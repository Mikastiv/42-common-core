/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:51:14 by mleblanc          #+#    #+#             */
/*   Updated: 2021/10/15 14:55:07 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	*one_philo_cycle(void *data)
{
	t_philo	*philo;

	philo = data;
	pthread_mutex_lock(philo->fork1);
	printf("%ld 1 has taken a fork\n", time_ms() - philo->m->start_time);
	usleep(philo->m->opts.time_to_die * 1000);
	printf("%ld 1 died\n", time_ms() - philo->m->start_time);
	pthread_mutex_unlock(philo->fork2);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_monitor	m;
	int			i;
	char		*msg;

	memset(&m, 0, sizeof(t_monitor));
	msg = parse_input(argc, argv, &m.opts);
	if (msg)
		return (quit_error(msg));
	init_monitor(&m);
	if (m.opts.philo_count == 1)
		pthread_create(&m.philos[0].tid, NULL, one_philo_cycle, &m.philos[0]);
	else
	{
		i = 0;
		while (i < m.opts.philo_count)
		{
			pthread_create(&m.philos[i].tid, NULL, philo_cycle, &m.philos[i]);
			++i;
		}
	}
	i = 0;
	while (i < m.opts.philo_count)
		pthread_join(m.philos[i++].tid, NULL);
	destroy_monitor(&m);
}
