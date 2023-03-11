/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations5.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/matrix_operations5.h"
#include "../inc/matrix_operations3.h"
#include "../inc/matrix_operations2.h"
#include "../inc/general_utils3.h"

double	**get_scaling_matrix_point(t_point3 *p)
{
	double	**m;

	if (!p)
		print_malloc_error_and_exit();
	m = create_identity_matrix(4);
	if (!m)
		return (NULL);
	m[0][0] = p->x;
	m[1][1] = p->y;
	m[2][2] = p->z;
	return (m);
}

void	multiply_matrices(double **m1, double **m2,
			double **multiplied_matrix)
{
	int	row;
	int	col;

	if (!m1 || !m2)
		return ;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			multiplied_matrix[row][col] = m1[row][0] * m2[0][col]
				+ m1[row][1] * m2[1][col]
				+ m1[row][2] * m2[2][col]
				+ m1[row][3] * m2[3][col];
			col++;
		}
		row++;
	}
	return ;
}

double	**get_translation_matrix_point(t_point3 *p)
{
	double	**m;

	if (!p)
		return (NULL);
	m = create_identity_matrix(4);
	m[0][3] = p->x;
	m[1][3] = p->y;
	m[2][3] = p->z;
	return (m);
}

double	determinant_nn(double **m, int n)
{
	int		j;
	double	determinant;

	if (!m)
	{
		return (0);
	}
	j = 0;
	determinant = 0;
	if (n == 2)
		determinant = m[0][0] * m[1][1] - m[0][1] * m[1][0];
	else
	{
		while (j < n)
		{
			determinant = determinant + m[0][j] * get_cofactor(m, 0, j, n);
			j++;
		}
	}
	return (determinant);
}
