/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:46:46 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/30 07:43:57 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	delete_textures_5(t_map_info *info)
{
	mlx_delete_texture(info->player);
	mlx_delete_texture(info->wall);
	mlx_delete_texture(info->exit);
	mlx_delete_texture(info->coin);
}

void	delete_all_textures(t_map_info *info)
{
	mlx_delete_texture(info->player);
	mlx_delete_texture(info->wall);
	mlx_delete_texture(info->exit);
	mlx_delete_texture(info->coin);
	mlx_delete_texture(info->empty);
}

void	delete_img4(t_map_info *info)
{
	delete_all_textures(info);
	mlx_delete_image(info->mlx, info->img1);
	mlx_delete_image(info->mlx, info->img2);
	mlx_delete_image(info->mlx, info->img3);
}

void	delete_img5(t_map_info *info)
{
	delete_all_textures(info);
	mlx_delete_image(info->mlx, info->img1);
	mlx_delete_image(info->mlx, info->img2);
	mlx_delete_image(info->mlx, info->img3);
	mlx_delete_image(info->mlx, info->img4);
}

void	check_img(t_map_info *info, mlx_image_t *img, int j, int i)
{
	if (mlx_image_to_window(info->mlx, img, j * 90, i * 90) < 0)
	{
		delete_all_textures(info);
		mlx_close_window(info->mlx);
		exit(1);
	}
}
