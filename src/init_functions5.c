/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions5.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pixel_operations.h"
#include "../inc/general_utils.h"
#include "../inc/general_utils3.h"
#include <math.h>

static void	set_comps_attributes(t_comps	*new_computation)
{
	new_computation->is_inside = 0;
	new_computation->n1 = 1;
	new_computation->n2 = 1;
	new_computation->n_ratio = 0;
	new_computation->cos_i = 0;
	new_computation->sin2_t = 0;
	new_computation->cos_t = 0;
	return ;
}

void	init_comps(t_world *world)
{
	set_point(&world->comps.comps_ray.orig, 0, 0, 0);
	set_vector(&world->comps.comps_ray.dir, 0, 0, 0);
	set_point(&world->comps.point, 0, 0, 0);
	set_point(&world->comps.point_at_parameter, 0, 0, 0);
	set_point(&world->comps.point, 0, 0, 0);
	set_point(&world->comps.over_p, 0, 0, 0);
	set_point(&world->comps.under_p, 0, 0, 0);
	set_vector(&world->comps.eyev, 0, 0, 0);
	set_vector(&world->comps.normal, 0, 0, 0);
	set_vector(&world->comps.reflectv, 0, 0, 0);
	set_vector(&world->comps.local_normal, 0, 0, 0);
	set_point(&world->comps.local_point, 0, 0, 0);
	set_comps_attributes(&world->comps);
	world->comps.obj = NULL;
	return ;
}

t_camera	*init_cam(double hsize, double vsize, double horizontal_fov)
{
	t_camera	*new_camera;

	new_camera = (t_camera *)malloc(sizeof(t_camera));
	if (!new_camera)
		print_malloc_error_and_exit();
	new_camera->h_size = hsize;
	new_camera->v_size = vsize;
	new_camera->aspect_ratio = hsize / vsize;
	new_camera->fov = deg2rad(horizontal_fov);
	new_camera->half_fov = tan(new_camera->fov / 2);
	new_camera->transform_matrix = NULL;
	new_camera->inv_transf_matrix = NULL;
	set_pixel_size(new_camera);
	set_vector(&new_camera->orientation, 0, 0, 0);
	set_point(&new_camera->camera_coord, 0, 0, 0);
	return (new_camera);
}

void	init_is_shadowed(t_shade_hit	*new_shade_hit)
{
	set_vector(&new_shade_hit->shadowed.light_point_vec, 0, 0, 0);
	set_point(&new_shade_hit->shadowed.shadow_ray.orig, 0, 0, 0);
	set_vector(&new_shade_hit->shadowed.shadow_ray.dir, 0, 0, 0);
	new_shade_hit->shadowed.is_shadowed = 0;
	return ;
}
