/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:21:48 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/26 17:58:19 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				sign;
	int				result;
	int				i;

	i = -1;
	result = 0;
	sign = 1;
	while ((*str == '\n' || *str == '\r' || *str == '\t' || *str == ' '
			|| *str == '0' || *str == '\v' || *str == '\b' || *str == '\f')
			&& *str)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str > 47 && *str < 58 && ++i < 20)
	{
		if (i > 18 && sign == 1)
			return (-1);
		else if (sign == -1 && i > 18)
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
