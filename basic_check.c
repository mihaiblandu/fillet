/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:44:34 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/24 20:05:17 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	update(size_t *tetrinumber, int *count_hashes,
										int *o, int *count_lines)
{
	*tetrinumber = *tetrinumber + 1;
	if (*count_hashes != 4)
		error();
	if (*tetrinumber > 26)
		error();
	*o = *o + 1;
	*count_hashes = 0;
	*count_lines = 0;
}

static void	initialize(int *o, int *count_hashes, int *count_lines)
{
	*o = 0;
	*count_hashes = 0;
	*count_lines = 0;
}

static void	is_newline(char *file, int *o)
{
	if (file[*o] != '\n')
		error();
	*o = *o + 1;
}

static int	check_endline(char *file, int *o)
{
	*o = *o - 1;
	if (file[*o] == '\0')
		return (-1);
	if (file[*o] != '\n')
		error();
	if (file[*o + 1] == '\0')
		error();
	*o = *o + 1;
	return (0);
}

void		basic_check(char *file, t_array *temp_array, size_t *tetrinumber)
{
	int		count_lines;
	int		count_hashes;
	int		k;
	int		o;

	initialize(&o, &count_hashes, &count_lines);
	if (*file != '.' && *file != '#')
		error();
	while (file[o])
	{
		k = o;
		create_row(temp_array);
		while (o < k + 4)
			check_this_row(file, &o, &count_hashes, temp_array);
		is_newline(file, &o);
		next_row(temp_array, &count_lines);
		if (count_lines == 4)
		{
			update(tetrinumber, &count_hashes, &o, &count_lines);
			if (check_endline(file, &o) == -1)
				break ;
		}
	}
	if (count_lines != 0)
		error();
}
