/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:34:59 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/25 16:04:55 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_percent(t_flags stru)
{
	int printed_car;

	printed_car = 0;
	if (stru.moins == 0)
		printed_car += ft_print(stru.zero, (stru.chifre - 1));
	ft_putchar('%');
	printed_car++;
	if (stru.moins == 1)
		printed_car += ft_print(' ', (stru.chifre - 1));
	return (printed_car);
}
