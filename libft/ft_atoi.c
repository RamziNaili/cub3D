/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:55:12 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/19 10:53:11 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_digit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

static int		ft_is_space(char c)
{
	if (c == '\n' || c == '\f' || c == '\r')
		return (1);
	if (c == '\t' || c == ' ' || c == '\v')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_is_digit(str[i]))
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (neg == -1 ? -res : res);
}
