/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:37:46 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/14 19:51:36 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	check_first_line(t_array *temp_array, int i, int j, int *link_nmb)
{
	if (i == 0)
	{
		if (temp_array->space[j][1] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j + 1][0] == '#')
			*link_nmb = *link_nmb + 1;
	}
	else if (i != 0 && i != 3)
	{
		if (temp_array->space[j][i - 1] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j][i + 1] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j + 1][i] == '#')
			*link_nmb = *link_nmb + 1;
	}
	else if (i == 3)
	{
		if (temp_array->space[j][2] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j + 1][3] == '#')
			*link_nmb = *link_nmb + 1;
	}
}

static void	check_last_line(t_array *temp_array, int i, int j, int *link_nmb)
{
	if (i == 0)
	{
		if (temp_array->space[j - 1][0] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j][1] == '#')
			*link_nmb = *link_nmb + 1;
	}
	else if (i != 0 && i != 3)
	{
		if (temp_array->space[j - 1][i] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j][i - 1] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j][i + 1] == '#')
			*link_nmb = *link_nmb + 1;
	}
	else if (i == 3)
	{
		if (temp_array->space[j - 1][3] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j][2] == '#')
			*link_nmb = *link_nmb + 1;
	}
}

static void	check_center(t_array *temp_array, int i, int j, int *link_nmb)
{
	if (temp_array->space[j][i - 1] == '#')
		*link_nmb = *link_nmb + 1;
	if (temp_array->space[j][i + 1] == '#')
		*link_nmb = *link_nmb + 1;
	if (temp_array->space[j - 1][i] == '#')
		*link_nmb = *link_nmb + 1;
	if (temp_array->space[j + 1][i] == '#')
		*link_nmb = *link_nmb + 1;
}

void		check_links(t_array *temp_array, int *link_nmb, int i, int j)
{
	if (j % 4 == 0)
		check_first_line(temp_array, i, j, link_nmb);
	else if (j % 4 == 3)
		check_last_line(temp_array, i, j, link_nmb);
	else if (i == 0 && j % 4 != 0 && j % 4 != 3)
	{
		if (temp_array->space[j - 1][0] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j + 1][0] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j][1] == '#')
			*link_nmb = *link_nmb + 1;
	}
	else if (j % 4 != 0 && j % 4 != 3 && i != 0 && i != 3)
		check_center(temp_array, i, j, link_nmb);
	else if (j % 4 != 0 && j % 4 != 3 && i == 3)
	{
		if (temp_array->space[j][2] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j - 1][3] == '#')
			*link_nmb = *link_nmb + 1;
		if (temp_array->space[j + 1][3] == '#')
			*link_nmb = *link_nmb + 1;
	}
}
