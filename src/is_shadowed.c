/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_operations1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/is_shadowed.h"
#include "../inc/intersections.h"
#include "../inc/point_operations1.h"
#include "../inc/vector_operations2.h"
#include "../inc/color_at.h"

static void	init_ray_local(t_point3 *origin, t_vector3 *direction,
				t_ray *res_ray)
{
	if (!origin || !direction || !res_ray)
		return ;
	res_ray->orig.x = origin->x;
	res_ray->orig.y = origin->y;
	res_ray->orig.z = origin->z;
	res_ray->dir.x = direction->x;
	res_ray->dir.y = direction->y;
	res_ray->dir.z = direction->z;
}

static void	free_intersect_list_l(t_intersection *prev, t_intersection *curr,
			t_intersections	*intersect_list)
{
	while (curr != NULL)
	{
		prev = curr;
		curr = curr->next_intersection;
		free(prev);
	}
	free(intersect_list);
}

void	is_shadowed(t_world *world, t_pointlight *current_light,
				t_point3 *point)
{
	t_intersections	*intersect_list;
	t_intersection	*curr;
	t_intersection	*prev;
	t_intersection	*hit;
	double			distance;

	point_min_point(&current_light->position, point,
		&world->shade_hit.shadowed.light_point_vec);
	distance = get_magnitude(&world->shade_hit.shadowed.light_point_vec);
	normalize(&world->shade_hit.shadowed.light_point_vec);
	init_ray_local(point, &world->shade_hit.shadowed.light_point_vec,
		&world->shade_hit.shadowed.shadow_ray);
	intersect_list = intersect_world(world,
			&world->shade_hit.shadowed.shadow_ray);
	hit = hit_object(intersect_list);
	if (hit != NULL && hit->t_val < distance
		&& hit->object_intersected->can_cast_shadows == 1)
		world->shade_hit.shadowed.is_shadowed = 1;
	else
		world->shade_hit.shadowed.is_shadowed = 0;
	curr = intersect_list->root;
	prev = NULL;
	free_intersect_list_l(prev, curr, intersect_list);
	return ;
}
