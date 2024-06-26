/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:56 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/26 12:30:29 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_map_rectangular(char *map, size_t len)
{
	size_t	len_line;

	len_line = 0;
	if (!map)
		return (0);
	while (*map != '\0')
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

int	check_walls(char *map)
{
	int		i;
	char	*temp;

	i = -1;
	temp = map;
	while (map[++i] != '\n')
	{
		if (map[i] != '1')
			return (0);
	}
	while (map[++i] != '\0')
	{
		if (map[i] == '\n')
		{
			if (map[i - 1] != '1' || (map[i + 1] != '\0' && map[i + 1] != '1'))
				return (0);
		}
	}
	i = ft_strlen(temp);
	while (--i >= 0 && map[i] != '\n')
	{
		if (map[i] != '1')
			return (0);
	}
	return (1);
}

void	calculate_dimensions(char *str, int *rows, int *cols)
{
	int	i;

	i = 0;
	*rows = 0;
	*cols = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			(*rows)++;
			if (*rows == 1)
				*cols = i;
		}
		i++;
	}
	if (str[i] == '\0')
		(*rows)++;
}

void	copy_to_2d_array(char **arr, char *str)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			arr[row][col] = '\0';
			row++;
			col = 0;
		}
		else
		{
			arr[row][col] = str[i];
			col++;
		}
		i++;
	}
	arr[row][col] = '\0';
}

char	**convert_to_2d_array(char *str, int *len, t_map_info *info)
{
	int		rows;
	int		cols;
	int		i;
	char	**arr;

	calculate_dimensions(str, &rows, &cols);
	if (!str)
		return (NULL);
	arr = malloc((rows + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		arr[i] = malloc((cols + 1) * sizeof(char));
		if (!arr[i])
			return (free_words(arr, i - 1), (NULL));
		arr[i][cols] = '\0';
		i++;
	}
	arr[i] = NULL;
	*len = i;
	info->free_index = i;
	copy_to_2d_array(arr, str);
	return (arr);
}
