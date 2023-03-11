/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy1.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTROY1_H
# define DESTROY1_H
# include "../inc/structs.h"
# include <stdio.h>
# include <stdarg.h>

void	destroy_pointers(void *arg1, ...);
void	destroy_pointlight(void *light);

#endif