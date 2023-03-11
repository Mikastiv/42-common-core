/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:56:29 by mleblanc          #+#    #+#             */
/*   Updated: 2021/12/03 00:56:49 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	ft_vec2_dist(t_vec2 a, t_vec2 b)
{
	double	dist_a;
	double	dist_b;

	dist_a = b.x - a.x;
	dist_b = b.y - a.y;
	return (sqrt(dist_a * dist_a + dist_b * dist_b));
}
