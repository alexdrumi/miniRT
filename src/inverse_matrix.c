/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inverse_matrix.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/inverse_matrix.h"
#include "../inc/matrix_operations3.h"
#include "../inc/matrix_operations2.h"
#include "../inc/matrix_operations5.h"
#include "../inc/general_utils3.h"

t_bool	is_invertible(double **m, int n)
{
	double	determinant_res;

	determinant_res = determinant_nn(m, n);
	if (determinant_res != 0)
		return (true);
	else
		return (false);
}

void	loop_of_inverse_m(double **inverse_matrix,
			double determinant_of_orig_m, int n, double **m)
{
	int		row;
	int		col;
	double	cofactor;

	row = 0;
	col = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			cofactor = get_cofactor(m, row, col, n);
			inverse_matrix[col][row] = cofactor / determinant_of_orig_m;
			col++;
		}
		row++;
	}
}

double	**get_inverse_matrix(double **m, int n)
{
	double	determinant_of_orig_m;
	double	**inverse_matrix;

	if (is_invertible(m, n) == false)
	{
		write(1, "matrix is not invertible\n", 26);
		return (NULL);
	}
	inverse_matrix = init_array_matrix_n(n);
	if (!inverse_matrix)
		return (NULL);
	determinant_of_orig_m = determinant_nn(m, 4);
	if (!determinant_of_orig_m)
	{
		free_split_array((char **)inverse_matrix);
		return (NULL);
	}
	loop_of_inverse_m(inverse_matrix, determinant_of_orig_m, n, m);
	return (inverse_matrix);
}
