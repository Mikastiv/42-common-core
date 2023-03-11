/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:14:11 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/01 06:52:56 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	wrapped(int32_t n, int32_t old, int32_t sign)
{
	if (sign > 0)
	{
		if (n < old)
			return (true);
		else
			return (false);
	}
	else
	{
		if (n > old)
			return (true);
		else
			return (false);
	}
}

int32_t	ft_atoi(const char *str)
{
	int32_t	result;
	int32_t	sign;
	int64_t	old;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (ft_isdigit(*str))
	{
		old = result;
		result = (result * 10) + ((*str - '0') * sign);
		if (wrapped(result, old, sign))
			return (-1);
		str++;
	}
	return (result);
}
