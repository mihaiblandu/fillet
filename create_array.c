/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:50:06 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/19 07:48:46 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_array		*create_array(t_array *the_array, size_t size)
{
	the_array = malloc(sizeof(t_array));
	if (!(the_array))
		error();
	the_array->size = size;
	the_array->j = 0;
	the_array->i = 0;
	the_array->space = malloc(sizeof(char*) * the_array->size + 1);
	the_array->space[0] = NULL;
	if (!(the_array->space))
		error();
	return (the_array);
}
