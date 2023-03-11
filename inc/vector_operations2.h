/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations2.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATIONS2_H
# define VECTOR_OPERATIONS2_H
# include "structs.h"

void		normalize(t_vector3 *v1);
double		get_dot_prod(t_vector3 *v1, t_vector3 *v2);
double		get_magnitude(t_vector3 *v1);
void		cross_product_l(t_vector3 *v1, t_vector3 *v2,
				t_vector3 *res);

#endif
