/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/matrix_operations2.h"
#include "../inc/matrix_operations3.h"
#include "../inc/matrix_operations5.h"
#include "../inc/general_utils3.h"
#include "../inc/destroy4.h"

static void	assign_to_submatrix_loop_vals(int *row_col, int *i, int flag)
{
	if (flag == 0)
	{
		*i = 0;
		*row_col = 0;
		*(row_col + 1) = 0;
	}
	else
	{
		(*row_col)++;
		*(row_col + 1) = 0;
	}
}

static	void	submatrix_loop(double	**return_matrix,
					double **matrix, int indexes[2], int n)
{
	int		j;
	int		i;
	int		row_col[2];
	double	*input_ptr;

	assign_to_submatrix_loop_vals(row_col, &i, 0);
	while (i < n)
	{
		j = 0;
		input_ptr = *(matrix + i);
		while (j < n)
		{
			if (i != indexes[0] && j != indexes[1])
			{
				return_matrix[row_col[0]][row_col[1]] = *input_ptr;
				row_col[1]++;
				if (row_col[1] == n - 1)
					assign_to_submatrix_loop_vals(row_col, &i, 1);
			}
			input_ptr++;
			j++;
		}
		i++;
	}
}

double	**get_submatrix(double **matrix, int row, int col, int n)
{
	double	**return_matrix;
	int		indexes[2];

	return_matrix = init_array_matrix_n(n - 1);
	if (!return_matrix)
		return (NULL);
	indexes[0] = row;
	indexes[1] = col;
	submatrix_loop(return_matrix, matrix, indexes, n);
	return (return_matrix);
}

double	get_cofactor(double **m, int row, int col, int n)
{
	double	minor_at_row_col;

	minor_at_row_col = get_minor(m, row, col, n);
	if (!minor_at_row_col)
		return (0);
	if (((row + col) % 2) == 1)
	{
		if (minor_at_row_col != 0)
			minor_at_row_col *= -1.0;
	}
	return (minor_at_row_col);
}

double	get_minor(double **m, int row, int col, int n)
{
	double	**submatrix_of_m_at_row_col;
	double	determinant;
	double	minor_res;

	submatrix_of_m_at_row_col = get_submatrix(m, row, col, n);
	determinant = determinant_nn(submatrix_of_m_at_row_col, n - 1);
	destroy_matrix(submatrix_of_m_at_row_col, n - 1);
	if (!determinant)
		return (0);
	minor_res = determinant;
	return (minor_res);
}
