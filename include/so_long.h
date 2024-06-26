/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:17:18 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/26 21:49:46 by noben-ai         ###   ########.fr       */
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
# include "../../MLX42/include/MLX42/MLX42.h"

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
	int		free_index;
	int		eposition_x;
	int		eposition_y;
	int		x;
	int		y;
	// a = height
	// b = width
	int		a;
	int		b;
	mlx_t 	*mlx;
	mlx_texture_t* player;
	mlx_texture_t* wall;
	mlx_texture_t* exit;
	mlx_texture_t* coin;
	mlx_texture_t* empty;
	mlx_image_t*	img1;
	mlx_image_t*	img2;
	mlx_image_t*	img3;
	mlx_image_t*	img4;
	mlx_image_t*	img5;

	
}			t_map_info;

int			is_map_rectangular(char *map, size_t len);
char		*read_map(int fd);
int			is_map_valid(t_data *data);
int			check_walls(char *map);
void		count_characters(t_data *data);
void		free_words(char **strings, int index);
void		get_player_position(t_map_info *info);
char		**convert_to_2d_array(char *str, int *len, t_map_info *info);
void		calculate_dimensions(char *str, int *rows, int *cols);
int			check_valid_path(t_data *data, t_map_info *info);
void		free_it_all(t_map_info *info, t_data *data);

int check_boundaries(t_map_info *info, t_data *data);
int load_images(t_map_info *info);
int t_to_image(t_map_info *info);
void display_images(t_map_info *info);
void key_press(mlx_key_data_t keydata);

#endif