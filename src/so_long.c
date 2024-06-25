/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:38:27 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/25 15:22:08 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_for_leaks(void)
{
	system("leaks so_long");
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
			return (ft_printf("Error\ninvalid map!\n"), 0);
	}
	else
		return (ft_printf("Error\ninvalid extension for map\n"), 0);
	if (!check_valid_path(data, info))
		return (ft_printf("Error\ninvalid path!\n"), 0);
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
		ft_printf("valid map 🤓\n");
	}
	else
		ft_printf("Error\nInvalid number of arguments :(\n");
}
