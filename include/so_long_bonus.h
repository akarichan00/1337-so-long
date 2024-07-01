/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 07:42:59 by noben-ai          #+#    #+#             */
/*   Updated: 2024/07/01 14:02:22 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char			*map;
	int				e_counter;
	int				c_counter;
	int				p_counter;
}					t_data;

typedef struct s_map_info
{
	int				collectibles;
	int				exits;
	char			**map;
	char			**original_map;
	int				free_index;
	int				eposition_x;
	int				eposition_y;
	int				x;
	int				y;
	int				a;
	int				b;
	mlx_t			*mlx;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_texture_t	*coin;
	mlx_texture_t	*empty;
	mlx_image_t		*img1;
	mlx_image_t		*img2;
	mlx_image_t		*img3;
	mlx_image_t		*img4;
	mlx_image_t		*img5;
	t_data			*data;
	int				count_c;

}					t_map_info;

int					is_map_rectangular(char *map, size_t len);
char				*read_map(int fd);
int					is_map_valid(t_data *data);
int					check_walls(char *map);
void				count_characters(t_data *data);
void				free_words(char **strings, int index);
void				get_player_position(t_map_info *info);
char				**convert_to_2d_array(char *str, int *len,
						t_map_info *info);
void				calculate_dimensions(char *str, int *rows, int *cols);
int					check_valid_path(t_data *data, t_map_info *info);
void				free_it_all(t_map_info *info);

int					check_boundaries(t_map_info *info);
int					load_images(t_map_info *info);
int					t_to_image(t_map_info *info);
void				display_images(t_map_info *info);
void				key_press(mlx_key_data_t keydata, void *param);
void				move(t_map_info *info, int x, int y);
int					draw(t_map_info *info);
void				delete_textures_5(t_map_info *info);
void				delete_all_textures(t_map_info *info);
void				delete_img4(t_map_info *info);
void				delete_img5(t_map_info *info);
void				check_img(t_map_info *info, mlx_image_t *img, int j, int i);
void				close_game(void *param);
void				do_smth(t_map_info *info, int x, int y);
void				print_moves(t_map_info *info, int c);
#endif