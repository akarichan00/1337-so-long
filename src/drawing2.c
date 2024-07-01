/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:52:10 by noben-ai          #+#    #+#             */
/*   Updated: 2024/07/01 11:32:05 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_boundaries(t_map_info *info)
{
	if (info->a > 16 || info->b > 29)
	{
		free_it_all(info);
		return (0);
	}
	return (1);
}

int	draw(t_map_info *info)
{
	info->mlx = mlx_init(info->b * 90, info->a * 90, "./so_long", false);
	if (!info->mlx)
	{
		free_it_all(info);
		return (ft_printf("Error\ncan't open the window!\n"), 0);
	}
	if (!load_images(info))
	{
		free_it_all(info);
		return (ft_printf("Error\ncan't load images!\n"), 0);
	}
	if (!t_to_image(info))
	{
		free_it_all(info);
		return (ft_printf("Error\ncan't convert texture to image!\n"), 0);
	}
	display_images(info);
	mlx_key_hook(info->mlx, key_press, info);
	mlx_close_hook(info->mlx, close_game, info);
	mlx_loop(info->mlx);
	mlx_terminate(info->mlx);
	return (1);
}
