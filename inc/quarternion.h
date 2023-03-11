/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quarternion.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUARTERNION_H
# define QUARTERNION_H
# include "../inc/structs.h"

void	create_quarternion1(t_vector3 *orient, t_minirt *minirt,
			double **qmatrix, t_ray_object *obj);

#endif