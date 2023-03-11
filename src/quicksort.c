/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/quick_sort.h"
#include "../inc/quicksort2.h"

static t_intersection	*get_tail(t_intersection *cur)
{
	while (cur != NULL && cur->next_intersection != NULL)
		cur = cur->next_intersection;
	return (cur);
}

static t_intersection	*quick_sort_recur(t_intersection *head,
								t_intersection *end)
{
	t_intersection	*pivot;
	t_intersection	*tmp;
	t_intersection	*new_end;
	t_intersection	*new_head;

	if (!head || head == end)
		return (head);
	new_head = NULL;
	new_end = NULL;
	pivot = partition_list(head, end, &new_head, &new_end);
	if (new_head != pivot)
	{
		tmp = new_head;
		while (tmp->next_intersection != pivot)
			tmp = tmp->next_intersection;
		tmp->next_intersection = NULL;
		new_head = quick_sort_recur(new_head, tmp);
		tmp = get_tail(new_head);
		tmp->next_intersection = pivot;
	}
	pivot->next_intersection
		= quick_sort_recur(pivot->next_intersection, new_end);
	return (new_head);
}

void	quick_sort(t_intersection **head_ref)
{
	if (!head_ref || !*head_ref)
		return ;
	(*head_ref) = quick_sort_recur(*head_ref, get_tail(*head_ref));
}
