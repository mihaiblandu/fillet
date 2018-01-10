/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:37:29 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/24 18:30:59 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "fillit.h"
#include "./libft/libft.h"

static size_t		minimum_sq(size_t number)
{
	size_t	i;

	i = 2;
	while (i * i < number * 4)
		i++;
	return (i);
}

int					main(int argc, char **argv)
{
	int				fd;
	char			p_buf[BUF_SIZE + 1];
	int				ret;
	t_array			*temp_array;
	size_t			tetrinumber;

	temp_array = NULL;
	tetrinumber = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit file_name\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = read(fd, p_buf, BUF_SIZE);
	if (ret == -1 || close(fd) == -1)
		return (-1);
	p_buf[ret] = '\0';
	temp_array = create_array(temp_array, 26 * 4);
	check_input_file(&(p_buf[0]), &tetrinumber, temp_array);
	algorithm(minimum_sq(tetrinumber), cr_tetr_list(temp_array, tetrinumber),
									tetrinumber);
	return (0);
}
