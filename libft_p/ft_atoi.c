/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:25:20 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/18 14:59:04 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		n;
	int		nb;

	n = 1;
	nb = 0;
	if ((ft_strncmp (str, "9223372036854775807", 50) >= 0) \
			&& (ft_strlen(str) >= 19))
		return (-1);
	if ((ft_strncmp (str, "-9223372036854775808", 50) >= 0) \
			&& (ft_strlen(str) >= 20))
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n *= -1;
		str++;
	}
	while (*str && *str <= '9' && *str >= '0')
		nb = nb * 10 + *str++ - 48;
	return (nb * n);
}
