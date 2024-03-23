/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:54:49 by aqiouami          #+#    #+#             */
/*   Updated: 2022/11/25 13:48:33 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void	push_b(t_list **a, t_list **b)
{
	int		index;
	t_list	*temp;

	temp = data_numb(*a);
	while (temp)
	{
		index = find_index(*a, temp -> content);
		switch_min(a, temp -> content, index);
		send_b(b, a, 1);
		temp = data_numb(*a);
	}
}

t_list	*data_numb(t_list *a)
{
	while (a)
	{
		if (a -> bool == 0)
			return (a);
		a = a -> next;
	}
	return (0);
}

int	find_index(t_list *st, int key)
{
	int	i;

	i = 0;
	while (st)
	{
		if (st -> content == key)
			return (i);
		st = st -> next;
		i++;
	}
	return (0);
}

void	switch_min(t_list **st, int key, int index)
{
	int	size;

	size = ft_lstsize(*st);
	while (1)
	{
		if ((*st)->content == key)
			break ;
		else if (index > (size / 2))
			rra(st, 1);
		else
			ra(st, 1);
	}
}
