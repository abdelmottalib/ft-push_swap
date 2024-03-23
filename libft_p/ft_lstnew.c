/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:14:59 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/13 12:57:51 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	node -> prev = NULL;
	return (node);
}
// int main()
// {
// 	t_list *node;
// 	char  str[] = "hello!";
// 	node = ft_lstnew(str);
// 	printf("%s\n", (char *)(node -> content));
// }
