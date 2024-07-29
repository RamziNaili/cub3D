/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:58:01 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/19 11:00:32 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenofstring(int nb)
{
	int				i;
	unsigned int	num;

	i = nb < 0 ? 1 : 0;
	num = nb < 0 ? -nb : nb;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int				i;
	char			*res;
	unsigned int	nb;

	i = ft_lenofstring(n);
	nb = n < 0 ? -n : n;
	if (n == 0)
	{
		if (!(res = malloc(sizeof(char) * 2)))
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	if (!(res = malloc(sizeof(char) * ft_lenofstring(n) + 1)))
		return (NULL);
	res[i--] = '\0';
	while (nb)
	{
		res[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	res[i] = n < 0 ? '-' : res[i];
	return (res);
}
