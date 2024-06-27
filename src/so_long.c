/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:38:27 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/27 16:58:25 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void test_leaks(void)
{
	system("leaks so_long");
}
void	free_it_all(t_map_info *info, t_data *data)
{
	free(data->map);
	free_words(info->map, info->free_index);
	free_words(info->original_map, info->free_index);
}

int	parse_map(char *av, t_data *data, t_map_info *info)
{
	int	len;
	int	fd;

	len = ft_strlen(av);
	if (len > 4 && ft_strncmp(av + len - 4, ".ber", 4) == 0)
	{
		fd = open(av, O_RDONLY);
		if (fd == -1)
			return (perror("Error\n"), 0);
		data->map = read_map(fd);
		if (!data->map || !is_map_valid(data) || !check_walls(data->map))
			return (ft_printf("Error\ninvalid map!\n"), free(data->map), 0);
	}
	else
		return (ft_printf("Error\ninvalid extension for map\n"), 0);
	(void)info;
	if (!check_valid_path(data, info))
		return (ft_printf("Error\ninvalid path!\n"), free_it_all(info, data),
			0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_map_info	info;
	
	// atexit(test_leaks);
	info.x = 0;
	info.y = 0;
	if (ac == 2)
	{
		if (!parse_map(av[1], &data, &info))
			return (0);
		info.data = &data;
		ft_printf("valid map 🤓\n");
		
		// check if map can be displayed within the mac's resolution :D
		if(check_boundaries(&info, &data) == 0)
			return (ft_printf("Error\nwa tga3ad a regragi!\n"), 0);
		
		// reserve how many pixels will be in the window
		info.mlx = mlx_init(info.b * 90, info.a * 90, "so long", false); // false to indicate that u cannot expand the window :D
		if (!info.mlx)
			return(ft_printf("Error\ncan't open the window!\n"),0);

		// load images 
		if (!load_images(&info))
			return(ft_printf("Error\ncan't load images!\n"),0);
		
		// Convert texture to a displayable image
		if (!t_to_image(&info))
			return(ft_printf("Error\ncan't convert texture to image!\n"),0);
		
		// display images
		display_images(&info);
		
		
		// exit if ESC is pressed 
		mlx_key_hook(info.mlx, key_press, &info);
		// printf("here\n");
		mlx_loop(info.mlx);
		mlx_terminate(info.mlx);
	}
	else
		ft_printf("Error\nInvalid number of arguments :(\n");
	free_it_all(&info, &data);
	return (1);
}
