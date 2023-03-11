/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy3.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTROY4_H
# define DESTROY4_H
# include "../inc/structs.h"

void	*destroy_w_return(void *arg1, ...);
void	destroy_mat(t_mat *mat);
void	destroy_matrix(double **matrix, int n);
t_bool	free_chararr_return_false(char **splitted);

#endif