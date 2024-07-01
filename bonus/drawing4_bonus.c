/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing4_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:35:36 by noben-ai          #+#    #+#             */
/*   Updated: 2024/07/01 17:52:54 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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

void	print_moves(t_map_info *info, int c)
{
	const char	*str;

	str = ft_itoa(c);
	check_img(info, info->img2, 0, 0);
	mlx_put_string(info->mlx, "moves: ", 0, 0);
	mlx_put_string(info->mlx, str, 60, 0);
	free(str);
}
