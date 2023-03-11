/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations3.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_OPERATIONS3_H
# define MATRIX_OPERATIONS3_H
# include "../inc/structs.h"

double	**init_array_matrix_n(int n);
double	**create_identity_matrix(int n);
void	transpose_matrix(double **m1, int n,
			double **transposed_matrix);
t_bool	create_translate_matrix(char **data, t_minirt *minirt,
			int index, double **matrix);
t_bool	get_inv_matrix(double **m,
			double **inverse_matrix, int n);

#endif