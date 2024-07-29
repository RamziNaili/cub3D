/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:07:16 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/25 16:01:51 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nb_len(int nb)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr(int nbr)
{
	int tab[10];
	int i;

	i = 0;
	if (nbr == 0)
		ft_putchar('0');
	if (nbr != -2147483648)
	{
		if (nbr < 0)
			nbr = -nbr;
		while (nbr)
		{
			tab[i] = nbr % 10;
			nbr /= 10;
			i++;
		}
		while (i--)
			ft_putchar(tab[i] + 48);
	}
	else
		write(1, "2147483648", 10);
}

void	ft_norm(int *sign)
{
	ft_putchar('-');
	*sign = 1;
}

int		ft_digit(int nbr, t_flags stru, int printed_car)
{
	int		sign;

	sign = 0;
	if (stru.point == 0 && nbr == 0)
		return (ft_print(' ', stru.chifre));
	stru.zero = stru.point >= 0 ? ' ' : stru.zero;
	stru.point = stru.point < ft_nb_len(nbr) ? ft_nb_len(nbr) : stru.point;
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
	printed_car += ft_print('0', stru.point - ft_nb_len(nbr));
	ft_putnbr(nbr);
	printed_car += ft_nb_len(nbr);
	if (stru.moins == 1)
		printed_car += ft_print(' ', (stru.chifre - stru.point));
	return (printed_car);
}
