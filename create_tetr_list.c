/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetr_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:39:02 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/25 13:47:19 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static void			build_one_row(t_array *array, t_tetr_list *ttrm,
					int letter, int start_ind)
{
	while (array->space[array->j][array->i] == '#')
	{
		while (ttrm->i < array->i - start_ind)
			ttrm->space[ttrm->j][ttrm->i++] = '.';
		ttrm->space[ttrm->j][ttrm->i] = letter;
		ttrm->i++;
		array->i++;
	}
	if (ttrm->i > ttrm->max_length)
		ttrm->max_length = ttrm->i;
	ttrm->space[ttrm->j][ttrm->i] = '\0';
	ttrm->i = 0;
	array->i = 4;
	ttrm->j++;
	ttrm->size++;
}

static t_tetr_list	*add_tetr_node(t_tetr_list *node)
{
	node = malloc(sizeof(t_tetr_list));
	if (!(node))
		error();
	node->size = 0;
	node->next = NULL;
	node->i = 0;
	node->max_length = 0;
	node->index = 0;
	node->j = 0;
	node->space = malloc(sizeof(char*) * 5);
	if (!(node->space))
		exit(-1);
	return (node);
}

static void			save_this_tetr(t_array *temp_array,
					t_tetr_list *ttrm_ind, int letter, int start_ind)
{
	size_t		k;

	k = temp_array->j + 4;
	while (temp_array->j < k)
	{
		while (temp_array->i < 4)
			if (temp_array->space[temp_array->j][temp_array->i] == '#')
			{
				ttrm_ind->space[ttrm_ind->j] = malloc(5);
				if (!(ttrm_ind->space))
					exit(-1);
				build_one_row(temp_array, ttrm_ind, letter, start_ind);
			}
			else
				temp_array->i++;
		temp_array->j++;
		temp_array->i = 0;
	}
}

static	void		update_values(t_tetr_list *a_tetrimino, int *index)
{
	a_tetrimino->j = 0;
	a_tetrimino->i = 0;
	a_tetrimino->index = *index;
	*index = *index + 1;
}

t_tetr_list			*cr_tetr_list(t_array *temp_array, size_t tetrinumber)
{
	int			letter;
	t_tetr_list	*ttrm;
	int			start_ind;
	t_tetr_list	*ttrm_ind;
	int			index;

	index = 1;
	letter = 65;
	ttrm = NULL;
	ttrm = add_tetr_node(ttrm);
	ttrm_ind = ttrm;
	while (temp_array->j < tetrinumber * 4)
	{
		if (temp_array->j != 0)
		{
			ttrm_ind->next = add_tetr_node(ttrm_ind->next);
			ttrm_ind = ttrm_ind->next;
		}
		start_ind = find_start(temp_array);
		save_this_tetr(temp_array, ttrm_ind, letter, start_ind);
		update_values(ttrm_ind, &index);
		letter++;
	}
	return (ttrm);
}
