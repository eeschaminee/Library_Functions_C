/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: eschamin <eschamin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:38:24 by eschamin       #+#    #+#                */
/*   Updated: 2019/11/14 10:37:12 by eschamin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count_c(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = -1;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char		*ft_create_word(const char *start, int len)
{
	char	*word;

	word = (char*)malloc(sizeof(char) * (len + 1));
	if (word == 0)
		return (0);
	if (len > 0)
		ft_strlcpy(word, start, len + 1);
	word[len] = '\0';
	return (word);
}

static void		ft_parse(const char *s, char c, char **result)
{
	int		start_word;
	int		word_i;
	int		i;

	start_word = -1;
	word_i = 0;
	i = 0;
	while (1)
	{
		if (start_word == -1)
		{
			if (s[i] != c)
				start_word = i;
		}
		else if (s[i] == c || s[i] == '\0')
		{
			result[word_i] = ft_create_word(s + start_word, i - start_word);
			word_i++;
			start_word = -1;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	result[word_i] = 0;
}

static int		ft_check_or_free(char **result, int word_count)
{
	int i;
	int filled;

	i = 0;
	filled = 1;
	while (i < word_count)
	{
		if (result[i] == 0)
			filled = 0;
		i++;
	}
	if (filled == 0)
	{
		i = 0;
		while (i < word_count)
		{
			if (result[i] != 0)
				free(result[i]);
			i++;
		}
		free(result);
		return (0);
	}
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;
	int		succeeded;

	if (s == 0)
		return (0);
	word_count = ft_count_c(s, c) + 1;
	result = (char**)malloc(sizeof(char*) * (word_count + 1));
	if (result == 0)
		return (0);
	if (word_count == 0)
	{
		result[0] = 0;
		return (result);
	}
	ft_parse(s, c, result);
	succeeded = ft_check_or_free(result, word_count);
	if (succeeded == 0)
		return (0);
	return (result);
}
