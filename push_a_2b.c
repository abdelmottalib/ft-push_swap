/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_2b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:42:53 by aqiouami          #+#    #+#             */
/*   Updated: 27/11/2022 08:44:12 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

t_list	*next_gretest(t_list **a, t_list *b_list)
{
	int		j;
	int		max;
	t_list	*temp;
	t_list	*dup;

	j = 0;
	max = INT_MAX;
	temp = *a;
	dup = *a;
	while (temp)
	{
		if (temp -> content < max && temp -> content > b_list -> content)
			max = temp -> content;
		temp = temp -> next;
	}
	while (dup)
	{
		if (dup -> content == max)
			return (dup);
		j++;
		dup = dup -> next;
	}
	return (0);
}

void	mouvement(t_list **a, t_list **b, t_list *the_least)
{
	t_list	*a_list;

	a_list = next_gretest(a, the_least);
	if (a_list->pos <= a_list->rev_p && the_least->pos <= the_least->rev_p)
		while (*a != a_list && *b != the_least)
			rr(a, b, 1);
	if (a_list->pos > a_list->rev_p && the_least->pos > the_least->rev_p)
		while (*a != a_list && *b != the_least)
			rrr(a, b, 1);
	if (a_list->pos <= a_list->rev_p)
		dicide(a, a_list, 1);
	else
		dicide(a, a_list, 3);
	if (the_least->pos <= the_least->rev_p)
		dicide(b, the_least, 2);
	else
		dicide(b, the_least, 4);
}

t_list	*least(t_list *a)
{
	int		aa;
	t_list	*temp;

	aa = INT_MAX;
	temp = a;
	while (temp)
	{
		if ((temp -> count) < aa)
			aa = temp-> count;
		temp = temp -> next;
	}
	while (a)
	{
		if (a -> count == aa)
			break ;
		a = a -> next;
	}
	return (a);
}

void	align(t_list **a)
{
	int	size;
	int	min;
	int	index;

	size = ft_lstsize(*a);
	min = find_min(*a);
	index = find_index(*a, min);
	while ((*a)->content != min)
	{
		if (index > (size / 2))
			rra(a, 1);
		else
			ra(a, 1);
	}
}
