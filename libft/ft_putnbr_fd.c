/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:14:10 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/16 17:23:50 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int sign;
	int buf[10];
	int i;

	i = 0;
	sign = 1;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	while (n != 0)
	{
		buf[i] = n % 10 * sign;
		n /= 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(buf[i] + '0', fd);
}
