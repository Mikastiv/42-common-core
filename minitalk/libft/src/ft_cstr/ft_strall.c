/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:25:41 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/10 10:03:36 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strall(const char *s, bool (*f)(char))
{
	while (*s)
	{
		if (!f(*s))
			return (false);
		++s;
	}
	return (true);
}
