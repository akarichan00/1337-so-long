/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:48:32 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/29 18:54:10 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int load_images(t_map_info *info)
{
    info->player = mlx_load_png("./textures/player.png");
    if (!info->player)
        return(0);
    info->wall = mlx_load_png("./textures/wall.png");
    if (!info->wall)
        return (mlx_delete_texture(info->player),0);        
    info->exit = mlx_load_png("./textures/exit.png");
    if (!info->exit)
    {
        mlx_delete_texture(info->player);
        return (mlx_delete_texture(info->wall),0);
    }
    info->coin = mlx_load_png("./textures/coin.png");
    if (!info->coin)
    {
        mlx_delete_texture(info->player);
        mlx_delete_texture(info->wall);
        return (mlx_delete_texture(info->exit), 0);
    }
    info->empty = mlx_load_png("./textures/free.png");
    if (!info->empty)
        return (delete_textures_5(info),0);
    return (1);
}

int t_to_image(t_map_info *info)
{
	info->img1 = mlx_texture_to_image(info->mlx, info->player);
	if (!info->img1)
		return (delete_all_textures(info), (0));
	info->img2 = mlx_texture_to_image(info->mlx, info->wall); 
	if (!info->img2)
	{
		delete_all_textures(info);
		return (mlx_delete_image(info->mlx, info->img1), 0);
	}
	info->img3 = mlx_texture_to_image(info->mlx, info->exit);
	if (!info->img3)
	{
		delete_all_textures(info);
		mlx_delete_image(info->mlx, info->img1);
		return (mlx_delete_image(info->mlx, info->img2), 0);
	}
	info->img4 = mlx_texture_to_image(info->mlx, info->coin);
	if (!info->img4)
		return (delete_img4(info), 0);
	info->img5 = mlx_texture_to_image(info->mlx, info->empty);
	if (!info->img5)
		return (delete_img5(info), 0);
	return (1);
}

// void delete_all_images(t_map_info *info)
// {
// 	mlx_delete_image(info->mlx, info->img1);
// 	mlx_delete_image(info->mlx, info->img2);
// 	mlx_delete_image(info->mlx, info->img3);
// 	mlx_delete_image(info->mlx, info->img4);
// 	mlx_delete_image(info->mlx, info->img5);
// }

void display_images(t_map_info *info)
{
	int i;
	int j;

	i = -1;
	while (info->original_map[++i] != '\0')
	{
		j = 0;
		while (info->original_map[i][j] != '\0')
		{
			if (info->original_map[i][j] == 'P')
			{
				check_img(info, info->img5, j , i);
				check_img(info, info->img1, j , i);
			}
			else if (info->original_map[i][j] == '0')
				check_img(info, info->img5, j , i);
			else if (info->original_map[i][j] == '1')
				check_img(info, info->img2, j , i);
			else if (info->original_map[i][j] == 'E')
				check_img(info, info->img3, j , i);
			else if (info->original_map[i][j] == 'C')
				check_img(info, info->img4, j , i);
			j++;
		}
	}
}
void close_game(void *param)
{
	t_map_info *info;
	
	info = (t_map_info *)param;
	delete_all_textures(info);
	mlx_close_window(info->mlx);
	exit(0);
}
void key_press(mlx_key_data_t keydata, void *param)
{
	t_map_info *info;

	info = (t_map_info *) param;

	if (keydata.key == MLX_KEY_ESCAPE)
	{
		// finito
		delete_all_textures(info);
		mlx_close_window(info->mlx);
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
	{
		ft_printf("GG EZ (ﾉ◕ヮ◕)ﾉ ･ﾟ✧\n");
		delete_all_textures(info);
		mlx_close_window(info->mlx);
		free_it_all(info);
		exit(0);
	}
}
