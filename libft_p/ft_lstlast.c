/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:13:01 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/12 17:40:43 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (lst)
	{
		while (lst && lst->next)
		{
			temp = lst;
			lst = lst->next;
			lst->prev = temp;
		}
		return (lst);
	}
	return (NULL);
}
//
//int main()
//{
//	t_list	*a, *b, *c, *d;
//	a = ft_lstnew("hello");
//	b = ft_lstnew("hello");
//	c = ft_lstnew("hello");
//	d = ft_lstnew("helloo");
//	a -> next = b;
//	b -> next = c;
//	c -> next = d;
//	t_list *last = ft_lstlast(a);
//	printf("%s\n", last -> content);
//}
