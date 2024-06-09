/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:38:04 by noben-ai          #+#    #+#             */
/*   Updated: 2023/12/29 19:58:40 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_char_in_set(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	s;
	size_t	e;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	s = 0;
	e = ft_strlen(s1) - 1;
	while (s1[s] != '\0' && ft_find_char_in_set(set, s1[s]))
		s++;
	while (e > s && ft_find_char_in_set(set, s1[e]))
		e--;
	trimmed = ft_substr(s1, s, (e - s) + 1);
	return (trimmed);
}
