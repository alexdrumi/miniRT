/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <bmajor@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/26 14:40:25 by bmajor        #+#    #+#                 */
/*   Updated: 2022/01/26 14:40:25 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define LINE_HAS_BEEN_READ 1
# define EOF_HAS_BEEN_REACHED 0
# define AN_ERROR_HAPPENED -1
# define BUFFER_SIZE 32
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/headers/libft.h"

int		is_n_in_str(char *s);
char	*join_with_buffer(char *buff, char *str[9999], int ret, const int fd);
void	create_new_str_fd(const int fd, char *str[9999], int is_n_in_s);
char	*line_without_n(char *str[9999], const int fd);
void	search_for_newline(char *buff, const int fd, char *str[9999], int *ret);
int		get_next_line(const int fd, char **line);

#endif
