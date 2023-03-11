/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 00:07:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/04 23:32:28 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

static void	rev_rotate(t_stack *a)
{
	int	i;
	int	tmp;

	if (a->size < 2)
		return ;
	i = 0;
	tmp = a->data[0];
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		++i;
	}
	a->data[a->size - 1] = tmp;
}

void	rev_rotate_a(t_stack *a)
{
	rev_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	rev_rotate_b(t_stack *b)
{
	rev_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	rev_rotate_ab(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putendl_fd("rrr", 1);
}
