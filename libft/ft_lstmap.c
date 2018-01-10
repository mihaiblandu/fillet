/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:50:34 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/02 15:50:45 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		copy_content(t_list *to_list, t_list *from_list)
{
	size_t	i;

	i = 0;
	while (i < to_list->content_size)
	{
		((char*)(to_list->content))[i] = ((char*)(from_list->content))[i];
		i++;
	}
}

static t_list	*create_ex_list(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*back;
	size_t	i;

	i = 0;
	back = malloc(sizeof(t_list));
	if (!(back))
		return (NULL);
	back->next = NULL;
	back->content_size = (f(lst))->content_size;
	back->content = malloc(back->content_size);
	if (!(back->content))
		return (NULL);
	copy_content(back, f(lst));
	return (back);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*back;

	back = NULL;
	if (!(lst) || !(f))
		return (NULL);
	new = malloc(sizeof(t_list));
	if (!(new))
		return (NULL);
	back = new;
	new->content_size = (f(lst))->content_size;
	new->content = malloc(new->content_size);
	if (!(new->content))
		return (NULL);
	copy_content(new, f(lst));
	while (lst->next)
	{
		new->next = create_ex_list(lst->next, f);
		lst = lst->next;
		new = new->next;
	}
	return (back);
}
