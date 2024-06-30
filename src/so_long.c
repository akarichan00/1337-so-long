/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:38:27 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/30 11:07:24 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_it_all(t_map_info *info)
{
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
		close(fd);
		if (!data->map || !is_map_valid(data) || !check_walls(data->map))
			return (ft_printf("Error\ninvalid map!\n"), free(data->map), 0);
	}
	else
		return (ft_printf("Error\ninvalid extension for map\n"), 0);
	if (!check_valid_path(data, info))
		return (ft_printf("Error\ninvalid path!\n"), free_it_all(info),
			free(data->map), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_map_info	info;

	info.x = 0;
	info.y = 0;
	if (ac == 2)
	{
		if (!parse_map(av[1], &data, &info))
			return (0);
		info.data = &data;
		free(data.map);
		free_words(info.map, info.free_index);
		if (check_boundaries(&info) == 0)
			return (ft_printf("Error\nmap is too big \n"), 0);
		if (!draw(&info))
			return (0);
	}
	else
		ft_printf("Error\nInvalid number of arguments :(\n");
	free_it_all(&info);
	return (1);
}
