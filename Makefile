# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperepio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 15:07:26 by mperepio          #+#    #+#              #
#    Updated: 2017/12/24 19:04:22 by mperepio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

all: $(NAME)

$(NAME):	
	make -C ./libft all
	gcc -Wall -Wextra -Werror fillit.c check_input_file.c check_links.c \
	error.c create_row.c add_this_tetrimino.c clear_this_tetrimino.c \
	can_it_work.c create_array.c next_row.c basic_check.c  \
	seed_this_space.c create_tetr_list.c print_result.c find_next_space.c \
	check_this_row.c algorithm.c rec_tetrimino.c seed_first_line.c \
	find_start.c seed_last_line.c seed_center.c ./libft/libft.a -o fillit

clean:
	make -C ./libft clean

fclean: clean
	/bin/rm -f ./libft/libft.a
	/bin/rm -f fillit

re:	fclean all
