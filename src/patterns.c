/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patterns.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/patterns.h"
#include "../inc/macros.h"
#include "../inc/inverse_matrix.h"
#include "../inc/vector_operations1.h"
#include "../inc/matrix_operations1.h"
#include <math.h>

static t_color	*pattern_at(t_pattern *pattern, t_point3 *p)
{
	t_point3	*point;
	double		res;

	point = multiply_matrix44_point(get_inverse_matrix(
				pattern->transformation_matrix, 4), p);
	if (!point)
		return (NULL);
	res = fmod(floor(point->x + EPSILON) + floor(point->y + EPSILON)
			+ floor(point->z + EPSILON), 2);
	if (res >= 1 || res < 0)
		return (pattern->b);
	else
		return (pattern->a);
}

static	t_point3	*world_to_object_space(t_ray_object *object,
			t_point3 *world_point)
{
	return (multiply_matrix44_point(
			object->inv_transform_mtx, world_point));
}

t_color	*pattern_at_object(t_pattern *pattern, t_ray_object *object,
			t_point3 *world_point)
{
	t_point3	*trans_point;

	trans_point = world_to_object_space(object, world_point);
	if (!trans_point)
		return (NULL);
	return (pattern_at(pattern, trans_point));
}
