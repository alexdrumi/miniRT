/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations5.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_OPERATIONS5_H
# define MATRIX_OPERATIONS5_H

# include "../inc/structs.h"

double	**get_scaling_matrix_point(t_point3 *p);
double	**get_translation_matrix_point(t_point3 *p);
void	multiply_matrices(double **m1, double **m2,
			double **multiplied_matrix);
double	determinant_nn(double **m, int n);

#endif