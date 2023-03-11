/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../inc/mlx_functions.h"
#include "../inc/store_resolution.h"
#include "../inc/macros.h"

t_bool	init_mlx(t_minirt *minirt)
{
	minirt->mlx = mlx_init();
	if (!minirt->mlx)
	{
		return (false);
	}
	minirt->win = mlx_new_window(minirt->mlx, minirt->res_width,
			minirt->res_height, "miniRT");
	if (!minirt->mlx)
	{
		return (false);
	}
	mlx_hook(minirt->win, DESTROY_WITH_PRESSING_REDCROSS, 0L,
		exit_mlx, minirt);
	mlx_key_hook(minirt->win, keypress, minirt);
	return (true);
}
