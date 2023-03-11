/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_utils3.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_UTILS3_H
# define GENERAL_UTILS3_H
# include "../inc/structs.h"

t_bool	free_splitted_return_false(void **splitted);
void	free_split_array_void(void **splitted);
void	set_ray_origin(t_ray *ray, double x, double y, double z);
void	print_malloc_error_and_exit(void);
void	free_split_array(char **splitted);

#endif
