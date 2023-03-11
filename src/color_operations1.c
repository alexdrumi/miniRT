/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_operations1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/color_operations1.h"
#include "../inc/coloring_functions.h"
#include "../inc/general_utils3.h"

t_color	*add_color(t_color *c1, t_color *c2)
{
	t_color	*new_color;

	new_color = (t_color *)malloc(sizeof(t_color));
	if (!c1 || !c2 || !new_color)
		print_malloc_error_and_exit();
	new_color->r = c1->r + c2->r;
	new_color->g = c1->g + c2->g;
	new_color->b = c1->b + c2->b;
	return (new_color);
}

void	scalar_color_mult_loc(t_color *c1, double scalar, t_color *res)
{
	if (!c1 || !res || !scalar)
		return ;
	res->r = scalar * c1->r;
	res->g = scalar * c1->g;
	res->b = scalar * c1->b;
}

t_color	*scalar_color_multicipation(t_color *c1, double scalar)
{
	t_color	*new_color;

	if (!c1)
		return (NULL);
	new_color = (t_color *)malloc(sizeof(t_color));
	if (!new_color)
		print_malloc_error_and_exit();
	new_color->r = scalar * c1->r;
	new_color->g = scalar * c1->g;
	new_color->b = scalar * c1->b;
	return (new_color);
}

void	color_mult_local(t_color *c1, t_color *c2, t_color *res)
{
	if (!c1 || !c2 || !res)
		return ;
	res->r = c1->r * c2->r;
	res->g = c1->g * c2->g;
	res->b = c1->b * c2->b;
}

void	add_color_local(t_color *c1, t_color *c2, t_color *res)
{
	if (!c1 || !c2 || !res)
		return ;
	res->r = c1->r + c2->r;
	res->g = c1->g + c2->g;
	res->b = c1->b + c2->b;
}
