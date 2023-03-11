/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:49:09 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/14 16:20:34 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
#include "libft.h"

static bool	front_a_is_next(t_pswap *s)
{
	return (front(s->a) == 0 || front(s->a) == back(s->a) + 1);
}

static bool	should_sort_b(t_pswap *s)
{
	return (stack_min(s->b) == back(s->a) + 1);
}

static void	push_a_top(t_pswap *s, int max)
{
	while (front(s->a) <= max && front(s->a) != 0)
	{
		if (front_a_is_next(s))
			rotate_a(s->a);
		else
			push_b(s->b, s->a);
	}
	if (should_sort_b(s))
		sort_b(s);
}

void	sort_b(t_pswap *s)
{
	int	b_max;

	if (s->b->size == 0)
		return ;
	b_max = stack_max(s->b);
	split_b_higher(s, average(s->b));
	while (front_a_is_next(s) && front(s->a) != 0)
		rotate_a(s->a);
	sort_b(s);
	push_a_top(s, b_max);
}

void	sort_big(t_pswap *s)
{
	int	mid;

	if (is_sorted(s->a))
		return ;
	mid = average(s->a);
	split_a_lower(s, mid);
	sort_b(s);
	push_a_top(s, stack_max(s->a));
}
