/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions1.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/general_utils3.h"
#include "../inc/vector_operations1.h"
#include "../inc/point_operations1.h"

t_intersection	*init_intersect(t_ray_object *object,
	double t_val, double u, double v)
{
	t_intersection	*node;

	node = (t_intersection *)malloc(sizeof(t_intersection));
	if (!node)
		print_malloc_error_and_exit();
	node->t_val = t_val;
	node->u = u;
	node->v = v;
	node->object_intersected = object;
	node->next_intersection = NULL;
	return (node);
}

t_point3	*init_point(double x, double y, double z)
{
	t_point3	*new_point;

	new_point = (t_point3 *)malloc(sizeof(t_point3));
	if (!new_point)
		print_malloc_error_and_exit();
	new_point->x = x;
	new_point->y = y;
	new_point->z = z;
	new_point->w = 1;
	return (new_point);
}

t_vector3	*init_vector(double x, double y, double z)
{
	t_vector3	*new_vector;

	new_vector = (t_vector3 *)malloc(sizeof(t_vector3));
	if (!new_vector)
		print_malloc_error_and_exit();
	new_vector->x = x;
	new_vector->y = y;
	new_vector->z = z;
	new_vector->w = 0;
	return (new_vector);
}

t_ray	*init_ray(t_point3 *origin, t_vector3 *direction)
{
	t_ray	*new_ray;

	if (!origin || !direction)
		print_malloc_error_and_exit();
	new_ray = (t_ray *)malloc(sizeof(t_ray));
	if (!new_ray)
		print_malloc_error_and_exit();
	set_point(&new_ray->orig, origin->x, origin->y, origin->z);
	set_vector(&new_ray->dir, direction->x, direction->y, direction->z);
	set_point(&new_ray->point_at_parameter, 0, 0, 0);
	return (new_ray);
}
