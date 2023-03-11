/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:19:23 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/14 16:13:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_max(t_stack *s)
{
	int	i;
	int	max;

	max = back(s);
	i = 1;
	while (i < s->size)
	{
		if (max < s->data[i])
			max = s->data[i];
		++i;
	}
	return (max);
}

int	stack_min(t_stack *s)
{
	int	i;
	int	min;

	min = back(s);
	i = 1;
	while (i < s->size)
	{
		if (min > s->data[i])
			min = s->data[i];
		++i;
	}
	return (min);
}
