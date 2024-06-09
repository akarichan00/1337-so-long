/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:27:38 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/01 17:28:11 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*dup;

	i = 0;
	dup = (unsigned char *)s;
	while (i < len)
	{
		dup[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
