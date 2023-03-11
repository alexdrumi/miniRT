/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations1.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/matrix_operations1.h"
#include "../inc/init_functions1.h"

t_point3	*multiply_matrix44_point(double **m1, t_point3 *point)
{
	t_point3	*multiplied_point_w_matrix;

	multiplied_point_w_matrix = init_point(0, 0, 0);
	if (!multiplied_point_w_matrix || !point || !m1)
		return (NULL);
	multiplied_point_w_matrix->x = m1[0][0] * point->x
		+ m1[0][1] * point->y
		+ m1[0][2] * point->z
		+ m1[0][3] * point->w;
	multiplied_point_w_matrix->y = m1[1][0] * point->x
		+ m1[1][1] * point->y
		+ m1[1][2] * point->z
		+ m1[1][3] * point->w;
	multiplied_point_w_matrix->z = m1[2][0] * point->x
		+ m1[2][1] * point->y
		+ m1[2][2] * point->z
		+ m1[2][3] * point->w;
	multiplied_point_w_matrix->w = m1[3][0] * point->x
		+ m1[3][1] * point->y
		+ m1[3][2] * point->z
		+ m1[3][3] * point->w;
	return (multiplied_point_w_matrix);
}

void	multiply_matrix44_point_to_point(double **m1, t_point3 *point,
		t_point3 *multiplied_point_w_matrix)
{
	if (!multiplied_point_w_matrix || !point || !m1)
		return ;
	multiplied_point_w_matrix->x = m1[0][0] * point->x
		+ m1[0][1] * point->y
		+ m1[0][2] * point->z
		+ m1[0][3] * point->w;
	multiplied_point_w_matrix->y = m1[1][0] * point->x
		+ m1[1][1] * point->y
		+ m1[1][2] * point->z
		+ m1[1][3] * point->w;
	multiplied_point_w_matrix->z = m1[2][0] * point->x
		+ m1[2][1] * point->y
		+ m1[2][2] * point->z
		+ m1[2][3] * point->w;
	multiplied_point_w_matrix->w = m1[3][0] * point->x
		+ m1[3][1] * point->y
		+ m1[3][2] * point->z
		+ m1[3][3] * point->w;
}

void	multiply_matrix44_vector_to_vector(double **m1, t_vector3 *vector,
		t_vector3 *multiplied_vector_w_matrix)
{
	if (!vector || !multiplied_vector_w_matrix || !m1)
		return ;
	multiplied_vector_w_matrix->x = m1[0][0] * vector->x
		+ m1[0][1] * vector->y
		+ m1[0][2] * vector->z
		+ m1[0][3] * vector->w;
	multiplied_vector_w_matrix->y = m1[1][0] * vector->x
		+ m1[1][1] * vector->y
		+ m1[1][2] * vector->z
		+ m1[1][3] * vector->w;
	multiplied_vector_w_matrix->z = m1[2][0] * vector->x
		+ m1[2][1] * vector->y
		+ m1[2][2] * vector->z
		+ m1[2][3] * vector->w;
	multiplied_vector_w_matrix->w = m1[3][0] * vector->x
		+ m1[3][1] * vector->y
		+ m1[3][2] * vector->z
		+ m1[3][3] * vector->w;
}

void	get_scaling_matrix(double **m, double x, double y, double z)
{
	if (!m)
		return ;
	m[0][0] = x;
	m[1][1] = y;
	m[2][2] = z;
}

void	get_translation_matrix(double **m, double x, double y, double z)
{
	if (!m)
		return ;
	m[0][3] = x;
	m[1][3] = y;
	m[2][3] = z;
}
