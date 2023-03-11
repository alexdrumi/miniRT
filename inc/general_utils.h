/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_UTILS_H
# define GENERAL_UTILS_H
# include "../inc/structs.h"
# include "../inc/general_utils2.h"

double	deg2rad(const double angle_in_degrees);
t_bool	check_correct_nr_of_inputs(char **data, int nr_of_expected_inputs);
t_list	*ft_lstlast(t_list *lst);
t_bool	data_to_point(char **data, double comps[3], t_minirt *minirt,
			int index);
t_bool	create_color(char **data, t_minirt *minirt,
			int index, t_color *assign_to);

#endif