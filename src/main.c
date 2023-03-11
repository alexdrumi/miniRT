/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/10/27 14:35:10 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../inc/macros.h"
#include "../inc/parse1.h"
#include "../inc/parse_utils.h"
#include "../inc/mlx_functions.h"
#include "../inc/init_functions3.h"
#include "../inc/store_resolution.h"
#include "../inc/render.h"

int	main(int argc, char *argv[])
{
	t_minirt	*minirt;

	if (argc != 2)
	{
		write(1, ERROR_MSG, 6);
		exit (1);
	}
	minirt = init_minirt();
	if (!minirt)
	{
		exit (EXIT_ERROR);
	}
	if (parse_rt_file(argv[1], minirt) == false)
	{
		write(1, ERROR_MSG, 6);
		exit(EXIT_ERROR);
	}
	render_all_cameras(minirt);
	display_window(minirt);
	mlx_key_hook(minirt->win, keypress, minirt);
	mlx_loop(minirt->mlx);
	exit(EXIT_SUCCESS);
}
