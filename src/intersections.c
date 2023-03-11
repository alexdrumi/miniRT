/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersections.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/intersections.h"
#include "../inc/general_utils3.h"
#include "../inc/quick_sort.h"

static t_intersections	*init_list_of_intersections(void)
{
	t_intersections	*root;

	root = (t_intersections *)malloc(sizeof(t_intersections));
	if (!root)
		print_malloc_error_and_exit();
	root->intersect_count = 0;
	root->root = NULL;
	root->curr = NULL;
	return (root);
}

void	free_intersect_list(t_intersections *list)
{
	int				i;
	t_intersection	*current;
	//t_intersection	*tmp;

	current = list->root;
	i = 0;
	while (current != NULL && i < list->intersect_count)
	{
		//tmp = current->next_intersection;
		free(current);
		i++;
	}
}

void	add_to_intersect_list(t_intersections *list, t_intersection *object)
{
	//t_intersection	*tmp;
	//int				i;

	if (!list || !object)
		print_malloc_error_and_exit();
	//i = 0;
	//tmp = NULL;
	if (!object)
		return ;
	if (!list->root)
	{
		list->root = object;
		list->curr = object;
	}
	else
	{
		if (list)
		{
			while (list->curr->next_intersection != NULL)
				list->curr = list->curr->next_intersection;
		}
		list->curr->next_intersection = object;
		list->curr->next_intersection->next_intersection = NULL;
	}
	list->intersect_count++;
}

t_intersections	*intersect_world(t_world *world, t_ray *ray)
{
	t_intersections	*list;
	t_ray_object	*current;
	t_list			*current_obj_in_list;
	int				i;

	list = init_list_of_intersections();
	current_obj_in_list = world->object_list;
	i = 0;
	while (current_obj_in_list != NULL)
	{
		current = (t_ray_object *)current_obj_in_list->content;
		(current->INTERSECT_FUNCTION)(current, ray, (void *)list);
		current_obj_in_list = current_obj_in_list->next;
		i++;
	}
	quick_sort(&list->root);
	return (list);
}
