/* ************************************************************************** */
/*	                                                                        */
/*	                                                    :::      ::::::::   */
/*   sort_3_5.c	                                     :+:      :+:    :+:   */
/*	                                                +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>	                +#+  +:+       +#+        */
/*	                                            +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:42:48 by aqiouami	      #+#    #+#             */
/*   Updated: 2022/11/26 13:14:17 by aqiouami         ###   ########.fr       */
/*	                                                                        */
/* ************************************************************************** */
#include "test.h"

void	sort_3(t_list **st)
{
	int		last;
	int		next;
	int		content;

	last = (ft_lstlast(*st))->content;
	next = (*st)->next->content;
	content = (*st)->content;
	if ((content > next) && (content < last))
		sa(st, 1);
	else if ((content < next) && (next > last) \
	&& (content < last))
	{
		sa(st, 1);
		ra(st, 1);
	}
	else if ((content > next) && (next > last))
	{
		sa(st, 1);
		rra(st, 1);
	}
	else if ((content > next) && (next < last))
		ra(st, 1);
	else if ((content < next) && (next > last))
		rra(st, 1);
}

void	sort_4(t_list **a, t_list **b)
{
	int	min;
	int	index;

	min = find_min(*a);
	index = find_index(*a, min);
	switch_min(a, min, index);
	send_b(b, a, 1);
	sort_3 (a);
	send_a(b, a, 1);
}

void	sort_5(t_list **a, t_list **b)
{
	int	min;
	int	index;

	if (ft_lstsize(*a) == 3)
	{
		sort_3(a);
		exit(0);
	}
	else if (ft_lstsize(*a) == 4)
	{
		sort_4(a, b);
		exit(0);
	}
	if (ft_lstsize(*a) == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a, 1);
		exit(0);
	}
	min = find_min(*a);
	index = find_index(*a, min);
	switch_min(a, min, index);
	send_b(b, a, 1);
	sort_4(a, b);
	send_a(b, a, 1);
}
