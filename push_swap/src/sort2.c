/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:37:23 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/15 16:38:16 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static void	sort_3(t_pswap *s)
{
	int	max;

	max = stack_max(s->a);
	if (find_number(s->a, max) == 1)
		rev_rotate_a(s->a);
	else if (find_number(s->a, max) == 2)
		rotate_a(s->a);
	if (!is_sorted(s->a))
		swap_a(s->a);
}

static void	sort_4_5(t_pswap *s)
{
	int	current_num;

	current_num = 0;
	while (s->a->size > 3)
	{
		if (front(s->a) == current_num)
		{
			push_b(s->b, s->a);
			++current_num;
			if (current_num == 2)
				break ;
			continue ;
		}
		if (find_number(s->a, current_num) < s->a->size / 2)
			rev_rotate_a(s->a);
		else
			rotate_a(s->a);
	}
	sort_3(s);
	while (s->b->size > 0)
		push_a(s->a, s->b);
}

void	sort_small(t_pswap *s)
{
	if (is_sorted(s->a))
		return ;
	if (s->a->size == 2)
		swap_a(s->a);
	else if (s->a->size == 3)
		sort_3(s);
	else
		sort_4_5(s);
}
