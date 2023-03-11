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

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		while (*s != '\0' && *s == c)
		{
			s++;
			flag = 1;
		}
		while (*s != '\0' && *s != c)
		{
			s++;
			flag = 0;
		}
		if ((*s == '\0' || *s == c) && flag == 0)
			count++;
	}
	return (count);
}

static int	free_str(char **str, size_t index)
{
	while (index > 0)
	{
		free(str[index - 1]);
		index--;
	}
	free(str);
	return (0);
}

static size_t	set_array(char **ret, char *cur, char *s, size_t *pos)
{
	size_t	i;

	i = *pos;
	ret[i] = (char *)ft_calloc(((cur - s) + 1), sizeof(char));
	if (ret[i] == NULL)
	{
		return (free_str(ret, i));
	}
	ft_strlcpy(ret[i], s, (cur - s) + 1);
	(*pos)++;
	return (1);
}

static char	**create_array(char const *s, char c, size_t *word_count)
{
	char	**ret;

	if (s == 0)
		return (NULL);
	*word_count = ft_count_words(s, c);
	ret = (char **)malloc((*word_count + 1) * sizeof(char *));
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*cur;
	size_t	i;
	size_t	word_count;

	arr = create_array(s, c, &word_count);
	if (arr == 0)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		cur = (char *)s;
		if (cur == 0)
			break ;
		while (*cur != '\0' && *cur != c)
			cur++;
		if (set_array(arr, cur, (char *)s, &i) == 1)
			s = cur;
		else
			return (NULL);
	}
	arr[i] = NULL;
	return (arr);
}
