/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:42:31 by aqiouami          #+#    #+#             */
/*   Updated: 27/11/2022 08:44:56 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*the_least;

	the_least = NULL;
	while (*b)
	{
		push_a_helper(a, b);
		the_least = least(*b);
		mouvement(a, b, the_least);
		send_a(b, a, 1);
	}
	align(a);
}

void	push_a_helper(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	while (temp)
	{
		ft_move(a, b, temp);
		temp = temp -> next;
	}
}

int	best_move(t_list *a_list, t_list *b_list)
{
	if ((a_list->pos <= a_list->rev_p) && (b_list->pos <= b_list->rev_p)
		&& (a_list->pos >= b_list->pos))
		return (a_list->pos);
	else if ((a_list->pos <= a_list->rev_p) && (b_list->pos <= b_list->rev_p) \
		&& (a_list->pos < b_list->pos))
		return (b_list->pos);
	else if ((a_list->pos > a_list->rev_p) && (b_list->pos > b_list->rev_p) \
		&& (a_list->rev_p >= b_list->rev_p))
		return (a_list->rev_p);
	else if ((a_list->pos > a_list->rev_p) && (b_list->pos > b_list->rev_p) \
		&& (a_list->rev_p < b_list->rev_p))
		return (b_list->rev_p);
	else if ((a_list->pos <= a_list->rev_p) && (b_list->pos > b_list->rev_p))
		return (a_list->pos + b_list->rev_p);
	else
		return (a_list->rev_p + b_list->pos);
	return (0);
}

void	ft_move(t_list **a, t_list **b, t_list *b_list)
{
	t_list	*a_list;

	a_list = next_gretest(a, b_list);
	b_list->pos = find_index(*b, b_list->content);
	a_list->pos = find_index(*a, a_list->content);
	a_list->rev_p = ft_lstsize(*a) - (a_list)->pos;
	b_list->rev_p = ft_lstsize(*b) - (b_list)->pos;
	b_list->count = best_move(a_list, b_list);
}
