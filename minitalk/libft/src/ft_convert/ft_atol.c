/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:19:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/01 06:52:53 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	wrapped(int64_t n, int64_t old, int64_t sign)
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

int64_t	ft_atol(const char *str)
{
	int64_t	result;
	int64_t	sign;
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
