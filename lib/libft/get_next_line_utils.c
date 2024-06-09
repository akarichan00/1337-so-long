/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:55:29 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/08 10:52:23 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	fft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > fft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char));
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if ((start + len) > fft_strlen(s))
		len = fft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub[len] = '\0', sub);
}

char	*fft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((s2 && s2[0] == '\0') && s1 == NULL)
		return (NULL);
	string = (char *)malloc((fft_strlen(s1) + fft_strlen(s2) + 1));
	if (string == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
			string[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
		string[j++] = s2[i++];
	string[j] = '\0';
	ft_free(&s1);
	return (string);
}

int	read_file(int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read != -1)
		buffer[bytes_read] = '\0';
	return (bytes_read);
}

int	handle_errors_and_join(int *bytes_read, char **buffer, char **line,
		char **rest)
{
	if (*bytes_read == -1)
	{
		ft_free(buffer);
		ft_free(line);
		ft_free(rest);
		return (1);
	}
	*line = fft_strjoin(*line, *buffer);
	if (!*line)
	{
		ft_free(rest);
		ft_free(buffer);
		return (1);
	}
	return (0);
}
