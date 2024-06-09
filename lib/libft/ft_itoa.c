/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:36:52 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/02 17:42:38 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_convert(long number, char *str, size_t count_digits)
{
	str = (char *)ft_calloc(count_digits + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (number == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (number < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	count_digits--;
	while (number != 0)
	{
		str[count_digits] = (number % 10) + '0';
		number /= 10;
		count_digits--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	count_digits;
	char	*string;
	long	number;

	number = (long)n;
	str = NULL;
	count_digits = ft_count_digits(n);
	if (count_digits == 0)
		return (NULL);
	string = ft_convert(number, str, count_digits);
	if (string == NULL)
		return (NULL);
	return (string);
}
