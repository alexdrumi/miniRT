/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H
# include "../inc/structs.h"

t_bool	data_to_vector(char **data, double comps[3],
			t_minirt *minirt, int index);
int		create_trgb(int t, int r, int g, int b);
t_bool	is_line_empty(char *line);
t_bool	is_whitespace(char c);

#endif