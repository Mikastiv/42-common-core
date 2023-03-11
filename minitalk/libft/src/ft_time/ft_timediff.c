/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timediff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:01:05 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/07 00:52:35 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_timediff(t_time t1, t_time t2)
{
	double	diff;

	diff = (double)(t2.tp.tv_sec - t1.tp.tv_sec);
	diff += (double)(t2.tp.tv_usec - t1.tp.tv_usec) *0.000001;
	return (diff);
}
