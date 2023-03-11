/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prepare_computations_main.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/prepare_computations_main.h"
#include "../inc/prepare_computations_utils.h"
#include "../inc/vector_operations2.h"
#include "../inc/set_comp_n_vals.h"
#include "../inc/general_utils.h"
#include "../inc/color_operations1.h"
#include "../inc/vector_operations1.h"
#include "../inc/lighting.h"
#include "../inc/normals.h"

static void	set_comps_attributes(t_world *world, t_comps	*comps,
				t_intersection *intersect)
{		
	scalar_color_mult_loc(&world->ambient_col,
		world->ambient_factor, &comps->ambient_col);
	comps->obj = intersect->object_intersected;
	set_color(&comps->obj->color, intersect->object_intersected->mat.color.r,
		intersect->object_intersected->mat.color.g,
		intersect->object_intersected->mat.color.b);
	comps->t = intersect->t_val;
	comps->point = comps->point_at_parameter;
}

void	prepare_computations(t_intersection *intersect,
			t_intersections *intersect_list, t_ray *ray, t_world *world)
{
	calc_p_at_parameter(&world->comps, intersect->t_val, ray);
	scalar_vec_mult_local(&ray->dir, -1, &world->comps.eyev);
	normalize(&world->comps.eyev);
	alt_normal_at(intersect->object_intersected,
		&world->comps.point_at_parameter, intersect, &world->comps);
	set_comps_attributes(world, &world->comps, intersect);
	if (get_dot_prod(&world->comps.eyev, &world->comps.normal) < 0)
	{
		world->comps.is_inside = 1;
		scalar_vec_mult_local(&world->comps.normal, -1, &world->comps.normal);
	}
	set_comp_n_vals(world, intersect, intersect_list, &world->comps);
	get_reflect_vector(&ray->dir, &world->comps.normal, &world->comps.reflectv);
	calc_points(&world->comps);
	calc_refracted_vals(&world->comps);
}
