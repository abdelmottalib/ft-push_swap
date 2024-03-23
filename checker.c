/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:12:52 by aqiouami          #+#    #+#             */
/*   Updated: 2022/11/25 16:26:28 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void	replicate_op(char *line, t_list **a, t_list **b)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(a, 0);
	if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(a, 0);
	if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(b, 0);
	if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(b, 0);
	if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, 0);
	if (ft_strncmp(line, "rrr\n", 3) == 0)
		rrr(a, b, 0);
	if (ft_strncmp(line, "pa\n", 3) == 0)
		send_a(b, a, 0);
	if (ft_strncmp(line, "pb\n", 3) == 0)
		send_b(b, a, 0);
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(a, 0);
	if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(b, 0);
	if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, 0);
}

void	get_line(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		replicate_op(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

void	dicide_2(t_list **a)
{
	if (exact_sort(*a) == 1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = NULL;
	error(argv);
	if (argc == 1)
		return (1);
	a = parssing(argc, argv);
	if (a == NULL)
		return (1);
	if (is_dup(a) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	get_line(&a, &b);
	dicide_2(&a);
	return (0);
}
