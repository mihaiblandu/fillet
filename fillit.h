/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperepio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:42:13 by mperepio          #+#    #+#             */
/*   Updated: 2017/12/24 18:40:13 by mperepio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# define BUF_SIZE 1024

typedef struct			s_tetr_list
{
	size_t				i;
	size_t				j;
	size_t				size;
	char				**space;
	size_t				max_length;
	size_t				index;
	struct s_tetr_list	*next;
}						t_tetr_list;

typedef struct			s_array
{
	size_t				i;
	size_t				j;
	size_t				size;
	char				**space;
}						t_array;

void					add_this_tetrimino(t_array *test_array,
									int letter, t_tetr_list *trmo);
void					algorithm(size_t min_size, t_tetr_list *tetr_list,
													size_t tetrinumber);
void					basic_check(char *file, t_array *test_array,
											size_t *tetrinumber);
int						can_it_work(t_array *test_array, size_t tetrinumber);
void					check_input_file(char *file, size_t *tetrinumber,
											t_array *test_array);
void					check_links(t_array *temp_array, int *link_nmb,
												int i, int j);
void					check_this_row(char *file, int *o, int *count_hashes,
								t_array *temp_array);
void					clear_this_tetrimino(t_array *test_array,
									t_tetr_list *tetrimino, int letter);
t_array					*create_array(t_array *the_array, size_t size);
void					create_row(t_array *temp_array);
t_tetr_list				*cr_tetr_list(t_array *temp_array, size_t tetrinumber);
void					error(void);
int						find_next_space(t_array *t_sq, t_tetr_list *trmo,
													int letter);
int						find_start(t_array *temp_array);
int						rec_tetrimino(int letter, t_array *test_array,
								t_tetr_list *a_tetrimino, size_t tetrinumber);
void					print_result(t_array *final_array);
void					next_row(t_array *temp_array, int *count_lines);
void					seed_this_space(t_array *test_arr, size_t *link_nmb,
											size_t j, size_t i);
void					seed_first_line(t_array *test_arr, size_t *link_nmb,
										size_t j, size_t i);
void					seed_last_line(t_array *test_arr, size_t *link_nmb,
											size_t j, size_t i);
void					seed_center(t_array *test_arr, size_t *link_nmb,
											size_t j, size_t i);
#endif
