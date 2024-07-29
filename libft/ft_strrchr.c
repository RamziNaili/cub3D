/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:08:47 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/15 16:08:49 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedchar)
{
	int		i;
	int		res;
	char	*str;

	i = 0;
	res = 0;
	str = (char *)string;
	while (str[i])
	{
		if (str[i] == searchedchar)
			res = i;
		i++;
	}
	if (str[i] == searchedchar)
		return (str + i);
	if (str[res] == searchedchar || res > 0)
		return (str + res);
	return (NULL);
}
