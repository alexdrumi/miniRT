/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_operations1.h.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_OPERATIONS1_H
# define COLOR_OPERATIONS1_H
# include "structs.h"

void	scalar_color_mult_loc(t_color *c1, double scalar,
			t_color *res);
t_color	*scalar_color_multicipation(t_color *c1, double scalar);
t_color	*add_color(t_color *c1, t_color *c2);
void	add_color_local(t_color *c1, t_color *c2, t_color *res);
void	color_mult_local(t_color *c1, t_color *c2, t_color *res);

#endif
