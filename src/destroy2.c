/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/destroy4.h"
#include "../inc/structs.h"

void	destroy_ray_obj(void *ray_object)
{
	t_ray_object	*obj;

	obj = (t_ray_object *)ray_object;
	if (obj != NULL)
	{
		destroy_matrix(obj->transform_mtx, 4);
		destroy_matrix(obj->inv_transform_mtx, 4);
		destroy_matrix(obj->transpose_inv_mtx, 4);
		destroy_matrix(obj->translate_mtx, 4);
		destroy_matrix(obj->rotate_mtx, 4);
		destroy_matrix(obj->scale_mtx, 4);
	}
	free(ray_object);
}
