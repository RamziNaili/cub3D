/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:24:38 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/25 16:02:04 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert_to_hexa(unsigned int nbr)
{
	int		tab[12];
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nbr == 0)
		ft_putchar('0');
	while (nbr)
	{
		tab[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	while (i--)
		ft_putchar(tab[i]);
}

int		ft_hexa(unsigned int nbr, t_flags stru, int printed_car)
{
	int		sign;

	sign = 0;
	if (stru.point == 0 && nbr == 0)
		return (ft_print(' ', stru.chifre));
	stru.zero = stru.point >= 0 ? ' ' : stru.zero;
	stru.point = stru.point < ft_hexa_len(nbr) ? ft_hexa_len(nbr) : stru.point;
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
	printed_car += ft_print('0', stru.point - ft_hexa_len(nbr));
	ft_convert_to_hexa(nbr);
	printed_car += ft_hexa_len(nbr);
	if (stru.moins == 1)
		printed_car += ft_print(' ', (stru.chifre - stru.point));
	return (printed_car);
}
