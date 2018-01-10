/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:24:42 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/15 18:51:47 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	sign;
	int	buf[10];
	int	i;

	i = 0;
	sign = 1;
	if (n == 0)
		ft_putchar('0');
	else if (n < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	while (n != 0)
	{
		buf[i] = n % 10 * sign;
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(buf[i] + '0');
}
