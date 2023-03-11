/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_at.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/color_at.h"
#include "../inc/intersections.h"
#include "../inc/shade_hit.h"
#include "../inc/prepare_computations_main.h"
#include "../inc/coloring_functions.h"

static void	free_intersections(t_intersections	*intersect_list)
{
	t_intersection	*prev;
	t_intersection	*current;

	current = intersect_list->root;
	while (current != NULL)
	{
		prev = current;
		current = current->next_intersection;
		free(prev);
	}
	free(intersect_list);
	return ;
}

t_intersection	*hit_object(t_intersections *list)
{
	t_intersection	*current;

	if (!list)
	{
		return (NULL);
	}
	current = list->root;
	while (current != NULL)
	{
		if (current->t_val > 0)
		{
			return (current);
		}
		current = current->next_intersection;
	}
	return (NULL);
}

t_color	*color_at(t_world *world, t_ray *ray, int remaining)
{
	t_intersections	*intersect_list;
	t_intersection	*hit_intersect;
	t_color			*final_col;
	//t_intersection	*current;

	intersect_list = intersect_world(world, ray);
	//current = NULL;
	if (!intersect_list)
		exit(1);
	hit_intersect = hit_object(intersect_list);
	if (hit_intersect)
		prepare_computations(hit_intersect, intersect_list, ray, world);
	//current = intersect_list->root;
	free_intersections(intersect_list);
	if (!hit_intersect)
		return (init_color(0, 0, 0));
	final_col = shade_hit(world, &world->comps, remaining);
	if (!final_col)
		exit(1);
	return (final_col);
}
