/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:26:13 by mperepio          #+#    #+#             */
/*   Updated: 2017/11/29 21:09:20 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**create_empty_arr(void)
{
	char	**arr;

	arr = NULL;
	arr = malloc(sizeof(char*));
	if (!(arr))
		return (NULL);
	arr[0] = NULL;
	return (arr);
}

static int	word_counter(char const *str, unsigned int i, char c)
{
	unsigned int	words;

	words = 0;
	while (str[i])
	{
		while (str[i] != c && str[i])
			i++;
		words++;
		while (str[i] == c && str[i])
			i++;
	}
	return (words);
}

static int	letter_counter(char	const *str, unsigned int start, char c)
{
	unsigned int	k;

	k = 0;
	while (str[start] != c && str[start])
	{
		k++;
		start++;
	}
	return (k);
}

static char	**create_array(char **array, char const *str,
		unsigned int start, char c)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (str[start])
	{
		i = 0;
		array[j] = malloc(letter_counter(str, start, c) + 1);
		if (!(array[j]))
			return (NULL);
		while (str[start] != c && str[start])
			array[j][i++] = str[start++];
		array[j++][i] = '\0';
		while (str[start] == c && str[start])
			start++;
	}
	array[j] = NULL;
	return (array);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**arr;
	unsigned int	i;
	unsigned int	start;
	unsigned int	j;

	j = 0;
	i = 0;
	if (!(s))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	if (!(s[i]))
		return (create_empty_arr());
	start = i;
	arr = malloc((word_counter(&(s[i]), i, c) + 1) * sizeof(char*));
	if (!(arr))
		return (NULL);
	return (create_array(arr, s, start, c));
}
