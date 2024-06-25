/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:38:27 by noben-ai          #+#    #+#             */
/*   Updated: 2024/06/25 10:09:56 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void check_for_leaks(void)
{
	system("leaks so_long");
}

//check errors in map
int parse_map(char *av, t_data *data)
{
	int x;
	int y;

	int len = ft_strlen(av);
	if (len > 4 && ft_strncmp(av + len - 4, ".ber", 4) == 0)
	{
		int fd = open(av, O_RDONLY);
		// check if the file is readable and was opened successfully
		if (fd == -1)
			return (perror("Error\n"), 0);
		// append the map in a string line by line
		data->map = read_map(fd);
		if (!data->map || !is_map_valid(data) || !check_walls(data->map))
			return (ft_printf("Error\ninvalid map!\n"), 0);
	}			
	else
		return (ft_printf("Error\ninvalid extension for map\n"), 0);	
	x = 0;
	y = 0;
	if (!check_valid_path(data, &x, &y))
		return (ft_printf("Error\ninvalid path!\n"), 0);
	return (1);
}

int main(int ac, char **av)
{	
	t_data data;
	atexit(check_for_leaks);
	
	if (ac == 2)
	{
		if (!parse_map(av[1], &data))
			return (0);
		ft_printf("valid map 🤓\n");
		// printf("%s", data.map);
	}
	else
		ft_printf("Error\nInvalid number of arguments :(\n");
	// free(data.map);
}

