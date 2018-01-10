/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_this_tetrimino.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:01:56 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/21 19:23:34 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_this_tetrimino(t_array *test_array, t_tetr_list *tetrimino,
								int letter)
{
	size_t	back_i;

	back_i = test_array->i;
	while (tetrimino->j < tetrimino->size)
	{
		while (tetrimino->space[tetrimino->j][tetrimino->i] != '\0')
		{
			if (tetrimino->space[tetrimino->j][tetrimino->i] == letter)
				test_array->space[test_array->j][test_array->i] = '.';
			test_array->i++;
			tetrimino->i++;
		}
		tetrimino->i = 0;
		tetrimino->j++;
		test_array->j++;
		test_array->i = back_i;
	}
	tetrimino->j = 0;
	test_array->i = back_i + 1;
	test_array->j = test_array->j - tetrimino->size;
}
