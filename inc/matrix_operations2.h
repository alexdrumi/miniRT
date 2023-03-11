/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations2.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_OPERATIONS2_H
# define MATRIX_OPERATIONS2_H
# include "structs.h"

double		get_cofactor(double **m, int row, int col, int n);
double		get_minor(double **m, int row, int col, int n);

#endif
