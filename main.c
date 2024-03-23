/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:02:26 by aqiouami          #+#    #+#             */
/*   Updated: 2022/11/26 13:02:57 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

int	main(int argc, char *argv[])
{
	t_list	*b;
	t_list	*a;

	b = NULL;
	error(argv);
	if (argc == 1 || argc == 2)
		return (1);
	a = parssing(argc, argv);
	if (exact_sort(a) == 1 || is_dup(a) == 0)
	{
		if (is_dup(a) == 0)
			write(2, "Error\n", 6);
		ft_lstclear(&a, free);
		return (1);
	}
	if (argc <= 6)
		sort_5(&a, &b);
	if (a == NULL)
		return (1);
	indexing(a);
	markup(a);
	push_b(&a, &b);
	push_a(&a, &b);
	ft_lstclear(&a, free);
	return (0);
}
