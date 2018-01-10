/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seed_this_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:51:24 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/26 18:29:57 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		check_first_column(t_array *test_arr, size_t *link_nmb, size_t j,
																	size_t i)
{
	if (test_arr->space[j - 1][0] == 'x')
	{
		*link_nmb = 100;
		return ;
	}
	if (test_arr->space[j - 1][0] == '0')
		return ;
	if (test_arr->space[j - 1][0] == '.')
		*link_nmb = *link_nmb + 1;
	if (test_arr->space[j][1] == '.')
	{
		*link_nmb = *link_nmb + 1;
		if (*link_nmb < 5 && test_arr->space[j - 1][1] != '.')
			seed_center(test_arr, link_nmb, j, 1);
	}
	if (*link_nmb < 5 && test_arr->space[j + 1][0] == '.')
	{
		*link_nmb = *link_nmb + 1;
		if (*link_nmb < 5)
			seed_this_space(test_arr, link_nmb, j + 1, i);
	}
}

void		check_last_column(t_array *test_arr, size_t *link_nmb, size_t j,
																size_t i)
{
	if (test_arr->space[j][i - 1] == 'x' || test_arr->space[j - 1][i] == 'x')
	{
		*link_nmb = 100;
		return ;
	}
	if (test_arr->space[j][i - 1] == '0' || test_arr->space[j - 1][i] == '0')
		return ;
	if (test_arr->space[j][i - 1] == '.')
	{
		*link_nmb = *link_nmb + 1;
		if (*link_nmb >= 5)
			return ;
		if (test_arr->space[j - 1][i] == '.')
			seed_center(test_arr, link_nmb, j, i - 1);
	}
	if (test_arr->space[j - 1][i] == '.')
		*link_nmb = *link_nmb + 1;
	if (*link_nmb < 5 && test_arr->space[j + 1][i] == '.')
	{
		*link_nmb = *link_nmb + 1;
		if (*link_nmb < 5)
			seed_this_space(test_arr, link_nmb, j + 1, i);
	}
}

void		seed_this_space(t_array *test_arr, size_t *link_nmb, size_t j,
															size_t i)
{
	if (j == 0)
		seed_first_line(test_arr, link_nmb, j, i);
	else if (j == test_arr->size - 1)
		seed_last_line(test_arr, link_nmb, j, i);
	else if (i == 0 && j != 0 && j != test_arr->size - 1)
		check_first_column(test_arr, link_nmb, j, i);
	else if (j != 0 && j != test_arr->size - 1
		&& i != 0 && i != test_arr->size - 1)
		seed_center(test_arr, link_nmb, j, i);
	else if (j != 0 && j != test_arr->size - 1
		&& i == test_arr->size - 1)
		check_last_column(test_arr, link_nmb, j, i);
}
