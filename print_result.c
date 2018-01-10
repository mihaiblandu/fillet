/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:58:24 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/23 18:00:20 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

void	print_result(t_array *final_array)
{
	size_t	back;

	back = final_array->j;
	final_array->j = 0;
	while (final_array->j < final_array->size)
	{
		ft_putstr(final_array->space[final_array->j]);
		ft_putchar('\n');
		final_array->j++;
	}
	final_array->j = back;
}
