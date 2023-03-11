/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations3.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/matrix_operations1.h"
#include "../inc/matrix_operations2.h"
#include "../inc/matrix_operations3.h"
#include "../inc/matrix_operations5.h"
#include "../inc/general_utils.h"
#include "../inc/general_utils3.h"
#include "../inc/inverse_matrix.h"
#include "../inc/point_operations1.h"

double	**init_array_matrix_n(int n)
{
	double	**array;
	int		i;
	int		j;

	i = 0;
	array = (double **)malloc(n * sizeof(double *));
	if (!array)
		print_malloc_error_and_exit();
	while (i < n)
	{
		array[i] = (double *)malloc(n * sizeof(double));
		if (!array)
			print_malloc_error_and_exit();
		j = 0;
		while (j < n)
		{	
			array[i][j] = 0;
			j++;
		}
		i++;
	}
	return (array);
}

double	**create_identity_matrix(int n)
{
	int		i;
	int		j;
	double	**identity;

	identity = init_array_matrix_n(n);
	if (!identity)
		print_malloc_error_and_exit();
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{	
			if (j == i)
				identity[i][j] = 1;
			j++;
		}
		i++;
	}
	return (identity);
}

void	transpose_matrix(double **m1, int n,
			double **transposed_matrix)
{
	int		row;
	int		col;

	if (!transposed_matrix)
		return ;
	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			transposed_matrix[row][col] = m1[col][row];
			col++;
		}
		row++;
	}
	return ;
}

t_bool	create_translate_matrix(char **data, t_minirt *minirt,
			int index, double **matrix)
{
	double		orig_comps[3];
	t_bool		succeeded;
	t_point3	t_point;

	succeeded = data_to_point(data, orig_comps, minirt, index);
	if (succeeded == false)
		return (false);
	if (orig_comps[0] == 0 && orig_comps[1] == 0 && orig_comps[2] == 0)
		return (true);
	set_point(&t_point, orig_comps[0], orig_comps[1], orig_comps[2]);
	get_translation_matrix(matrix, t_point.x, t_point.y, t_point.z);
	return (true);
}

/*
 write(1, "matrix is not invertible, exit\n", 32);
*/
t_bool	get_inv_matrix(double **m, double **inverse_matrix, int n)
{
	int		row;
	int		col;
	double	cofactor;
	double	determinant_of_orig_matrix;

	if (is_invertible(m, n) == 0)
		return (false);
	row = 0;
	determinant_of_orig_matrix = determinant_nn(m, 4);
	if (!determinant_of_orig_matrix)
		return (false);
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			cofactor = get_cofactor(m, row, col, n);
			inverse_matrix[col][row] = cofactor / determinant_of_orig_matrix;
			col++;
		}
		row++;
	}
	return (true);
}
