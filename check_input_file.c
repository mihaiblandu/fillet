/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:18:06 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/24 20:06:30 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	how_many_links(t_array *temp_array, int *links)
{
	while (temp_array->i < 4)
	{
		if (temp_array->space[temp_array->j][temp_array->i] == '#')
			check_links(temp_array, links, temp_array->i, temp_array->j);
		temp_array->i++;
	}
	temp_array->j++;
	temp_array->i = 0;
}

static int	is_tetrimino(t_array *temp_array, size_t tetrinumber)
{
	size_t	k;
	int		links;

	links = 0;
	temp_array->i = 0;
	temp_array->j = 0;
	temp_array->j = 0;
	while (temp_array->j < tetrinumber * 4)
	{
		k = temp_array->j + 4;
		while (temp_array->j < k)
			how_many_links(temp_array, &links);
		if (links < 6)
			error();
		links = 0;
	}
	temp_array->j = 0;
	return (0);
}

void		check_input_file(char *file, size_t *tetrinumber,
										t_array *temp_array)
{
	basic_check(file, temp_array, tetrinumber);
	is_tetrimino(temp_array, *tetrinumber);
}
