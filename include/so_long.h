/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:17:18 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/09 16:06:32 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include "/usr/local/include/mlx.h"

typedef struct s_data
{
	char *map;
	int E_counter;
	int C_counter;
	int P_counter;
	
} t_data;


int is_map_rectangular(char *map, size_t len);
char *read_map(int fd);
int is_map_valid(t_data *data);


# endif