/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:07:27 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/15 16:07:28 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)str;
	while (res[i] != c && res[i])
		i++;
	if (res[i] == c)
		return (res + i);
	return (NULL);
}
