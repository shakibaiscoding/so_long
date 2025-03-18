/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:57:17 by saghighi          #+#    #+#             */
/*   Updated: 2024/11/01 07:52:17 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_arr(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free (ptr[i]);
	}
	free (ptr);
	return (NULL);
}

static int	words_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**split_words(const char *s, char c, char **s2, int num_words)
{
	int	i;
	int	word_len;
	int	word;

	i = 0;
	word_len = 0;
	word = 0;
	while (word < num_words)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof (char) * (word_len + 1));
		if (!s2[word])
			return (free_arr (s2, word));
		putword (s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = NULL;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
	{
		return (NULL);
	}
	num_words = words_count (s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
	{
		return (NULL);
	}
	s2 = split_words(s, c, s2, num_words);
	return (s2);
}
