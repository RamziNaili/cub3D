/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranaili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:18:48 by ranaili           #+#    #+#             */
/*   Updated: 2021/02/25 16:04:38 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_moins(t_flags *stru)
{
	stru->moins = 1;
	stru->zero = ' ';
}

void	ft_point(t_flags *stru, char *str, int *i, va_list ap)
{
	(*i)++;
	if (str[*i] == '*')
		stru->point = va_arg(ap, int);
	else if (str[*i] >= '0' && str[*i] <= '9')
	{
		stru->point = 0;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			stru->point *= 10;
			stru->point += str[*i] - 48;
			(*i)++;
		}
		(*i)--;
	}
	else
	{
		stru->point = 0;
		(*i)--;
	}
}

void	ft_star(t_flags *stru, va_list ap)
{
	int c;

	c = va_arg(ap, int);
	if (c < 0)
	{
		ft_moins(stru);
		c = -c;
	}
	stru->chifre = c;
}

void	ft_fill_struct(t_flags *stru, char *str, int *i, va_list ap)
{
	ft_initialize_stru(stru);
	while (ft_stop(str[*i]))
	{
		if (str[(*i) + 1] == '\0')
			return ;
		if (str[*i] == '-')
			ft_moins(stru);
		else if (str[*i] == '0' && stru->moins == 0)
			stru->zero = '0';
		else if (str[*i] == '.')
			ft_point(stru, str, i, ap);
		else if (str[*i] == '*')
			ft_star(stru, ap);
		else if (str[(*i)] >= '0' && str[(*i)] <= '9')
		{
			stru->chifre = 0;
			while (str[*i] >= '0' && str[*i] <= '9')
			{
				stru->chifre *= 10;
				stru->chifre += str[(*i)++] - 48;
			}
			(*i) -= str[(*i) - 1] >= '0' && str[(*i) - 1] <= '9' ? 1 : 0;
		}
		(*i)++;
	}
}
