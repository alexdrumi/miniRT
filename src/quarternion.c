/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quarternion.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/object_normals.h"
#include "../inc/vector_operations1.h"
#include "../inc/vector_operations2.h"
#include "../inc/macros.h"
#include <math.h>

static void	set_default_orient_according_to_new_orient(t_ray_object *obj,
				t_vector3 *orient, t_vector3 *default_orient, t_minirt *minirt)
{
	(void)minirt;
	if (obj->LOCAL_NORMAL_FUNCTION == square_normal_tremo)
	{
		if (orient->y == 0 && orient->x < 0 && orient->z < 0)
		{
			default_orient->x = 0;
			default_orient->y = -1;
			default_orient->z = 0;
		}
	}
}

static void	normalize_quarternion(t_vector3 *quat)
{
	double		magn;

	magn = sqrt(pow(quat->w, 2) + pow(quat->x, 2)
			+ pow(quat->y, 2) + pow(quat->z, 2));
	quat->w = quat->w / magn;
	quat->x = quat->x / magn;
	quat->y = quat->y / magn;
	quat->z = quat->z / magn;
}

static void	quarternion_to_matrix(double **qmatrix, t_vector3 *quart)
{
		qmatrix[0][0] = 1 - 2 * quart->y * quart->y - 2 * quart->z * quart->z;
		qmatrix[0][1] = 2 * quart->x * quart->y - 2 * quart->z * quart->w;
		qmatrix[0][2] = 2 * quart->x * quart->z + 2 * quart->y * quart->w;
		qmatrix[1][0] = 2 * quart->x * quart->y + 2 * quart->z * quart->w;
		qmatrix[1][1] = 1 - 2 * quart->x * quart->x - 2 * quart->z * quart->z;
		qmatrix[1][2] = 2 * quart->y * quart->z - 2 * quart->x * quart->w;
		qmatrix[2][0] = 2 * quart->x * quart->z - 2 * quart->y * quart->w;
		qmatrix[2][1] = 2 * quart->y * quart->z + 2 * quart->x * quart->w;
		qmatrix[2][2] = 1 - 2 * quart->x * quart->x - 2 * quart->y * quart->y;
}

void	create_quarternion1(t_vector3 *orient, t_minirt *minirt,
			double **qmatrix, t_ray_object *obj)
{
	t_vector3	m;
	t_vector3	quarternion;
	double		norm_u_norm_v;
	double		real_part;

	set_vector(&m, 0, 1, 0);
	if (orient->y < 0)
		m.y = -1;
	set_default_orient_according_to_new_orient(obj, orient, &m, minirt);
	norm_u_norm_v = sqrt(get_dot_prod(&m, &m) * get_dot_prod(orient, orient));
	real_part = norm_u_norm_v + get_dot_prod(orient, &m);
	set_vector(&quarternion, 0, 0, 0);
	if (real_part < EPSILON * norm_u_norm_v)
	{
		real_part = 0.0;
		if (fabs(m.x) > fabs(m.z))
			set_vector(&quarternion, m.y, m.x, 0);
		else
			set_vector(&quarternion, 0, -m.z, m.y);
	}
	else
		cross_product_l(orient, &m, &quarternion);
	quarternion.w = real_part;
	normalize_quarternion(&quarternion);
	quarternion_to_matrix(qmatrix, &quarternion);
}
