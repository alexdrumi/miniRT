/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_square.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/intersect_square.h"

void	set_p_at_parameter(t_point3 *p1, t_vector3 *v1, t_point3 *res)
{
	res->x = p1->x + v1->x;
	res->y = p1->y + v1->y;
	res->z = p1->z + v1->z;
	res->w = p1->w + v1->w;
}
