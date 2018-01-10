/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seed_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 17:13:08 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/26 18:55:02 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static void	if_prev(t_array *test_arr, size_t *link_nmb, size_t j, size_t i)
{
	*link_nmb = *link_nmb + 1;
	if (*link_nmb < 5 && test_arr->space[j - 1][i] == '.')
		seed_this_space(test_arr, link_nmb, j, i - 1);
}

void		seed_center(t_array *test_arr, size_t *link_nmb, size_t j,
													size_t i)
{
	if (test_arr->space[j][i - 1] == '0' || test_arr->space[j - 1][i] == '0')
		return ;
	if (test_arr->space[j][i - 1] == 'x' || test_arr->space[j - 1][i] == 'x')
	{
		*link_nmb = 100;
		return ;
	}
	if (test_arr->space[j][i - 1] == '.')
		if_prev(test_arr, link_nmb, j, i);
	if (test_arr->space[j - 1][i] == '.')
		*link_nmb = *link_nmb + 1;
	if (*link_nmb < 5 && test_arr->space[j][i + 1] == '.')
	{
		*link_nmb = *link_nmb + 1;
		if (*link_nmb < 5 && test_arr->space[j - 1][i + 1] != '.')
			seed_this_space(test_arr, link_nmb, j, i + 1);
	}
	if (*link_nmb < 5 && test_arr->space[j + 1][i] == '.')
	{
		*link_nmb = *link_nmb + 1;
		if (*link_nmb < 5)
			seed_this_space(test_arr, link_nmb, j + 1, i);
	}
}
