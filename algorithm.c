/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:21:44 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/24 18:30:35 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	initiate_array(t_array *an_array, char c)
{
	while (an_array->j < an_array->size)
	{
		an_array->space[an_array->j] = malloc(an_array->size + 1);
		if (!(an_array->space[an_array->j]))
			error();
		while (an_array->i < an_array->size)
		{
			an_array->space[an_array->j][an_array->i] = c;
			an_array->i++;
		}
		an_array->space[an_array->j][an_array->i] = '\0';
		an_array->j++;
		an_array->i = 0;
	}
	an_array->j = 0;
}

void	delete_array(t_array *to_delete)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (to_delete->space[to_delete->j] && to_delete->j < to_delete->size)
	{
		free(to_delete->space[j]);
		to_delete->space[j] = NULL;
		j++;
	}
	free(to_delete->space);
	to_delete->space = NULL;
	free(to_delete);
	to_delete = NULL;
}

void	algorithm(size_t min_size, t_tetr_list *tetr_list, size_t tetrinumber)
{
	t_array		*test_array;
	int			letter;
	int			state;

	letter = 65;
	test_array = NULL;
	test_array = create_array(test_array, min_size);
	initiate_array(test_array, '.');
	state = rec_tetrimino(letter, test_array, tetr_list, tetrinumber);
	while (state == -1)
	{
		min_size++;
		delete_array(test_array);
		test_array = create_array(test_array, min_size);
		initiate_array(test_array, '.');
		state = rec_tetrimino(letter, test_array, tetr_list, tetrinumber);
	}
}
