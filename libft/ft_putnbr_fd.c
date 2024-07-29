/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:06:59 by ramzi             #+#    #+#             */
/*   Updated: 2020/11/19 11:01:12 by ranaili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int tab[12];
	int i;

	i = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n != -2147483648)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		while (n)
		{
			tab[i] = n % 10;
			n /= 10;
			i++;
		}
		while (i--)
			ft_putchar_fd(tab[i] + 48, fd);
	}
	else
		write(fd, "-2147483648", 11);
}
