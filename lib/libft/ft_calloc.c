/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noben-ai <noben-ai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:41:46 by noben-ai          #+#    #+#             */
/*   Updated: 2024/01/09 11:55:57 by noben-ai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	char	*array;
	size_t	total_bytes;

	total_bytes = num_elements * element_size;
	if (element_size != 0 && total_bytes / element_size != num_elements)
		return (NULL);
	array = (char *)malloc(num_elements * element_size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, total_bytes);
	return (array);
}
