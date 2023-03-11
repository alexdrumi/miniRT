/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy4.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/general_utils3.h"
#include "../inc/destroy1.h"
#include "../inc/destroy2.h"
#include "../inc/destroy4.h"
#include "../inc/structs.h"

void	*destroy_w_return(void *arg1, ...)
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
	return (NULL);
}

void	destroy_mat(t_mat *mat)
{	
	destroy_pointers(mat->pattern.a, mat->pattern.b,
		mat->pattern.transformation_matrix, NULL);
	destroy_matrix(mat->pattern.transformation_matrix, 4);
	free(mat);
}

void	destroy_matrix(double **matrix, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

t_bool	free_chararr_return_false(char **splitted)
{
	if (splitted != NULL)
	{
		free_split_array((char **)splitted);
	}
	return (false);
}
