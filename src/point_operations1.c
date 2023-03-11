/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point_operations1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/point_operations1.h"

void	point_plus_vector(t_point3 *p1, t_vector3 *v1, t_vector3 *res)
{
	if (!p1 || !v1 || !res)
		return ;
	res->x = p1->x + v1->x;
	res->y = p1->y + v1->y;
	res->z = p1->z + v1->z;
	res->w = p1->w + v1->w;
	return ;
}

void	set_point(t_point3 *point, double x, double y, double z)
{
	if (!point)
		return ;
	point->x = x;
	point->y = y;
	point->z = z;
	point->w = 1;
}

void	point_min_point(t_point3 *p1, t_point3 *p2, t_vector3 *res)
{
	if (!p1 || !p2 || !res)
		return ;
	res->x = p1->x - p2->x;
	res->y = p1->y - p2->y;
	res->z = p1->z - p2->z;
	res->w = p1->w - p2->w;
}

void	point_min_vector(t_point3 *p1, t_vector3 *v1, t_vector3 *res)
{
	if (!p1 || !v1 || !res)
		return ;
	res->x = p1->x - v1->x;
	res->y = p1->y - v1->y;
	res->z = p1->z - v1->z;
	res->w = p1->w - v1->w;
	return ;
}
