/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 11:16:48 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/03 12:44:10 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item,
									int (*cmpf)(void*, void*))
{
	if (!(*root))
		*root = btree_create_node(item);
	else
	{
		if (cmpf(item, (*(*root)).item) < 0)
			btree_insert_data(&(*(*root)).left, item, cmpf);
		else if (cmpf(item, (*(*root)).item) >= 0)
			btree_insert_data(&(*(*root)).right, item, cmpf);
	}
}
