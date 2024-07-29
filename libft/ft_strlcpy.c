/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:07:58 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/18 21:56:15 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = 0;
	if (!dst || !src)
		return (0);
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (i != size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i == size)
		dst[size - 1] = '\0';
	else
		dst[i] = '\0';
	return (len);
}
