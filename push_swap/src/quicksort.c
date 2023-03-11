/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:33:39 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/03 14:53:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	swap(t_stack *s, int left, int right)
{
	int	tmp;

	tmp = s->data[left];
	s->data[left] = s->data[right];
	s->data[right] = tmp;
}

static int	partition(t_stack *s, int left, int right, int pivot)
{
	while (left <= right)
	{
		while (s->data[left] > pivot)
			++left;
		while (s->data[right] < pivot)
			--right;
		if (left <= right)
		{
			swap(s, left, right);
			++left;
			--right;
		}
	}
	return (left);
}

static void	quicksort_r(t_stack *s, int left, int right)
{
	int	pivot;
	int	index;

	if (left >= right)
		return ;
	pivot = s->data[(left + right) / 2];
	index = partition(s, left, right, pivot);
	quicksort_r(s, left, index - 1);
	quicksort_r(s, index, right);
}

void	quicksort(t_stack *s)
{
	quicksort_r(s, 0, s->size - 1);
}
