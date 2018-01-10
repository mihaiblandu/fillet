/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:26:14 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/26 18:44:03 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static void	seed_or_not(t_array *test_array, t_tetr_list *a_tetrimino,
		size_t tetrinumber, int *state)
{
	if ((tetrinumber * 2 > test_array->size * test_array->size -
		tetrinumber * 4) && ((a_tetrimino->index >= (test_array->size *
		test_array->size - tetrinumber * 4) / 2 + 1)) && (a_tetrimino->index
					<= tetrinumber - 2))
		*state = can_it_work(test_array, tetrinumber);
}

static void	if_successfull(t_array *test_array, t_tetr_list *a_tetrimino)
{
	if (a_tetrimino->next == NULL)
	{
		print_result(test_array);
		exit(1);
	}
}

int			rec_tetrimino(int letter, t_array *test_array,
						t_tetr_list *a_tetrimino, size_t tetrinumber)
{
	int		is_space;
	size_t	last_space_j;
	size_t	last_space_i;
	int		state;

	is_space = -1;
	is_space = find_next_space(test_array, a_tetrimino, letter);
	while (is_space != -1)
	{
		state = 0;
		last_space_i = test_array->i;
		last_space_j = test_array->j;
		add_this_tetrimino(test_array, letter, a_tetrimino);
		if_successfull(test_array, a_tetrimino);
		seed_or_not(test_array, a_tetrimino, tetrinumber, &state);
		if (state == 1 || state == 0)
			rec_tetrimino(letter + 1, test_array, a_tetrimino->next,
					tetrinumber);
		test_array->j = last_space_j;
		test_array->i = last_space_i;
		clear_this_tetrimino(test_array, a_tetrimino, letter);
		is_space = find_next_space(test_array, a_tetrimino, letter);
	}
	return (-1);
}
