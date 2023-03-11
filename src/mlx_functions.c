/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_functions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mlx_functions.h"
#include "../minilibx/mlx.h"
#include "../inc/macros.h"

int	exit_mlx(t_minirt *minirt)
{
	(void)minirt;
	exit(0);
}

int	display(t_minirt *minirt, t_list *current_cam)
{
	t_camera	*cam;

	(void)minirt;
	(void)current_cam;
	cam = (t_camera *)minirt->cam_list->content;
	mlx_put_image_to_window(minirt->mlx, minirt->win, cam->image_ptr.img, 0, 0);
	return (0);
}

int	keypress(int keycode, t_minirt *minirt, t_list *current_cam)
{
	(void)minirt;
	(void)current_cam;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	return (0);
}

void	display_window(t_minirt *minirt)
{
	(void)minirt;
	mlx_loop_hook(minirt->mlx, display, minirt);
}
