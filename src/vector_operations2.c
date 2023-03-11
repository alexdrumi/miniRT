/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector_operations2.h"
#include "../inc/general_utils3.h"
#include <math.h>

void	normalize(t_vector3 *v1)
{
	double	magnitude;

	if (!v1)
		return ;
	magnitude = get_magnitude(v1);
	v1->x = v1->x / magnitude;
	v1->y = v1->y / magnitude;
	v1->z = v1->z / magnitude;
	v1->w = v1->w / magnitude;
}

double	get_dot_prod(t_vector3 *v1, t_vector3 *v2)
{
	double	dot_product;

	dot_product = (v1->x * v2->x) + (v1->y * v2->y)
		+ (v1->z * v2->z) + (v1->w * v2->w);
	return (dot_product);
}

double	get_magnitude(t_vector3 *v1)
{
	double	magnitude;

	magnitude = sqrt(pow(v1->x, 2) + pow(v1->y, 2)
			+ pow(v1->z, 2) + pow(v1->w, 2));
	return (magnitude);
}

void	cross_product_l(t_vector3 *v1, t_vector3 *v2, t_vector3 *res)
{
	double	i;
	double	j;
	double	k;

	i = (v1->y * v2->z) - (v1->z * v2->y);
	j = (v1->z * v2->x) - (v1->x * v2->z);
	k = (v1->x * v2->y) - (v1->y * v2->x);
	res->x = i;
	res->y = j;
	res->z = k;
	res->w = 0;
	return ;
}
