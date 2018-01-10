/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:47:28 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/30 19:29:21 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char			*create_empty_str(void)
{
	char	*new;

	new = malloc(sizeof(char));
	if (!(new))
		return (NULL);
	new[0] = '\0';
	return (new);
}

static unsigned int	how_long(char const *s, unsigned int *i,
				unsigned int *t_length)
{
	unsigned int	k;

	while (s[*i])
	{
		while (s[*i] != ' ' && s[*i] != '\n' && s[*i] != '\t' && s[*i])
			*i = *i + 1;
		k = *i;
		while (s[k] && (s[k] == ' ' || s[k] == '\n' || s[k] == '\t'))
			k++;
		if (!(s[k]))
			break ;
		else
			*i = *i + 1;
	}
	*t_length = *i;
	return (*t_length);
}

char				*ft_strtrim(char const *s)
{
	char			*new;
	unsigned int	i;
	unsigned int	t_length;
	unsigned int	start;

	t_length = 0;
	i = 0;
	if (!(s))
		return (NULL);
	if (!(s[i]))
		return (create_empty_str());
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (!(s[i]))
		return (create_empty_str());
	start = i;
	t_length = how_long(s, &i, &t_length);
	new = malloc(t_length - start + 1);
	if (!(new))
		return (NULL);
	i = 0;
	while (start < t_length)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
