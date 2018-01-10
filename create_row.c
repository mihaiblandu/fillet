/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_row.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:52:35 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/24 20:07:17 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void		create_row(t_array *temp_array)
{
	temp_array->space[temp_array->j] = malloc(sizeof(char) * 5);
	if (!(temp_array->space[temp_array->j]))
		error();
}
