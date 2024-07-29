/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:38:12 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/25 16:05:38 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_var(int *i, int *res)
{
	*i = -1;
	*res = 0;
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list ap;
	t_flags stru;

	ft_init_var(&i, &res);
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i++])
		{
			ft_fill_struct(&stru, (char *)str, &i, ap);
			if (str[i] == '%')
				res += ft_types(str[i], "", stru);
			else
				res += ft_types(str[i], va_arg(ap, char *), stru);
		}
		else
		{
			ft_putchar(str[i]);
			res++;
		}
	}
	va_end(ap);
	return (res);
}
