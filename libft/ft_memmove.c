/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:59:59 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/15 16:00:01 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	unsigned int	i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (size == 0 || destination == source)
		return (destination);
	if (dst > src)
	{
		i = size;
		while (i-- > 0)
			dst[i] = src[i];
	}
	else
	{
		i = 0;
		while (i < size)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (destination);
}
