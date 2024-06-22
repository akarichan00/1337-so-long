/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:56 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/22 19:10:19 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// check if map is in a rectangular shape 
int is_map_rectangular(char *map, size_t len)
{
	size_t len_line; 

	len_line = 0;

	// the main logic here is to check if all lines have the same length
	while(*map != '\0')
	{
		while (*map != '\0' && *map != '\n')
		{
			len_line++;
			map++;
		}
		if (len_line != len)
			return (0);
		len_line = 0;
		if (*map == '\n')
        	map++; 
	}
    return (1);
}

int check_walls(char *map)
{
	// check if first line is a wall
	int i;
	char *temp;

	i = 0;
	temp = map;
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			return (0);
		i++;		
	}
	// check sides (walls)
	while(map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			if (map[i - 1] != '1' || (map[i + 1] != '\0' && map[i + 1] != '1'))
				return (0);		
		}
		i++;		
	}
	i = ft_strlen(temp) - 1;
	// check if last line is a wall
	while (i >= 0 && map[i] != '\n')
	{
		if (map[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

// check for valid path 
	// is the exit accessible from the start position
	// are all the collectibles accessible from the start position

int check_valid_path(t_data *data)
{
	// count_characters(map);
	char *temp_map;
	
	temp_map = data->map;
	while(*temp_map != '\0')
    {
        
        if (*temp_map == 'C')
            data->C_counter++;
        
        temp_map++;
    }
	
}