/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations3.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector_operations3.h"
#include "../inc/init_functions1.h"
#include "../inc/general_utils3.h"

t_vector3	*cross_product(t_vector3 *v1, t_vector3 *v2)
{
	double		i;
	double		j;
	double		k;
	t_vector3	*new_cross_product_vec;

	if (!v1 || !v2)
		print_malloc_error_and_exit();
	i = (v1->y * v2->z) - (v1->z * v2->y);
	j = (v1->z * v2->x) - (v1->x * v2->z);
	k = (v1->x * v2->y) - (v1->y * v2->x);
	new_cross_product_vec = init_vector(i, j, k);
	if (!new_cross_product_vec)
		print_malloc_error_and_exit();
	return (new_cross_product_vec);
}

t_vector3	*multiply_matrix44_vector(double **m1, t_vector3 *vector)
{
	t_vector3	*multiplied_vector_w_matrix;

	multiplied_vector_w_matrix = init_vector(0, 0, 0);
	if (!multiplied_vector_w_matrix)
		print_malloc_error_and_exit();
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
	return (multiplied_vector_w_matrix);
}
