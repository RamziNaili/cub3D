/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:39:44 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/25 16:06:19 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_len(char *str, int nb)
{
	int i;

	i = 0;
	while (str[i] && i < nb)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_string(char *str, t_flags stru)
{
	int		printed_car;

	printed_car = 0;
	if (str == NULL)
		str = "(null)";
	stru.point = stru.point < 0 ? ft_strlen(str) : stru.point;
	stru.point = stru.point > ft_strlen(str) ? ft_strlen(str) : stru.point;
	if (stru.moins == 0)
		printed_car += ft_print(stru.zero, (stru.chifre - stru.point));
	ft_putstr_len(str, stru.point);
	printed_car += stru.point;
	if (stru.moins == 1)
		printed_car += ft_print(' ', (stru.chifre - stru.point));
	return (printed_car);
}
