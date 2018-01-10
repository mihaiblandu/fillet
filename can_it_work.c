/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_it_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:55:20 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/26 18:44:27 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	reset(t_array *test_array, size_t back_j)
{
	while (test_array->j < back_j)
	{
		while (test_array->i < test_array->size)
		{
			if (test_array->space[test_array->j][test_array->i] == '0')
				test_array->space[test_array->j][test_array->i] = '.';
			else if (test_array->space[test_array->j][test_array->i] == 'x')
				test_array->space[test_array->j][test_array->i] = '.';
			test_array->i++;
		}
		test_array->i = 0;
		test_array->j++;
	}
	test_array->j = 0;
}

static int	finish(t_array *test_array, size_t *nr_of_orphaned,
										size_t tetrinumber, int flag)
{
	size_t	back_j;

	if (flag == 1)
		back_j = test_array->j + 1;
	else
		back_j = test_array->size;
	test_array->j = 0;
	test_array->i = 0;
	reset(test_array, back_j);
	if (test_array->size * test_array->size - tetrinumber * 4 < *nr_of_orphaned)
		return (-1);
	return (1);
}

static void	go_to_next_row(t_array *test_arr, size_t *link_nmb)
{
	test_arr->i = 0;
	test_arr->j++;
	*link_nmb = 0;
}

static int	check_state(t_array *test_array, size_t *link_nmb,
							size_t *nr_of_orphaned, int tetrinumber)
{
	if (*link_nmb < 5)
	{
		*nr_of_orphaned = *nr_of_orphaned + 1;
		test_array->space[test_array->j][test_array->i] = '0';
	}
	else if (*link_nmb >= 5)
		test_array->space[test_array->j][test_array->i] = 'x';
	if (test_array->size * test_array->size - tetrinumber * 4
			< *nr_of_orphaned)
		return (1);
	return (0);
}

int			can_it_work(t_array *t_arr, size_t trnmb)
{
	size_t	nr_orphan;
	size_t	link_nmb;
	int		flag;

	flag = 0;
	link_nmb = 0;
	nr_orphan = 0;
	while (t_arr->j < t_arr->size)
	{
		while (t_arr->i < t_arr->size)
		{
			if (t_arr->space[t_arr->j][t_arr->i] == '.')
			{
				seed_this_space(t_arr, &link_nmb, t_arr->j, t_arr->i);
				if ((flag = check_state(t_arr, &link_nmb, &nr_orphan, trnmb)))
					break ;
			}
			t_arr->i++;
			link_nmb = 0;
		}
		if (flag == 1)
			break ;
		go_to_next_row(t_arr, &link_nmb);
	}
	return (finish(t_arr, &nr_orphan, trnmb, flag));
}
