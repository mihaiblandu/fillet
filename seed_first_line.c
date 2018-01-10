/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seed_first_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 17:09:02 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/26 18:49:22 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	middle(t_array *test_arr, size_t *link_nmb, size_t j, size_t i)
{
	if (test_arr->space[j][i - 1] == '0')
		return ;
	if (test_arr->space[j][i - 1] == 'x')
	{
		*link_nmb = 100;
		return ;
	}
	if (test_arr->space[j][i - 1] == '.')
		*link_nmb = *link_nmb + 1;
	if (test_arr->space[j][i + 1] == '.')
	{
		*link_nmb = *link_nmb + 1;
		if (*link_nmb >= 5)
			return ;
		seed_this_space(test_arr, link_nmb, j, i + 1);
	}
	if (*link_nmb < 5 && test_arr->space[j + 1][i] == '.')
	{
		*link_nmb = *link_nmb + 1;
		if (*link_nmb < 5)
			seed_center(test_arr, link_nmb, j + 1, i);
	}
}

static void	last_one(t_array *test_arr, size_t *link_nmb, size_t j, size_t i)
{
	if (test_arr->space[j][i - 1] == '0')
		return ;
	if (test_arr->space[j][i - 1] == 'x')
	{
		*link_nmb = 100;
		return ;
	}
	if (test_arr->space[j][i - 1] == '.')
		*link_nmb = *link_nmb + 1;
	if (test_arr->space[j + 1][i] == '.')
	{
		*link_nmb = *link_nmb + 1;
		if (*link_nmb < 5)
			seed_this_space(test_arr, link_nmb, j + 1, i);
	}
}

void		seed_first_line(t_array *test_arr, size_t *link_nmb, size_t j,
													size_t i)
{
	if (i == 0)
	{
		if (test_arr->space[j][1] == '.')
		{
			*link_nmb = *link_nmb + 1;
			middle(test_arr, link_nmb, j, i + 1);
		}
		if (*link_nmb < 5 && test_arr->space[j + 1][0] == '.')
		{
			*link_nmb = *link_nmb + 1;
			seed_this_space(test_arr, link_nmb, j + 1, i);
		}
	}
	else if (i != 0 && i != test_arr->size - 1)
		middle(test_arr, link_nmb, j, i);
	else if (i == test_arr->size - 1)
		last_one(test_arr, link_nmb, j, i);
}
