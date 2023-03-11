/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/init_functions2.h"
#include "../inc/pixel_operations.h"
#include "../inc/general_utils.h"
#include "../inc/general_utils3.h"
#include "../inc/matrix_operations3.h"

t_pointlight	*init_point_light(t_point3 *pos, t_color *intensity)
{
	t_pointlight	*new_plight;

	new_plight = (t_pointlight *)malloc(sizeof(t_pointlight));
	if (!new_plight)
		print_malloc_error_and_exit();
	set_point(&new_plight->position, pos->x, pos->y, pos->z);
	set_color(&new_plight->intensity, intensity->r, intensity->g, intensity->b);
	new_plight->diffuse = 0;
	new_plight->next = NULL;
	return (new_plight);
}

void	init_mat(t_mat	*new_mat)
{
	set_color(&new_mat->color, 0, 0, 0);
	new_mat->reflective = 0.0;
	new_mat->ambient = 0;
	new_mat->specular = 0;
	new_mat->shininess = 0;
	new_mat->transparency = 0.0;
	new_mat->refract_index = 0;
	return ;
}

static void	set_attributes(t_ray_object	*new_ray_object,
	void (*intersect_function_ptr)(t_ray_object *, t_ray *, void *),
		void (*local_normal_function_ptr)(t_ray_object *,
			t_point3 *, void *, t_vector3 *))
{
	new_ray_object->INTERSECT_FUNCTION = intersect_function_ptr;
	new_ray_object->LOCAL_NORMAL_FUNCTION = local_normal_function_ptr;
	new_ray_object->id = 0;
	new_ray_object->radius = 0;
	new_ray_object->next = NULL;
	new_ray_object->closed = 1;
	new_ray_object->can_cast_shadows = 1;
	new_ray_object->can_receive_shadows = 1;
	new_ray_object->amount_of_children = 0;
}

t_ray_object	*
	init_ray_object(int type,
		void (*intersect_function_ptr)(t_ray_object *, t_ray *, void *),
			void (*local_normal_function_ptr)(t_ray_object *,
				t_point3 *, void *, t_vector3 *))
{
	t_ray_object	*new_obj;

	(void)type;
	new_obj = (t_ray_object *)malloc(sizeof(t_ray_object));
	if (!new_obj)
		print_malloc_error_and_exit();
	new_obj->object = NULL;
	new_obj->transform_mtx = create_identity_matrix(4);
	new_obj->inv_transform_mtx = create_identity_matrix(4);
	new_obj->transpose_inv_mtx = create_identity_matrix(4);
	new_obj->translate_mtx = create_identity_matrix(4);
	new_obj->rotate_mtx = create_identity_matrix(4);
	new_obj->scale_mtx = create_identity_matrix(4);
	set_color(&new_obj->color, 0, 0, 0);
	set_point(&new_obj->local_ray.orig, 0, 0, 0);
	set_vector(&new_obj->local_ray.dir, 0, 0, 0);
	set_vector(&new_obj->normal, 0, 0, 0);
	init_mat(&new_obj->mat);
	set_attributes(new_obj, intersect_function_ptr, local_normal_function_ptr);
	return (new_obj);
}
