/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:32:03 by aqiouami          #+#    #+#             */
/*   Updated: 2022/11/26 13:03:51 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void	send_a(t_list **b, t_list **a, int i)
{
	t_list	*temp;
	t_list	*copy;

	if (*b)
	{
		copy = ft_lstnew((*b)->content);
		ft_lstadd_front(a, copy);
		temp = (*b);
		(*b)->prev = NULL;
		(*b) = (*b)->next;
		free(temp);
		temp = NULL;
	}
	if (i == 1)
		write(1, "pa\n", 3);
}

void	send_b(t_list **b, t_list **a, int i)
{
	t_list	*copy;
	t_list	*temp;

	if (*a)
	{
		copy = ft_lstnew((*a)->content);
		ft_lstadd_front(b, copy);
		temp = (*a);
		(*a) = (*a)->next;
		free(temp);
		temp = NULL;
	}
	if (i == 1)
		write(1, "pb\n", 3);
}

void	rr(t_list **a, t_list **b, int i)
{
	ra(a, 0);
	rb(b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}

void	rrr(t_list **a, t_list **b, int i)
{
	rra(a, 0);
	rrb(b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}

void	rrb(t_list **s, int i)
{
	t_list	*last;
	t_list	*before_last;

	last = ft_lstlast(*s);
	before_last = last->prev;
	before_last->next = NULL;
	last->next = *s;
	*s = last;
	if (i == 1)
		write(1, "rrb\n", 4);
}
