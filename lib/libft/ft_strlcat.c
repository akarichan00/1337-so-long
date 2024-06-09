/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:11:49 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/02 18:30:28 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	lendest;
	size_t	lensrc;
	size_t	k;

	if (dest == NULL || src == NULL)
		return (0);
	i = 0;
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	k = lendest;
	if (size == 0 || size <= lendest)
		return (lensrc + size);
	while (src[i] != '\0' && i < size - lendest - 1)
	{
		dest[k] = src[i];
		i++;
		k++;
	}
	dest[k] = '\0';
	return (lendest + lensrc);
}
