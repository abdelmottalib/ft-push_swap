/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:17:19 by aqiouami          #+#    #+#             */
/*   Updated: 27/11/2022 08:49:23 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef TEST_H
# define TEST_H
# include <unistd.h>
# include <stdlib.h>
# include "libft_p/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_small_index
{
	int		max;
	int		*index;
	int		i;
	int		j;
	int		max_count;
	t_list	*temp;
}t_small_index;

t_list	*dup_list(t_list *head);
t_list	*parssing(int ac, char **av);
t_list	*parssing_helper(char *str);
void	indexing(t_list *a);
int		find_max(t_list *st);
void	sort_3(t_list **a);
void	sort_5(t_list **a, t_list **b);
void	sort_4(t_list **a, t_list **b);
int		check_limit(char **av);
int		error(char **av);
int		is_dup(t_list *head);
void	push_b(t_list **a, t_list **b);
t_list	*data_numb(t_list *a);
int		find_index(t_list *st, int key);
void	switch_min(t_list **st, int key, int index);
void	push_a(t_list **a, t_list **b);
void	push_a_helper(t_list **a, t_list **b);
int		best_move(t_list *a, t_list *b);
void	ft_move(t_list **a, t_list **b, t_list *b_list);
t_list	*next_gretest(t_list **a, t_list *b_list);
void	mouvement(t_list **a, t_list **b, t_list *the_least);
t_list	*least(t_list *a);
void	align(t_list **a);
void	dicide(t_list **s, t_list *x_list, int flag);
int		find_min(t_list *st);
int		smallest_index(t_list *a, int max_count);
t_list	*best(t_list *a);
void	reset(t_list *st);
void	markup_helper(t_list *mh, t_list *st);
int		markup(t_list *st);
void	send_a(t_list **b, t_list **a, int i);
void	send_b(t_list **b, t_list **a, int i);
void	rr(t_list **a, t_list **b, int i);
void	rrr(t_list **a, t_list **b, int i);
t_list	*sort(t_list *head);
void	rrb(t_list **s, int i);
void	swap(t_list *a, t_list *b);
void	rra(t_list **s, int i);
void	ra(t_list **s, int i);
void	rb(t_list **s, int i);
void	dicide_2(t_list **a);
void	get_line(t_list **a, t_list **b);
int		exact_sort(t_list *a);
void	replicate_op(char *line, t_list **a, t_list **b);
void	ss(t_list **a, t_list **b, int i);
void	sa(t_list **a, int i);
void	sb(t_list **b, int i);

#endif
