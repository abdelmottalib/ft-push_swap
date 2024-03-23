/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:00:02 by aqiouami          #+#    #+#             */
/*   Updated: 27/11/2022 08:53:02 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

int	smallest_index(t_list *a, int max_count)
{
	t_small_index	rndm;

	rndm.max = INT_MAX;
	rndm.index = calloc(50, 4);
	rndm.i = 0;
	rndm.j = 0;
	rndm.temp = a;
	while (rndm.temp)
	{
		if (rndm.temp->count == max_count)
			rndm.index[rndm.i++] = (rndm.temp->index);
		rndm.temp = rndm.temp->next;
	}
	while (rndm.j < rndm.i)
	{
		if (rndm.index[rndm.j] < rndm.max)
			rndm.max = rndm.index[rndm.j];
		rndm.j++;
	}
	free(rndm.index);
	return (rndm.max);
}

t_list	*best(t_list *a)
{
	int		aa;
	t_list	*temp;

	aa = 0;
	temp = a;
	while (temp)
	{
		if ((temp->count) > aa)
			aa = temp-> count;
		temp = temp->next;
	}
	aa = smallest_index(a, aa);
	while (a)
	{
		if (a->index == aa)
			break ;
		a = a->next;
	}
	return (a);
}

void	reset(t_list *st)
{
	while (st)
	{
		st->bool = 0;
		st = st->next;
	}
}

void	markup_helper(t_list *mh, t_list *st)
{
	t_list	*temp;
	t_list	*temp1;
	int		max;

	temp = st;
	temp1 = mh;
	temp1->count = 1;
	max = mh->index;
	mh->bool = 1;
	while (temp)
	{
		if (mh->index >= max)
		{
			max = mh->index;
			mh->bool = 1;
			temp1->count++;
		}
		if (mh->next == NULL)
			mh = st;
		else
			mh = mh->next;
		temp = temp->next;
	}
}

int	markup(t_list *st)
{
	t_list	*mark_h;
	t_list	*bestmh;

	mark_h = st;
	bestmh = mark_h;
	while (mark_h)
	{
		reset(st);
		markup_helper(mark_h, st);
		mark_h = mark_h->next;
	}
	bestmh = best(st);
	reset(st);
	markup_helper(bestmh, st);
	bestmh->bool = 1;
	return (bestmh->count);
}
