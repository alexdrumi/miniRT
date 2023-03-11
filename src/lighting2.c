/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lighting.h"
#include "../inc/lighting2.h"
#include "../inc/vector_operations2.h"
#include "../inc/is_shadowed.h"
#include "../inc/color_operations1.h"
#include "../inc/general_utils3.h"
#include "../inc/general_utils2.h"
#include "../inc/vector_operations1.h"
#include "../inc/point_operations1.h"
#include <math.h>

static void	hadamard_product(t_color *c1, t_color *c2, t_color *res)
{
	if (!c1 || !c2 || !res)
		print_malloc_error_and_exit();
	res->r = c1->r * c2->r;
	res->g = c1->g * c2->g;
	res->b = c1->b * c2->b;
	return ;
}

static void	get_light_col(t_world *world, t_comps *comps,
					t_lightcalcs *lights,
						t_pointlight *current_light)
{
	t_color	light_col_res;

	is_shadowed(world, current_light, &comps->over_p);
	if (world->shade_hit.shadowed.is_shadowed == -1)
		return ;
	light_col_res = lighting(comps, lights, current_light,
			world->shade_hit.shadowed.is_shadowed);
	set_color(&world->final_col.light_col,
		light_col_res.r, light_col_res.g, light_col_res.b);
}

static double	calculate(t_lightcalcs *lights, t_pointlight *light,
					t_comps *comps, double light_dot_normal)
{
	t_vector3	*neg_light_vector;
	double		reflect_dot_eye;
	double		spec_factor;

	scalar_color_mult_loc(&lights->effective_col,
		(light->diffuse * light_dot_normal), &lights->diffuse_col);
	neg_light_vector = scalar_vec_mult(&lights->light_vector, -1);
	get_reflect_vector(neg_light_vector,
		&comps->normal, &lights->reflect_vector);
	reflect_dot_eye = get_dot_prod(&lights->reflect_vector, &comps->eyev);
	free(neg_light_vector);
	if (reflect_dot_eye > 0)
	{
		spec_factor = pow(reflect_dot_eye, comps->obj->mat.shininess);
		scalar_color_mult_loc(&light->intensity,
			(comps->obj->mat.specular * spec_factor),
			&lights->specular_color);
	}
	return (reflect_dot_eye);
}

t_color	lighting(t_comps *comps, t_lightcalcs *lights,
			t_pointlight *light, int in_shadow)
{
	t_color		plus_spec;
	t_color		amb_plus_diff;
	t_color		*tmp;
	double		light_dot_normal;

	tmp = &comps->obj->mat.color;
	hadamard_product(tmp, &light->intensity, &lights->effective_col);
	hadamard_product(&lights->effective_col, &comps->ambient_col,
		&lights->ambient_col);
	point_min_point(&light->position, &comps->point, &lights->light_vector);
	normalize(&lights->light_vector);
	if (in_shadow == 1)
		return (lights->ambient_col);
	light_dot_normal = get_dot_prod(&lights->light_vector, &comps->normal);
	if (light_dot_normal > 0)
		calculate(lights, light, comps, light_dot_normal);
	add_color_local(&lights->ambient_col, &lights->diffuse_col, &amb_plus_diff);
	add_color_local(&amb_plus_diff, &lights->specular_color, &plus_spec);
	return (plus_spec);
}

t_color	*loop_all_lights(t_world *world, t_comps *comps,
			t_color *surface, t_lightcalcs *lights)
{
	t_pointlight	*current_light;
	t_list			*current_in_list;
	t_color			*surface_plus_light;
	int				i;

	current_in_list = world->light_list;
	i = 0;
	while (current_in_list != NULL && i < world->light_count)
	{
		current_light = (t_pointlight *)current_in_list->content;
		if (comps->obj->can_receive_shadows == 1)
		{	
			get_light_col(world, comps, lights, current_light);
			surface_plus_light = add_color(&world->final_col.light_col,
					surface);
			free(surface);
		}
		current_in_list = current_in_list->next;
		i++;
	}
	return (surface_plus_light);
}
