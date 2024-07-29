/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:55:40 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/17 18:18:30 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = malloc(size * count)))
		return (NULL);
	while (i < count * size)
	{
		str[i] = '\0';
		i++;
	}
	str = (void *)str;
	return (str);
}
