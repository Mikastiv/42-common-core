/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:39:06 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/24 23:09:56 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*create_queue(int philo_count)
{
	int	*queue;
	int	i;
	int	j;

	queue = malloc(philo_count * sizeof(int));
	i = 1;
	j = 0;
	while (i <= philo_count)
	{
		queue[j] = i;
		i += 2;
		++j;
	}
	i = 2;
	while (i <= philo_count)
	{
		queue[j] = i;
		i += 2;
		++j;
	}
	return (queue);
}

void	rotate_queue(int *queue, int size)
{
	int	i;
	int	tmp;

	tmp = queue[0];
	i = 0;
	while (i < size - 1)
	{
		queue[i] = queue[i + 1];
		++i;
	}
	queue[i] = tmp;
}
