/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:35:36 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/29 20:40:36 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_game(void *param)
{
	t_map_info	*info;

	info = (t_map_info *)param;
	delete_all_textures(info);
	mlx_close_window(info->mlx);
	exit(0);
}

void	do_smth(t_map_info *info, int x, int y)
{
	mlx_delete_image(info->mlx, info->img1);
	info->x = x;
	info->y = y;
	info->img1 = mlx_texture_to_image(info->mlx, info->player);
	mlx_image_to_window(info->mlx, info->img1, info->y * 90, info->x * 90);
}
