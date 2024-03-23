/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:11:06 by aqiouami          #+#    #+#             */
/*   Updated: 27/11/2022 08:44:55 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void	dicide(t_list **s, t_list *x_list, int flag)
{
	if (flag == 1)
		while (*s != x_list)
			ra(s, 1);
	if (flag == 2)
		while (*s != x_list)
			rb(s, 1);
	if (flag == 3)
		while (*s != x_list)
			rra(s, 1);
	if (flag == 4)
		while (*s != x_list)
			rrb(s, 1);
}

int	find_min(t_list *st)
{
	int	min;

	min = INT_MAX;
	while (st)
	{
		if (st -> content < min)
			min = st -> content;
		st = st -> next;
	}
	return (min);
}
