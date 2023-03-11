/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATIONS1_H
# define VECTOR_OPERATIONS1_H
# include "structs.h"

void		set_vector(t_vector3 *vector, double x, double y, double z);
void		scalar_vec_mult_local(t_vector3 *v, double t, t_vector3 *res);
void		vector_min_vector(t_vector3 *v1, t_vector3 *v2, t_vector3 *res);
void		vector_plus_vector(t_vector3 *v1, t_vector3 *v2, t_vector3 *res);
t_vector3	*scalar_vec_mult(t_vector3 *v1, double scalar);

#endif
