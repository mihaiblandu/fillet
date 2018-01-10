/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_this_tetrimino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:46:18 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/22 15:18:55 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_this_tetrimino(t_array *test_array, int letter, t_tetr_list *trmo)
{
	size_t	back_i;

	back_i = test_array->i;
	trmo->i = 0;
	trmo->j = 0;
	while (trmo->j < trmo->size)
	{
		while (trmo->space[trmo->j][trmo->i] != '\0')
		{
			if (trmo->space[trmo->j][trmo->i] == letter)
				test_array->space[test_array->j][test_array->i] =
					trmo->space[trmo->j][trmo->i];
			trmo->i++;
			test_array->i++;
		}
		trmo->i = 0;
		trmo->j++;
		test_array->i = back_i;
		test_array->j++;
	}
	test_array->i = 0;
	trmo->j = 0;
	test_array->j = 0;
}
