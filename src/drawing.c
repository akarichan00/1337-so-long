/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:48:32 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/27 17:11:12 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_boundaries(t_map_info *info, t_data *data)
{
	if (info->a > 16 || info->b > 29)
	{
		free_it_all(info, data);
		return (0);
	}
	return (1);
}

int load_images(t_map_info *info)
{
	info->player = mlx_load_png("./images/player.png");
	info->wall = mlx_load_png("./images/wall.png");
	info->exit = mlx_load_png("./images/exit.png");
	info->coin = mlx_load_png("./images/coin.png");
	info->empty = mlx_load_png("./images/free.png");
	if (!info->player || !info->wall || !info->exit || !info->coin || !info->empty)
		return(0);
	return (1);
}

int t_to_image(t_map_info *info)
{
	info->img1 = mlx_texture_to_image(info->mlx, info->player);
	info->img2 = mlx_texture_to_image(info->mlx, info->wall);
	info->img3 = mlx_texture_to_image(info->mlx, info->exit);
	info->img4 = mlx_texture_to_image(info->mlx, info->coin);
	info->img5 = mlx_texture_to_image(info->mlx, info->empty);
	if (!info->img1 || !info->img2 || !info->img3 || !info->img4 || !info->img5)
		return (0);
	return (1);
}

void display_images(t_map_info *info)
{
	int i;
	int j;

	i = 0;
	while (info->original_map[i] != '\0')
	{
		j = 0;
		while (info->original_map[i][j] != '\0')
		{
			if (info->original_map[i][j] == 'P')
			{
				mlx_image_to_window(info->mlx, info->img5, j * 90, i * 90);
				mlx_image_to_window(info->mlx, info->img1, j * 90, i * 90);
			}
			else if (info->original_map[i][j] == '0')
				mlx_image_to_window(info->mlx, info->img5, j * 90, i * 90);
			else if (info->original_map[i][j] == '1')
				mlx_image_to_window(info->mlx, info->img2, j * 90, i * 90);
			else if (info->original_map[i][j] == 'E')
				mlx_image_to_window(info->mlx, info->img3, j * 90, i * 90);
			else if (info->original_map[i][j] == 'C')
				mlx_image_to_window(info->mlx, info->img4, j * 90, i * 90);
			j++;
		}
		i++;
	}
}

void key_press(mlx_key_data_t keydata, void *param)
{
	t_map_info *info;

	info = (t_map_info *) param;

	if (keydata.key == MLX_KEY_ESCAPE)
	{
		// free everything and destroy images / leaks
		exit(0);
	}
	else if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move(param, info->x - 1, info->y);
	else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move(param, info->x + 1, info->y);
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move(param, info->x , info->y - 1);
	else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D) && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move(param, info->x, info->y + 1);
	ft_printf("total coins: %d\n", info->data->c_counter);
	ft_printf("collected coins: %d\n", info->count_c);

}

void move(t_map_info *info, int x, int y)
{
	static int count;

	if (info->original_map[x][y] == 'C')
	{
		info->original_map[x][y] = '0';
		mlx_image_to_window(info->mlx, info->img5, y * 90, x * 90);
		info->count_c++;
	}
	if (info->original_map[x][y] != '1')
	{
		count++;
		ft_printf("moves: %d\n", count);
		//delete the image ( the texture is still here)
		mlx_delete_image(info->mlx, info->img1);
		// update player position
		info->x = x;
		info->y = y;
		// texture to image
		info->img1 = mlx_texture_to_image(info->mlx, info->player);
		mlx_image_to_window(info->mlx, info->img1,  info->y  * 90,  info->x  *90);
	}
	// free shito and terminito everythingo finiitoooo
	if ((info->data->c_counter == info->count_c) && (info->x == info->eposition_x && info->y == info->eposition_y))
		exit(1);
	return;
}
