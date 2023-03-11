/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:53:10 by mleblanc          #+#    #+#             */
/*   Updated: 2021/11/19 19:57:20 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_clamp(int64_t v, int64_t min, int64_t max)
{
	if (v < min)
		return (min);
	if (v > max)
		return (max);
	return (v);
}
