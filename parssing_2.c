/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:03:09 by aqiouami          #+#    #+#             */
/*   Updated: 2022/11/26 13:03:14 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

int	exact_sort(t_list *a)
{
	t_list	*index;
	int		i;

	i = 1;
	while ((a)->next)
	{
		index = (a)->next;
		if ((a)->content >= index->content)
			return (0);
		(a) = (a)->next;
		i++;
	}
	return (1);
}

int	check_limit(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((ft_strncmp (av[i], "2147483647", 10) > 0) \
			&& (ft_strlen(av[i]) >= 10))
		{
			write (2, "error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	error(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0)
		{
			write (2, "Error\n", 6);
			return (0);
		}
		j = -1;
		while (av[i][++j])
		{
			if (ft_isdigit(av[i][j]) == 0 || (av[i][j] == 32 && \
				ft_isdigit(av[i][j + 1]) == 0) || ((av[i][j] == '-') && \
				(av[i][j + 1] == '-' || ft_strlen(av[i]) == 1)))
			{
				write (2, "Error\n", 6);
				exit(1);
			}
		}
		i++;
	}
	return (1);
}

int	is_dup(t_list *head)
{
	t_list	*dup;
	t_list	*temp;

	dup = dup_list(head);
	temp = dup;
	dup = sort(dup);
	while (dup -> next)
	{
		if (dup -> content == dup -> next -> content)
		{
			ft_lstclear(&dup, free);
			return (0);
		}
		dup = dup -> next;
	}
	ft_lstclear(&temp, free);
	return (1);
}

t_list	*sort(t_list *head)
{
	t_list	*start;
	t_list	*next;
	t_list	*min;

	start = head;
	next = NULL;
	min = NULL;
	while (start->next)
	{
		min = start;
		next = start->next;
		while (next)
		{
			if (min->content > next->content)
				min = next;
			next = next->next;
		}
		swap(start, min);
		start = start->next;
	}
	return (head);
}
