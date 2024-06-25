/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:53:14 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/25 09:56:25 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//concatenate lines to map.
char *concat_and_free(char *map, char *line)
{
    char *save = ft_strjoin(map , line);
    free(line);
    if (map)
        free(map);
    return save;
}

// Reads the map from a file and returns it as a string.
char *read_map(int fd)
{
	char *line;
	char *map;
	size_t len;
	char *original_map;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	map = NULL;
	while(line != NULL)
	{
		map = concat_and_free(map, line);
		if (!map)
			return (NULL);
		line = get_next_line(fd);
	}
	original_map = map;
	if (is_map_rectangular(original_map, len) == 0)
			return (free(map), (NULL));
	free(original_map);
	return(map);
}

// Checks if a character is valid in the map.
int is_character_invalid(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
		return (0);
	return (1);
}

// Counts the number of 'E', 'C', and 'P' characters in the map.
void count_characters(t_data *data)
{
	char *temp_map;
	
	temp_map = data->map;
    while(*temp_map != '\0')
    {
        if (*temp_map == 'E')
            data->E_counter++;
        else if (*temp_map == 'C')
            data->C_counter++;
        else if (*temp_map == 'P')
            data->P_counter++;
        temp_map++;
    }
}

// Checks if the map is valid.
int is_map_valid(t_data *data)
{
	char *temp_map;
	
	temp_map = data->map;
    while(*temp_map != '\0')
    {
        if (is_character_invalid(*temp_map) == 1)
		{
			// ft_printf("Error\nMap contains invalid character '%c'\n", *temp_map);
            return (0);
		}
		temp_map++;
    }
	count_characters(data);
    if (data->E_counter != 1 || data->C_counter < 1 || data->P_counter != 1)
		{
			// ft_printf("Error\nMap has invalid counts (E: %d, C: %d, P: %d)\n", data->E_counter, data->C_counter, data->P_counter);
			return (0);
		}
    return (1);
}

