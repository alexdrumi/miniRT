/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prepare_computations.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/color_at.h"
#include "../inc/prepare_computations_utils.h"
#include "../inc/vector_operations2.h"
#include "../inc/init_functions3.h"
#include "../inc/set_comp_n_vals.h"
#include "../inc/intersect_square.h"
#include "../inc/general_utils.h"
#include "../inc/point_operations1.h"
#include "../inc/vector_operations1.h"
#include "../inc/init_functions5.h"
#include "../inc/macros.h"
#include <math.h>

static void	get_under_point_tremo(t_point3 *point,
				t_vector3 *normal, t_point3 *over_p)
{
	t_vector3	scaled_normal;
	t_vector3	over_p_vect;

	scalar_vec_mult_local(normal, EPSILON, &scaled_normal);
	point_min_vector(point, &scaled_normal, &over_p_vect);
	set_point(over_p, over_p_vect.x, over_p_vect.y, over_p_vect.z);
}

static void	get_over_point_tremo(t_point3 *point,
				t_vector3 *normal, t_point3 *over_p)
{
	t_vector3	scaled_normal;
	t_vector3	over_p_vect;

	scalar_vec_mult_local(normal, EPSILON, &scaled_normal);
	point_plus_vector(point, &scaled_normal, &over_p_vect);
	set_point(over_p, over_p_vect.x, over_p_vect.y, over_p_vect.z);
}

void	calc_refracted_vals(t_comps *comps)
{
	comps->n_ratio = comps->n1 / comps->n2;
	comps->cos_i = get_dot_prod(&comps->eyev, &comps->normal);
	comps->sin2_t = comps->n_ratio * comps->n_ratio
		* (1 - (comps->cos_i * comps->cos_i));
	comps->cos_t = sqrt(1 - comps->sin2_t);
}

void	calc_points(t_comps *comps)
{
	get_over_point_tremo(&comps->point, &comps->normal, &comps->over_p);
	get_under_point_tremo(&comps->point, &comps->normal, &comps->under_p);
}

void	calc_p_at_parameter(t_comps *comps, double t, t_ray *ray)
{
	set_ray_origin(&comps->comps_ray, ray->orig.x, ray->orig.y, ray->orig.z);
	scalar_vec_mult_local(&ray->dir, t, &comps->comps_ray.dir);
	set_p_at_parameter(&comps->comps_ray.orig, &comps->comps_ray.dir,
		&comps->point_at_parameter);
}
