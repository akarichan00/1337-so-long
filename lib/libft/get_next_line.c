/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:55:25 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/08 10:51:24 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

int	find_n(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*initialize(char **rest, char **line)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!*rest)
	{
		*rest = malloc(1);
		if (!*rest)
			return (NULL);
		(*rest)[0] = '\0';
	}
	else
		*line = fft_strjoin(*line, *rest);
	buffer[0] = '\0';
	return (buffer);
}

char	*sep_n(char *line, char **rest)
{
	int		i;
	char	*temp;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		ft_free(rest);
		return (line);
	}
	else if (line[i] == '\n')
	{
		ft_free(rest);
		*rest = ft_substr(line, i + 1, fft_strlen(line) - i - 1);
		temp = ft_substr(line, 0, i + 1);
		ft_free(&line);
		return (temp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;
	int			bytes_read;
	char		*buffer;

	line = NULL;
	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = initialize(&rest, &line);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && find_n(buffer) == 0)
	{
		bytes_read = read_file(fd, buffer);
		if (handle_errors_and_join(&bytes_read, &buffer, &line, &rest))
			return (NULL);
	}
	ft_free(&buffer);
	if (bytes_read == 0 && line && line[0] == '\0')
		return (ft_free(&line));
	line = sep_n(line, &rest);
	return (line);
}
