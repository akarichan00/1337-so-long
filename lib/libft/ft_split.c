/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:27:10 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/24 11:39:05 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordscounter(char *s, char sep)
{
	int	i;
	int	words_counter;

	i = 0;
	words_counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == sep)
			i++;
		if (s[i] != '\0' && s[i] != sep)
			words_counter++;
		while (s[i] != sep && s[i])
			i++;
	}
	return (words_counter);
}

static char	*ft_malloc_word(char *s, char c)
{
	size_t	wlen;
	char	*word;

	wlen = 0;
	while (s[wlen] != '\0' && s[wlen] != c)
		wlen++;
	word = (char *)malloc(sizeof(char) * (wlen + 1));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s, wlen + 1);
	return (word);
}

void	free_words(char **strings, int index)
{
	while (index >= 0)
	{
		free(strings[index]);
		index--;
	}
	free(strings);
}

static char	**ft_smallsplit(char *s, char **strings, char c)
{
	int	word_index;

	word_index = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			strings[word_index] = ft_malloc_word(s, c);
			if (strings[word_index] == NULL)
			{
				free_words(strings, word_index - 1);
				return (NULL);
			}
			word_index++;
		}
		while (*s != c && *s != '\0')
			s++;
	}
	strings[word_index] = NULL;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	strings = (char **)malloc(sizeof(char *) * (ft_wordscounter(str, c) + 1));
	if (strings == NULL)
		return (NULL);
	return (ft_smallsplit(str, strings, c));
}


