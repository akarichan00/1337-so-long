/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:42:51 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/25 19:34:25 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_player_position(t_map_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i] != '\0')
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			if (info->map[i][j] == 'P')
			{
				info->x = i;
				info->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_map_info *info, int x, int y)
{
	if (x < 0 || y < 0 || x >= info->a || y >= info->b)
		return ;
	if (info->map[x][y] == '1' || info->map[x][y] == '+')
		return ;
	if (info->map[x][y] == 'C')
		(info->collectibles)++;
	if (info->map[x][y] == 'E')
		(info->exits)++;
	info->map[x][y] = '+';
	flood_fill(info, x + 1, y);
	flood_fill(info, x - 1, y);
	flood_fill(info, x, y + 1);
	flood_fill(info, x, y - 1);
}

int	check_map_visited(char **map, int *a, int *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < *a)
	{
		j = 0;
		while (j < *b)
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E'
				|| map[i][j] == '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid_path(t_data *data, t_map_info *info)
{
	char	*str;
	char	*cpy;
	int		i;

	i = 0;
	str = data->map;
	cpy = str;
	info->map = convert_to_2d_array(cpy, &i);
	info->original_map = convert_to_2d_array(cpy, &i);
	if (!info->map)
		return (0);
	get_player_position(info);
	info->collectibles = 0;
	info->exits = 0;
	info->a = 0;
	info->b = 0;
	calculate_dimensions(cpy, &info->a, &info->b);
	flood_fill(info, info->x, info->y);
	if (data->c_counter != info->collectibles || data->e_counter != info->exits)
		return (printf("na uh\n"), 0); // free_words(info->map, i)
	if (!check_map_visited(info->map, &info->a, &info->b))
		return (0); // free_words(info->map, i)
	// free_words(info->map, i);
	return (1);
}
