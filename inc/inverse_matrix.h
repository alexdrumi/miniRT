/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inverse_matrix.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVERSE_MATRIX_H
# define INVERSE_MATRIX_H
# include "structs.h"

double		**get_inverse_matrix(double **m, int n);
t_bool		is_invertible(double **m, int n);

#endif