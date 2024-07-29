/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:59:47 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/15 15:59:49 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *destination;
	char *source;

	if (n == 0 || dst == src)
		return (dst);
	destination = (char *)dst;
	source = (char *)src;
	while (n--)
		*destination++ = *source++;
	return (dst);
}
