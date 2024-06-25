/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:42:51 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/25 10:26:09 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


// check for valid path 
	// -> is the exit accessible from the start position
	// -> are all the collectibles accessible from the start position

void get_player_position(char **map, int *x, int *y)
{
	int  i;
	int  j;

	i = 0;

	while(map[i] != '\0')
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return;
			}
			j++;
		}
		i++;
	}
}

void flood_fill(char **map, int x, int y, int *collectibles, int *exits) {
    // Check if the position is a wall or has already been visited
    if (map[x][y] == '1' || map[x][y] == '+')
        return;
	if (map[x][y] == 'C')
		(*collectibles)++;
	if (map[x][y] == 'E')
		(*exits)++;	
    // Mark the position as visited
    map[x][y] = '+';
	
    // Apply the flood fill algorithm to all neighboring positions
    flood_fill(map, x - 1, y, collectibles, exits);  // Up
    flood_fill(map, x + 1, y, collectibles, exits);  // Down
    flood_fill(map, x, y - 1, collectibles, exits);  // Left
    flood_fill(map, x, y + 1, collectibles, exits);  // Right
}

int check_map_visited(char **map, int *a, int *b)
{
	int  i;
	int  j;

	i = 0;
	
	while(i < *a)
	{
		j = 0;
		while (j < *b)
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int check_valid_path(t_data *data, int *x, int *y)
{
	char *str;
	char *cpy;
	char **map;
	int i = 0;
	
	str = data->map;
	cpy = str;
	// covert the map to 2d array (to use it in flood fill algortithm)
	map = convert_to_2d_array(cpy, &i);
	if (!map)
		return (0);
	// flood fill algorithm
	// searching for the player's position in the 2d array
	get_player_position(map, x, y);
	int collectibles = 0;
	int exits = 0;
	flood_fill(map, *x, *y, &collectibles, &exits);
	if (data->C_counter != collectibles || data->E_counter != exits)
		return (free_words(map, i), 0);
	int a = 0;
	int b = 0;
	calculate_dimensions(cpy ,&a, &b);
	if (!check_map_visited(map, &a, &b))
		return (free_words(map, i),0);
	free_words(map, i);
	return (1);
}
