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

#include "../inc/vector_operations1.h"
#include "../inc/general_utils3.h"

void	set_vector(t_vector3 *vector, double x, double y, double z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->w = 0;
	return ;
}

void	scalar_vec_mult_local(t_vector3 *v, double t, t_vector3 *res)
{
	res->x = t * v->x;
	res->y = t * v->y;
	res->z = t * v->z;
	res->w = t * v->w;
	return ;
}

void	vector_min_vector(t_vector3 *v1, t_vector3 *v2, t_vector3 *res)
{
	if (!v1 || !v2 || !res)
		return ;
	res->x = v1->x - v2->x;
	res->y = v1->y - v2->y;
	res->z = v1->z - v2->z;
	res->w = v1->w - v2->w;
	return ;
}

void	vector_plus_vector(t_vector3 *v1, t_vector3 *v2, t_vector3 *res)
{
	if (!v1 || !v2 || !res)
		return ;
	res->x = v1->x + v2->x;
	res->y = v1->y + v2->y;
	res->z = v1->z + v2->z;
	res->w = v1->w + v2->w;
	return ;
}

t_vector3	*scalar_vec_mult(t_vector3 *v1, double scalar)
{
	t_vector3	*new_vector;

	if (!v1)
		return (NULL);
	new_vector = (t_vector3 *)malloc(sizeof(t_vector3));
	if (!new_vector)
		print_malloc_error_and_exit();
	new_vector->x = scalar * v1->x;
	new_vector->y = scalar * v1->y;
	new_vector->z = scalar * v1->z;
	new_vector->w = scalar * v1->w;
	return (new_vector);
}
