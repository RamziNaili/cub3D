/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointeur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:35:15 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/25 16:05:18 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_adress(unsigned long long a)
{
	int			tab[18];
	int			i;
	char		*base;

	i = 0;
	base = "0123456789abcdef";
	if (a == 0)
		write(1, "0", 1);
	else
	{
		while (a)
		{
			tab[i] = base[a % 16];
			a /= 16;
			i++;
		}
		while (i--)
			ft_putchar(tab[i]);
	}
}

int		ft_adress_len(unsigned long long a)
{
	int			tab[18];
	int			i;
	char		*base;
	int			res;

	i = 0;
	res = 2;
	base = "0123456789abcdef";
	if (a == 0)
		return (3);
	else
	{
		while (a)
		{
			tab[i] = base[a % 16];
			a /= 16;
			i++;
		}
		while (i--)
			res++;
	}
	return (res);
}

int		ft_null(t_flags stru, unsigned long long a)
{
	int		printed_car;

	printed_car = 0;
	if (stru.point == 0)
	{
		stru.point = 2;
		return (ft_string("0x", stru));
	}
	else if (stru.chifre > 0)
		return (ft_string("0x0", stru));
	write(1, "0x", 2);
	if (stru.moins == 0)
		printed_car += ft_print('0', stru.point - ft_adress_len(a) + 2);
	ft_print_adress(a);
	printed_car += ft_adress_len(a);
	if (stru.moins == 1)
		printed_car += ft_print(' ', stru.chifre - stru.point);
	return (printed_car);
}

int		ft_pointeur(unsigned long long a, t_flags stru)
{
	int		printed_car;

	printed_car = 0;
	if (a == 0)
		return (ft_null(stru, a));
	stru.zero = stru.point >= 0 ? ' ' : stru.zero;
	stru.point = stru.point < ft_adress_len(a) ? ft_adress_len(a) : stru.point;
	stru.point += stru.point > ft_adress_len(a) ? 2 : 0;
	if (a < 0 && stru.zero == '0')
		write(1, "0x", 2);
	if (stru.moins == 0)
		printed_car += ft_print(stru.zero, (stru.chifre - stru.point));
	if (a > 0)
		write(1, "0x", 2);
	printed_car += ft_print('0', stru.point - ft_adress_len(a));
	ft_print_adress(a);
	printed_car += ft_adress_len(a);
	if (stru.moins == 1)
		printed_car += ft_print(' ', (stru.chifre - stru.point));
	return (printed_car);
}
