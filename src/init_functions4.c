/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_functions4.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lighting.h"
#include "../inc/init_functions2.h"
#include "../inc/init_functions4.h"
#include "../inc/matrix_operations3.h"
#include "../inc/vector_operations3.h"
#include "../inc/matrix_operations5.h"
#include "../inc/general_utils3.h"
#include "../inc/macros.h"
#include "../inc/destroy4.h"
#include "../inc/coloring_functions.h"
#include "../inc/vector_operations1.h"
#include "../inc/vector_operations2.h"
#include "../inc/point_operations1.h"
#include "../inc/point_operations1.h"
#include "../inc/inverse_matrix.h"

static t_bool	add_cam(t_minirt *minirt, t_camera *cam)
{
	if (minirt->cam_list == NULL)
	{
		minirt->cam_list = ft_lstnew(cam);
		if (!minirt->cam_list)
		{
			print_malloc_error_and_exit();
		}
	}
	else
	{
		ft_lst_add_back_double(&minirt->cam_list, ft_lstnew(cam));
	}
	(minirt->amount_of_cameras)++;
	minirt->bitflags |= (1 << 8);
	return (true);
}

static t_bool	check_forward_orient(t_vector3 *forward, t_vector3 *up)
{
	if (forward->x == 0 && forward->y == 0 && forward->z == 0)
	{
		write(1, ERROR_MSG, 6);
		exit (EXIT_ERROR);
	}
	else if (forward->x == 0 && (forward->y < 0 && forward->y >= -1)
		&& forward->z == 0)
	{
		set_vector(up, 0, 0, 1);
	}
	else if (forward->x == 0 && (forward->y <= 1 && forward->y > 0)
		&& forward->z == 0)
	{
		set_vector(up, 0, 0, -1);
	}
	normalize(up);
	return (true);
}

static void	assign_to_orientation_matrix(double **orientation, t_vector3 *left,
				t_vector3 *true_up, t_vector3 *forward)
{
	orientation[0][0] = left->x;
	orientation[0][1] = left->y;
	orientation[0][2] = left->z;
	orientation[1][0] = true_up->x;
	orientation[1][1] = true_up->y;
	orientation[1][2] = true_up->z;
	orientation[2][0] = -forward->x;
	orientation[2][1] = -forward->y;
	orientation[2][2] = -forward->z;
}

static double	**view_transformation(t_point3 *from, t_vector3 *forward,
					t_vector3 *up)
{
	double		**orientation;
	double		**translate_matrix;
	t_vector3	*left;
	t_vector3	*true_up;
	t_point3	translation;

	orientation = create_identity_matrix(4);
	if (check_forward_orient(forward, up) == false)
		exit (EXIT_ERROR);
	left = cross_product(forward, up);
	true_up = cross_product(left, forward);
	assign_to_orientation_matrix(orientation, left, true_up, forward);
	set_point(&translation, -from->x, -from->y, -from->z);
	translate_matrix = get_translation_matrix_point(&translation);
	multiply_matrices(orientation, translate_matrix, orientation);
	destroy_matrix(translate_matrix, 4);
	free(left);
	free(true_up);
	return (orientation);
}

t_bool	create_camera(double cam_view_coords[3],
			double cam_orient_coords[3], double fov, t_minirt *minirt)
{
	t_camera	*cam;
	t_point3	view_point;
	t_vector3	orient;
	t_vector3	up;

	cam = init_cam((double)minirt->res_width, (double)minirt->res_height, fov);
	if (!cam)
		print_malloc_error_and_exit();
	set_point(&view_point, cam_view_coords[0], cam_view_coords[1],
		cam_view_coords[2]);
	set_vector(&orient, cam_orient_coords[0], cam_orient_coords[1],
		cam_orient_coords[2]);
	set_vector(&up, 0, 1, 0);
	cam->transform_matrix = view_transformation(&view_point, &orient, &up);
	cam->inv_transf_matrix = get_inverse_matrix(cam->transform_matrix, 4);
	if (!cam->transform_matrix || !cam->inv_transf_matrix)
		print_malloc_error_and_exit();
	if ((minirt->bitflags & (1 << 0)) == 0)
		minirt->bitflags |= (1 << 4);
	return (add_cam(minirt, cam));
}
