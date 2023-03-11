/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 20:24:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/14 16:25:23 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	find_number(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->data[i] == n)
			return (i);
		++i;
	}
	return (-1);
}

int	average(t_stack *s)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < s->size)
	{
		sum += s->data[i];
		++i;
	}
	return ((float)(sum) / (int)(s->size + 0.5f));
}

bool	is_sorted(t_stack *s)
{
	int	i;
	int	prev;

	if (s->size < 2)
		return (true);
	i = 1;
	prev = s->data[0];
	while (i < s->size)
	{
		if (s->data[i] > prev)
			return (false);
		prev = s->data[i++];
	}
	return (true);
}

bool	contains_smaller(t_stack *s, int max)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->data[i] <= max)
			return (true);
		++i;
	}
	return (false);
}
