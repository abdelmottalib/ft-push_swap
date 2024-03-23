/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:24:36 by aqiouami          #+#    #+#             */
/*   Updated: 2022/11/26 13:04:36 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void	sb(t_list **b, int i)
{
	int		temp;
	t_list	*index;

	index = (*b)->next;
	temp = (*b)->content;
	(*b)->content = index->content;
	index->content = temp;
	if (i == 1)
		write (1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int i)
{
	sa(a, 0);
	sb(b, 0);
	if (i == 1)
		write (1, "ss\n", 3);
}
