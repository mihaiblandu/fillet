/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:22:09 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/03 12:23:56 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_arr_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*my_array;

	i = 0;
	my_array = malloc(sizeof(int) * length);
	while (i < length)
	{
		my_array[i] = f(tab[i]);
		i++;
	}
	return (my_array);
}
