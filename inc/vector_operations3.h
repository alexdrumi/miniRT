/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations3.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATIONS3_H
# define VECTOR_OPERATIONS3_H

# include "../inc/structs.h"

t_vector3	*multiply_matrix44_vector(double **m1, t_vector3 *vector);
t_vector3	*cross_product(t_vector3 *v1, t_vector3 *v2);

#endif