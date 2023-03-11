/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/quick_sort.h"

static	void	if_statement(t_intersection **cur, t_intersection **pivot,
					t_intersection **prev)
{
	(void)pivot;
	*prev = *cur;
	*cur = (*cur)->next_intersection;
}

static	void	else_statement(t_intersection **cur, t_intersection **tmp,
					t_intersection **tail, t_intersection **prev)
{
	if (*prev != NULL)
		(*prev)->next_intersection = (*cur)->next_intersection;
	*tmp = (*cur)->next_intersection;
	(*cur)->next_intersection = NULL;
	(*tail)->next_intersection = *cur;
	*tail = *cur;
	*cur = *tmp;
}

t_intersection	*partition_list(t_intersection *head,
		t_intersection *end,
		t_intersection **new_head,
		t_intersection **new_end)
{
	t_intersection	*pivot;
	t_intersection	*prev;
	t_intersection	*cur;
	t_intersection	*tail;
	t_intersection	*tmp;

	pivot = end;
	cur = head;
	tail = pivot;
	prev = NULL;
	while (cur != pivot)
	{
		if (cur->t_val < pivot->t_val)
		{
			if ((*new_head) == NULL)
				(*new_head) = cur;
			if_statement(&cur, &pivot, &prev);
		}
		else
			else_statement(&cur, &tmp, &tail, &prev);
	}
	if ((*new_head) == NULL)
		(*new_head) = pivot;
	(*new_end) = tail;
	return (pivot);
}
