/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 11:03:25 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/03 12:51:15 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		btree_level_count(t_btree *root)
{
	int		count;
	int		count_left;
	int		count_right;

	count = 0;
	if (!(root))
		return (count);
	count = 1;
	count_left = count + btree_level_count(root->left);
	count_right = count + btree_level_count(root->right);
	if (count_left > count_right)
		return (count_left);
	else if (count_left < count_right)
		return (count_right);
	else if (count_left == count_right && count_left != 1)
		return (count_left);
	return (count);
}
