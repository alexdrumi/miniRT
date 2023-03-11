/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions3.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/prepare_computations_main.h"
#include "../inc/general_utils3.h"
#include "../inc/set_comp_n_vals.h"
#include "../inc/init_functions5.h"
#include "../inc/point_operations1.h"
#include "../inc/vector_operations1.h"
#include "../inc/store_resolution.h"
#include "../inc/general_utils2.h"

static void	init_shade_hit(t_world	*world)
{
	init_is_shadowed(&world->shade_hit);
}

static void	init_color_res(t_world	*world)
{
	set_color(&world->final_col.surface, 0, 0, 0);
	set_color(&world->final_col.reflected_color, 0, 0, 0);
	set_color(&world->final_col.refracted_color, 0, 0, 0);
	set_color(&world->final_col.reflected_times_reflectance, 0, 0, 0);
	set_color(&world->final_col.schlick_color, 0, 0, 0);
	set_color(&world->final_col.light_col, 0, 0, 0);
	set_color(&world->final_col.final_col, 0, 0, 0);
	return ;
}

void	init_world(t_minirt *minirt)
{
	init_shade_hit(&minirt->world);
	init_comps(&minirt->world);
	init_color_res(&minirt->world);
	set_point(&minirt->world.ray_through_pixel.orig, 0, 0, 0);
	set_vector(&minirt->world.ray_through_pixel.dir, 0, 0, 0);
	minirt->world.light_list = NULL;
	minirt->world.object_list = NULL;
	minirt->world.object_count = 0;
	minirt->world.light_count = 0;
	return ;
}

t_minirt	*init_minirt(void)
{
	t_minirt	*new_minirt;

	new_minirt = (t_minirt *)malloc(sizeof(t_minirt));
	init_world(new_minirt);
	if (!new_minirt)
		print_malloc_error_and_exit();
	new_minirt->mlx = NULL;
	new_minirt->win = NULL;
	new_minirt->amount_of_cameras = 0;
	new_minirt->cam_list = NULL;
	new_minirt->res_width = 640;
	new_minirt->res_height = 480;
	new_minirt->field_of_view = 0;
	new_minirt->current_cam = NULL;
	new_minirt->ambient = 0;
	new_minirt->diffuse = 0;
	new_minirt->specular = 0;
	new_minirt->shininess = 0;
	new_minirt->bitflags = 0;
	set_color(&new_minirt->ambient_col, 0, 0, 0);
	if (init_mlx(new_minirt) == false)
		return (NULL);
	return (new_minirt);
}
