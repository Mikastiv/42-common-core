/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:48:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/14 16:25:15 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

t_stack	*new_stack(int size)
{
	t_stack	*arr;

	arr = ft_calloc(1, sizeof(t_stack));
	if (!arr)
		return (NULL);
	arr->data = ft_calloc((size_t)size, sizeof(int));
	if (!arr->data)
		return (ft_free(arr));
	arr->size = 0;
	return (arr);
}

void	delete_stack(t_stack *s)
{
	if (s)
		ft_free(s->data);
	ft_free(s);
}

int	front(t_stack *s)
{
	return (s->data[s->size - 1]);
}

int	back(t_stack *s)
{
	return (s->data[0]);
}

void	copy_stack(t_stack *dst, t_stack *src)
{
	int	i;

	i = 0;
	while (i < src->size)
	{
		dst->data[i] = src->data[i];
		++i;
	}
	dst->size = src->size;
}
