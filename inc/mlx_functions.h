/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_functions.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_FUNCTIONS_H
# define MLX_FUNCTIONS_H

# include "../inc/structs.h"

int		display(t_minirt *minirt, t_list *current_cam);
int		keypress(int keycode, t_minirt *minirt, t_list *current_cam);
void	display_window(t_minirt *minirt);
int		exit_mlx(t_minirt *minirt);

#endif