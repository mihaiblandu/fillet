/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:24:04 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/01 18:30:50 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*my_list;
	size_t	i;

	i = 0;
	my_list = malloc(sizeof(t_list));
	if (!(my_list))
		return (NULL);
	if (!(content))
	{
		my_list->content = NULL;
		my_list->content_size = 0;
		my_list->next = NULL;
		return (my_list);
	}
	my_list->content = malloc(content_size);
	if (!(my_list->content))
		return (NULL);
	while (i < content_size)
	{
		((char*)(my_list->content))[i] = ((char*)content)[i];
		i++;
	}
	my_list->content_size = content_size;
	my_list->next = NULL;
	return (my_list);
}
