/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_cylinder.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/init_functions2.h"
#include "../inc/general_utils.h"
#include "../inc/object_normals.h"
#include "../inc/matrix_operations1.h"
#include "../inc/matrix_operations3.h"
#include "../inc/intersect_cylinder.h"
#include "../inc/ft_fatoi.h"
#include "../inc/matrix_operations4.h"
#include "../inc/matrix_operations5.h"
#include "../inc/destroy2.h"
#include "../inc/general_utils3.h"

t_bool	get_geometry_data(char **data, t_ray_object *obj,
		int index, double *geom_attribute)
{
	double	value;

	(void)obj;
	value = ft_fatoi(data[index]);
	if (!value || check_fatoi_error(value, 2, 2) || value < EPSILON * 2)
		return (false);
	*geom_attribute = value;
	return (true);
}

static t_bool	cylinder_data_to_attributes(char **data, t_minirt *minirt,
				t_ray_object *obj)
{
	if (create_translate_matrix(data, minirt, 1,
			obj->translate_mtx) == false
		|| create_rotate_matrix(data, minirt, 2, obj) == false)
		return (false);
	if (get_geometry_data(data, obj, 3, &obj->radius) == false)
		return (false);
	obj->radius = obj->radius / 2;
	if (get_geometry_data(data, obj, 4, &obj->maximum) == false)
		return (false);
	obj->maximum = obj->maximum / 2;
	obj->minimum = -(obj->maximum);
	get_scaling_matrix(obj->scale_mtx, obj->radius, 1, obj->radius);
	if (create_color(data, minirt, 5, &obj->mat.color) == false)
		return (false);
	multiply_matrices(obj->translate_mtx, obj->rotate_mtx,
		obj->transpose_inv_mtx);
	multiply_matrices(obj->transpose_inv_mtx, obj->scale_mtx,
		obj->transform_mtx);
	if (get_inv_matrix(obj->transform_mtx,
			obj->inv_transform_mtx, 4) == false)
		return (false);
	transpose_matrix(obj->inv_transform_mtx, 4, obj->transpose_inv_mtx);
	return (true);
}

t_bool	store_cylinder(t_minirt *minirt, char *line, char **data)
{
	t_ray_object	*obj;
	t_list			*new_obj;

	data = ft_split_whitespace(line);
	if (!data)
		return (false);
	if (check_correct_nr_of_inputs(data, 6) == false)
		return (free_splitted_return_false((void **)data));
	obj = init_ray_object(2, intersect_cylinder, cylinder_normal_tremo);
	if (!obj)
		return (free_splitted_return_false((void **)data));
	new_obj = ft_lstnew(obj);
	if (cylinder_data_to_attributes(data, minirt, obj) == false || !new_obj)
	{
		destroy_ray_obj(obj);
		return (free_splitted_return_false((void **)data));
	}
	ft_lstadd_back(&minirt->world.object_list, new_obj);
	minirt->world.object_count++;
	free_split_array(data);
	return (true);
}
