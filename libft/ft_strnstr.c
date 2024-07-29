/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:08:40 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/19 11:05:14 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(char *fullstring, char *substring, int n)
{
	int i;
	int y;
	int len;

	i = 0;
	len = 0;
	if (substring[0] == '\0')
		return (fullstring);
	len = ft_strlen(substring);
	while (fullstring[i] && i < n)
	{
		y = 0;
		if (fullstring[i] == substring[y])
		{
			while (fullstring[i] == substring[y] && fullstring[i] && i < n)
			{
				i++;
				y++;
			}
			if (y == len)
				return (fullstring + (i - y));
		}
		i++;
	}
	return (len == 0 ? fullstring : NULL);
}
