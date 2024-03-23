/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:32:58 by aqiouami          #+#    #+#             */
/*   Updated: 2022/11/25 16:27:58 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void	swap(t_list *a, t_list *b)
{
	int	temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void	rra(t_list **s, int i)
{
	t_list	*last;
	t_list	*before_last;

	last = ft_lstlast(*s);
	before_last = last->prev;
	before_last->next = NULL;
	last->next = *s;
	*s = last;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ra(t_list **s, int i)
{
	t_list	*temp;
	t_list	*last;

	temp = (*s);
	(*s) = (*s)->next;
	last = ft_lstlast(*s);
	last->next = temp;
	temp->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **s, int i)
{
	t_list	*temp;
	t_list	*last;

	temp = (*s);
	(*s) = (*s)->next;
	last = ft_lstlast(*s);
	last->next = temp;
	temp->next = NULL;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	sa(t_list **a, int i)
{
	int		temp;
	t_list	*index;

	index = (*a)->next;
	temp = (*a)->content;
	(*a)->content = index->content;
	index->content = temp;
	if (i == 1)
		write (1, "sa\n", 3);
}
