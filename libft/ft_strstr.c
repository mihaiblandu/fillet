/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:12:41 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/03 13:53:30 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set(size_t *first_m, size_t *i, int *key)
{
	*first_m = *i;
	*key = 1;
}

static void	reset(size_t *j, size_t *i, size_t *count, int *key)
{
	*j = 0;
	*key = 0;
	*i = *i - *count;
	*count = 0;
}

static void	move_forward(size_t *j, size_t *i, size_t *count)
{
	*j = *j + 1;
	*i = *i + 1;
	*count = *count + 1;
}

char		*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	back;
	int		key;
	size_t	j;
	size_t	count;

	count = 0;
	j = 0;
	key = 0;
	i = 0;
	if (!(*little))
		return ((char*)big);
	while (big[i])
	{
		if (little[j] == big[i])
			set(&back, &i, &key);
		while (little[j] == big[i] && little[j] && big[i])
			move_forward(&j, &i, &count);
		if (key == 1 && (little[j]))
			reset(&j, &i, &count, &key);
		else if (key == 1 && !(little[j]))
			return ((char*)&(big[back]));
		i++;
	}
	return (NULL);
}
