/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort2.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT2_H
# define QUICKSORT2_H
# include "structs.h"

t_intersection	*partition_list(t_intersection *head,
					t_intersection *end,
					t_intersection **new_head,
					t_intersection **new_end);

#endif
