/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 18:39:16 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/24 18:41:16 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			find_start(t_array *temp_array)
{
	int			start;
	size_t		k;

	k = temp_array->j;
	start = -1;
	while (temp_array->i < 4)
	{
		while (temp_array->j < k + 4)
		{
			if (temp_array->space[temp_array->j][temp_array->i] == '#')
			{
				temp_array->j = k;
				k = temp_array->i;
				temp_array->i = 0;
				return (k);
			}
			temp_array->j++;
		}
		temp_array->j = k;
		temp_array->i++;
	}
	temp_array->j = k;
	temp_array->i = 0;
	return (start);
}
