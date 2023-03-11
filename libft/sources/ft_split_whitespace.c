/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 07:33:10 by bmajor        #+#    #+#                 */
/*   Updated: 2020/11/03 20:29:28 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r');
}

static size_t	ft_count_words(char const *s)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		while (*s != '\0' && is_whitespace(*s) == 1)
		{
			s++;
			flag = 1;
		}
		while (*s != '\0' && is_whitespace(*s) == 0)
		{
			s++;
			flag = 0;
		}
		if ((*s == '\0' || is_whitespace(*s) == 1) && flag == 0)
			count++;
	}
	return (count);
}

static size_t	set_array(char **ret, char *cur, char *s, size_t *pos)
{
	size_t	i;

	i = *pos;
	ret[i] = (char *)ft_calloc(((cur - s) + 1), sizeof(char));
	if (ret[i] == NULL)
	{
		return (ft_free_str(ret, i));
	}
	ft_strlcpy(ret[i], s, (cur - s) + 1);
	(*pos)++;
	return (1);
}

static char	**create_array(char const *s, size_t *word_count)
{
	char	**ret;

	if (s == 0)
		return (NULL);
	*word_count = ft_count_words(s);
	ret = (char **)malloc((*word_count + 1) * sizeof(char *));
	return (ret);
}

char	**ft_split_whitespace(char const *s)
{
	char	**arr;
	char	*cur;
	size_t	i;
	size_t	word_count;

	arr = create_array(s, &word_count);
	if (arr == 0)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (is_whitespace(*s) == 1)
			s++;
		cur = (char *)s;
		if (cur == 0)
			break ;
		while (*cur != '\0' && is_whitespace(*cur) == 0)
			cur++;
		if (set_array(arr, cur, (char *)s, &i) == 1)
			s = cur;
		else
			return (NULL);
	}
	arr[i] = NULL;
	return (arr);
}
