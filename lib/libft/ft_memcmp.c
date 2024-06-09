/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:35:47 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/02 18:35:50 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*block1;
	unsigned char	*block2;

	i = 0;
	block1 = (unsigned char *)s1;
	block2 = (unsigned char *)s2;
	while (i < n)
	{
		if (block1[i] == block2[i])
			i++;
		else
			return (block1[i] - block2[i]);
	}
	return (0);
}
