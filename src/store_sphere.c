/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/store_sphere.h"
#include "../inc/matrix_operations3.h"
#include "../inc/object_normals.h"
#include "../inc/general_utils.h"
#include "../inc/intersect_sphere.h"
#include "../inc/init_functions2.h"
#include "../inc/matrix_operations4.h"
#include "../inc/matrix_operations5.h"
#include "../inc/destroy2.h"
#include "../inc/general_utils3.h"

static t_bool	sphere_data_to_attributes(char **data, t_minirt *minirt,
					t_ray_object *obj)
{
	t_bool	succeeded;

	succeeded = create_translate_matrix(data, minirt, 1,
			obj->translate_mtx);
	if (succeeded == false)
	{
		return (false);
	}
	succeeded = create_scale_matrix(data, minirt, 2,
			obj->scale_mtx);
	if (succeeded == false)
		return (false);
	succeeded = create_color(data, minirt, 3, &obj->mat.color);
	if (succeeded == false)
		return (false);
	multiply_matrices(obj->translate_mtx, obj->scale_mtx,
		obj->transform_mtx);
	succeeded = get_inv_matrix(obj->transform_mtx,
			obj->inv_transform_mtx, 4);
	if (succeeded == false)
		return (false);
	transpose_matrix(obj->inv_transform_mtx, 4,
		obj->transpose_inv_mtx);
	return (true);
}

t_bool	store_sphere(t_minirt *minirt, char *line, char **data)
{
	t_ray_object	*obj;
	t_list			*new_obj;

	data = ft_split_whitespace(line);
	if (!data)
		return (false);
	if (check_correct_nr_of_inputs(data, 4) == false)
		return (free_splitted_return_false((void **)data));
	obj = init_ray_object(1, intersect_sphere, sphere_normal_tremo);
	if (!obj)
		return (free_splitted_return_false((void **)data));
	new_obj = ft_lstnew(obj);
	if (sphere_data_to_attributes(data, minirt, obj) == false || !new_obj)
	{
		destroy_ray_obj(obj);
		return (free_splitted_return_false((void **)data));
	}
	ft_lstadd_back(&minirt->world.object_list, new_obj);
	(minirt->world.object_count)++;
	free_split_array(data);
	return (true);
}
