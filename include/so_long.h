/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:17:18 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/25 19:30:32 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	char	*map;
	int		e_counter;
	int		c_counter;
	int		p_counter;
}			t_data;

typedef struct s_map_info
{
	int		collectibles;
	int		exits;
	char	**map;
	char	**original_map;
	int		x;
	int		y;
	int		a;
	int		b;
}			t_map_info;

int			is_map_rectangular(char *map, size_t len);
char		*read_map(int fd);
int			is_map_valid(t_data *data);
int			check_walls(char *map);
void		count_characters(t_data *data);
void		free_words(char **strings, int index);
void		get_player_position(t_map_info *info);
char		**convert_to_2d_array(char *str, int *len);
void		calculate_dimensions(char *str, int *rows, int *cols);
int			check_valid_path(t_data *data, t_map_info *info);

#endif