/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations4.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/object_normals.h"
#include "../inc/quarternion.h"
#include "../inc/parse_utils.h"
#include "../inc/ft_fatoi.h"
#include "../inc/point_operations1.h"
#include "../inc/matrix_operations1.h"
#include "../inc/general_utils2.h"

static void	negate_coords(double orient_comps[3], t_minirt *minirt)
{
	(void)minirt;
	orient_comps[2] = orient_comps[2] * -1;
	orient_comps[0] = orient_comps[0] * -1;
}

static void	set_orientation(double orient_comps[3], t_vector3 *orientation)
{
	orientation->x = orient_comps[0];
	orientation->y = orient_comps[1];
	orientation->z = orient_comps[2];
	orientation->w = 0;
}

t_bool	create_scale_matrix(char **data, t_minirt *minirt,
			int index, double **m)
{
	double		scalar;
	t_point3	s_point;

	(void)minirt;
	scalar = ft_fatoi(data[index]);
	if (!scalar || check_fatoi_error(scalar, 2, 2) || scalar < EPSILON)
		return (false);
	scalar = scalar / 2;
	set_point(&s_point, scalar, scalar, scalar);
	get_scaling_matrix(m, scalar, scalar, scalar);
	return (true);
}

t_bool	create_rotate_matrix(char **data, t_minirt *minirt,
			int index, t_ray_object *obj)
{
	double		orient_comps[3];
	t_vector3	orientation;

	if (data_to_vector(data, orient_comps, minirt, index) == false)
		return (false);
	if ((orient_comps[0] == 0 && orient_comps[1] == 0 && orient_comps[2] == 0))
		return (false);
	if ((orient_comps[0] == 0 && orient_comps[2] == 0)
		&& (orient_comps[1] >= -1 && orient_comps[1] <= 1))
		return (true);
	if ((obj->LOCAL_NORMAL_FUNCTION == cylinder_normal_tremo)
		|| (obj->LOCAL_NORMAL_FUNCTION == plane_normal_tremo))
		negate_coords(orient_comps, minirt);
	set_orientation(orient_comps, &orientation);
	create_quarternion1(&orientation, minirt, obj->rotate_mtx, obj);
	return (true);
}
