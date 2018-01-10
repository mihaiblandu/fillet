/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_this_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 17:03:06 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/24 17:03:35 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_this_row(char *file, int *o, int *count_hashes,
								t_array *temp_array)
{
	if (file[*o] != '.' && file[*o] != '#')
		error();
	if (file[*o] == '#')
		*count_hashes = *count_hashes + 1;
	temp_array->space[temp_array->j][temp_array->i] = file[*o];
	temp_array->i++;
	*o = *o + 1;
}
