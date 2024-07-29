/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:22:13 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/25 16:06:03 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hexa_len(unsigned int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int		ft_stop(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'u' || c == '\0')
		return (0);
	if (c == 'x' || c == 'X' || c == '%' || c == 'p' || c == 'c')
		return (0);
	return (1);
}

void	ft_initialize_stru(t_flags *stru)
{
	stru->moins = 0;
	stru->point = -1;
	stru->chifre = 0;
	stru->zero = ' ';
}

int ft_types(char c, void *ap, t_flags stru)
{
    int v = 0;
    
    if (c == 's')
        v = ft_string((char *)ap, stru);
    else if (c == 'c')
        v = ft_caracter(*(char *)ap, stru); 
    else if (c == 'd' || c == 'i')
        v = ft_digit(*(int *)ap, stru, 0); 
    else if (c == '%')
        v = ft_percent(stru);
    else if (c == 'u')
        v = ft_unsigned(*(unsigned int *)ap, stru, 0); 
    else if (c == 'x')
        v = ft_hexa(*(int *)ap, stru, 0); 
    else if (c == 'X')
        v = ft_hexadecimal(*(int *)ap, stru, 0); 
    else if (c == 'p')
        v = ft_pointeur(*(unsigned long long *)ap, stru); 
    
    return v;
}