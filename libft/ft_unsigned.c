/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:40:40 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/25 16:06:42 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_unsigned_nbr(unsigned int nbr)
{
	int tab[12];
	int i;

	i = 0;
	if (nbr == 0)
		ft_putchar('0');
	while (nbr)
	{
		tab[i] = nbr % 10;
		nbr /= 10;
		i++;
	}
	while (i--)
	{
		ft_putchar(tab[i] + 48);
	}
}

int		ft_un_len(unsigned int nbr)
{
	unsigned int i;
	unsigned int nb;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i++;
		nb = -nbr;
	}
	else
		nb = nbr;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int		ft_unsigned(unsigned int nbr, t_flags stru, int printed_car)
{
	int		sign;

	sign = 0;
	if (stru.point == 0 && nbr == 0)
		return (ft_print(' ', stru.chifre));
	stru.zero = stru.point >= 0 ? ' ' : stru.zero;
	stru.point = stru.point < ft_un_len(nbr) ? ft_un_len(nbr) : stru.point;
	if (nbr < 0)
	{
		printed_car++;
		stru.chifre--;
	}
	if (nbr < 0 && stru.zero == '0')
		ft_norm(&sign);
	if (stru.moins == 0)
		printed_car += ft_print(stru.zero, (stru.chifre - stru.point));
	if (nbr < 0 && sign == 0)
		ft_putchar('-');
	printed_car += ft_print('0', stru.point - ft_un_len(nbr));
	ft_put_unsigned_nbr(nbr);
	printed_car += ft_un_len(nbr);
	if (stru.moins == 1)
		printed_car += ft_print(' ', (stru.chifre - stru.point));
	return (printed_car);
}
