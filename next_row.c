/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:54:57 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/14 19:55:16 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	next_row(t_array *temp_array, int *count_lines)
{
	temp_array->space[temp_array->j][temp_array->i] = '\0';
	temp_array->j++;
	temp_array->i = 0;
	*count_lines = *count_lines + 1;
}
