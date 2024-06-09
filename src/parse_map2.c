/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:03:56 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/09 16:06:14 by noben-ai         ###   ########.fr       */
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
