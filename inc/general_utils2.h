/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils2.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_UTILS2_H
# define GENERAL_UTILS2_H
# include "../inc/structs.h"

t_bool		check_components(char **components, double *return_values,
				t_minirt *minirt);
int			check_fatoi_error(double a, double b, double c);
void		set_color(t_color *color, double r, double g, double b);

#endif