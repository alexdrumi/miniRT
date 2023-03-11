/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions1.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_FUNCTIONS3_H
# define INIT_FUNCTIONS3_H
# include "../inc/structs.h"

t_minirt	*init_minirt(void);
void		init_world(t_minirt *minirt);
void		init_comps(t_world *world);

#endif