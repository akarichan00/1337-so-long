/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:53:14 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/25 12:53:19 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*concat_and_free(char *map, char *line)
{
	char	*save;

	save = ft_strjoin(map, line);
	free(line);
	if (map)
		free(map);
	return (save);
}

char	*read_map(int fd)
{
	char	*line;
	char	*map;
	size_t	len;
	char	*original_map;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	map = NULL;
	while (line != NULL)
	{
		map = concat_and_free(map, line);
		if (!map)
			return (NULL);
		line = get_next_line(fd);
	}
	original_map = map;
	if (is_map_rectangular(original_map, len) == 0)
		return (free(map), (NULL));
	// free(original_map);
	return (map);
}

int	is_character_invalid(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
		return (0);
	return (1);
}

void	count_characters(t_data *data)
{
	char	*temp_map;

	data->e_counter = 0;
	data->c_counter = 0;
	data->p_counter = 0;
	temp_map = data->map;
	while (*temp_map != '\0')
	{
		if (*temp_map == 'E')
			data->e_counter++;
		else if (*temp_map == 'C')
			data->c_counter++;
		else if (*temp_map == 'P')
			data->p_counter++;
		temp_map++;
	}
}

int	is_map_valid(t_data *data)
{
	char	*temp_map;

	temp_map = data->map;
	while (*temp_map != '\0')
	{
		if (is_character_invalid(*temp_map) == 1)
			return (0);
		temp_map++;
	}
	count_characters(data);
	if (data->e_counter != 1 || data->c_counter < 1 || data->p_counter != 1)
		return (0);
	return (1);
}
