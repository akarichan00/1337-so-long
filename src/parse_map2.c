/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:56 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/25 10:05:10 by noben-ai         ###   ########.fr       */
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


void calculate_dimensions(char *str, int *rows, int *cols) {
    *rows = 0;
    *cols = 0;

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            (*rows)++;
            // If this is the first row, set *cols to the number of columns in this row
            if (*rows == 1) {
                *cols = i;
            }
        }
        i++;
    }
	// count last line
	if (str[i] == '\0')
		(*rows)++;
}

// Copy characters from the string to the 2D array
void copy_to_2d_array(char **arr, char *str)
{
	int i;
	int row;
	int col;
	
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

char **convert_to_2d_array(char *str, int *len)
{
	int rows;
	int cols;
	int i ;

	// calculate the number of rows and cols in the string
	calculate_dimensions(str, &rows, &cols);	

	// allocate memory for the 2D array (for the pointers to the strings)
	if (!str)
		return (NULL);
	char **arr = malloc((rows + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		//allocating memory for each individual string (or row)
		arr[i] = malloc((cols + 1) * sizeof(char));
		if (!arr[i])
			return (free_words(arr, i - 1), (NULL));
		arr[i][cols] = '\0';
		i++;
	}
	arr[i] = NULL;
	*len = i;
	copy_to_2d_array(arr, str);
	return arr;	
}


