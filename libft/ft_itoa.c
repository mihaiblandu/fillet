/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:09:19 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/03 13:41:24 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*create_array(int sign, int i)
{
	char	*array;

	if (sign == -1)
		i++;
	array = malloc(i * sizeof(char) + 1);
	if (!(array))
		return (NULL);
	if (sign == -1)
		array[0] = '-';
	return (array);
}

static void	set_array(int n, int sign, int *i, int *b)
{
	while (n != 0)
	{
		b[*i] = n % 10 * sign;
		n = n / 10;
		*i = *i + 1;
	}
}

char		*ft_itoa(int n)
{
	int		buf[10];
	int		i;
	int		sign;
	char	*new;
	int		j;

	j = 0;
	i = 0;
	sign = 1;
	if (n == 0)
		buf[i++] = 0;
	if (n < 0)
		sign = -1;
	set_array(n, sign, &i, &buf[0]);
	new = create_array(sign, i);
	if (!(new))
		return (NULL);
	if (sign == -1)
		j++;
	while (--i >= 0)
		new[j++] = buf[i] + '0';
	new[j] = '\0';
	return (new);
}
