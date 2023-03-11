/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/destroy1.h"
#include "../inc/destroy2.h"

void	destroy_pointers(void *arg1, ...)
{
	va_list	args;
	void	*vp;

	free(arg1);
	va_start(args, arg1);
	vp = va_arg(args, void *);
	while (vp != 0)
	{
		free(vp);
		vp = va_arg(args, void *);
	}
	va_end(args);
	return ;
}

void	destroy_pointlight(void *light)
{	
	t_pointlight	*plight;

	plight = (t_pointlight *)light;
	free(plight);
	return ;
}
