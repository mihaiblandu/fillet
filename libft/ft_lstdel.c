/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:43:42 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/01 15:56:47 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*ptr;

	if (!(alst) || !(del))
		return ;
	while ((*alst)->next)
	{
		del((*alst)->content, (*alst)->content_size);
		ptr = *alst;
		*alst = (*alst)->next;
		free(ptr);
		ptr = NULL;
	}
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
