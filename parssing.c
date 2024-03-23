/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:05:28 by aqiouami          #+#    #+#             */
/*   Updated: 2022/11/26 13:05:30 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

t_list	*dup_list(t_list *head)
{
	t_list	*new_head;

	new_head = NULL;
	while (head)
	{
		ft_lstadd_back(&new_head, ft_lstnew(head -> content));
		head = head -> next;
	}
	return (new_head);
}

t_list	*parssing_helper(char *str)
{
	int		i;
	char	**ptr;
	t_list	*a;
	t_list	*new;

	i = 0;
	a = NULL;
	ptr = ft_split(str, 32);
	free(str);
	str = NULL;
	if (check_limit(ptr) == 0)
	{
		free (ptr);
		exit(1);
	}
	while (ptr[i])
	{
		new = ft_lstnew(ft_atoi(ptr[i]));
		free(ptr[i]);
		ft_lstadd_back(&a, new);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (a);
}

t_list	*parssing(int ac, char **av)
{
	char	*str;
	int		i;
	t_list	*a;

	i = 1;
	str = ft_calloc(1, 1);
	while (i < ac)
	{
		str = ft_strjoin(str, av[i]);
		i++;
	}
	a = parssing_helper(str);
	return (a);
}

void	indexing(t_list *a)
{
	int		i;
	t_list	*temp;
	t_list	*dup;
	t_list	*temp2;

	i = 0;
	dup = dup_list(a);
	temp2 = dup;
	dup = sort(dup);
	while (dup)
	{
		temp = a;
		while (temp)
		{
			if (dup -> content == temp -> content)
				temp -> index = i;
			temp = temp -> next;
		}
		i++;
		dup = dup -> next;
	}
	ft_lstclear(&temp2, free);
	dup = NULL;
}
