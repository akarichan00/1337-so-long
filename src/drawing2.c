/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 07:52:10 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/29 16:38:00 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_boundaries(t_map_info *info)
{
	if (info->a > 16 || info->b > 29)
	{
		free_it_all(info);
		return (0);
	}
	return (1);
}

int  draw(t_map_info *info)
{
	// reserve how many pixels will be in the window
	info->mlx = mlx_init(info->b * 90, info->a * 90, "so long", false); // false to indicate that u cannot expand the window :D
	if (!info->mlx)
	{
		free_it_all(info);
		return(ft_printf("Error\ncan't open the window!\n"),0);
	}
	// load images 
	if (!load_images(info))
	{
		free_it_all(info);
		return(ft_printf("Error\ncan't load images!\n"),0);
	}
	// Convert texture to a displayable image
	if (!t_to_image(info))
	{
		free_it_all(info);
		return(ft_printf("Error\ncan't convert texture to image!\n"),0);
	} 
	// display images
	display_images(info);
	// // handle keys
	mlx_key_hook(info->mlx, key_press, info);
	mlx_close_hook(info->mlx, close_game, info);
	mlx_loop(info->mlx);
	mlx_terminate(info->mlx);	
	return (1);
}

