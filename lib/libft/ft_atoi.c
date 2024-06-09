/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:37:00 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/11 11:58:36 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	integer;
	int					i;

	i = 0;
	sign = 1;
	integer = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		integer = integer * 10 + (str[i++] - '0');
		if (integer > 9223372036854775807 && sign == 1)
			return (-1);
		if (integer > 9223372036854775807 && sign == -1)
			return (0);
	}
	return (sign * integer);
}
