/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strany.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:36:42 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/10 10:02:25 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strany(const char *s, bool (*f)(char))
{
	while (*s)
	{
		if (f(*s))
			return (true);
		++s;
	}
	return (false);
}
