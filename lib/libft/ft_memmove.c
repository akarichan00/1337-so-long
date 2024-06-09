/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:11:06 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/03 11:27:49 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	len;
	char	*d;
	char	*s;

	if (dest == src)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	len = n - 1;
	if (d > s)
	{
		while ((int)len >= 0)
		{
			d[len] = s[len];
			len--;
		}
	}
	else
		ft_memcpy(d, s, n);
	return (d);
}
