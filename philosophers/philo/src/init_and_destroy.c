/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 23:10:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/10/15 23:34:58 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

static t_philo	*init_philos(t_monitor *m)
{
	int		i;
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * (m->opts.philo_count + 1));
	i = 0;
	while (i < m->opts.philo_count)
	{
		philos[i].id = i + 1;
		philos[i].m = m;
		philos[i].fork1 = &m->forks[i];
		philos[i].fork2 = &m->forks[(i + 1) % m->opts.philo_count];
		philos[i].fork1_s = &m->forks_s[i];
		philos[i].fork2_s = &m->forks_s[(i + 1) % m->opts.philo_count];
		philos[i].last_eat = m->start_time;
		philos[i].eat_count = 0;
		++i;
	}
	return (philos);
}

void	init_monitor(t_monitor *m)
{
	int	i;

	pthread_mutex_init(&m->lock, NULL);
	pthread_mutex_init(&m->wlock, NULL);
	m->forks = malloc(sizeof(pthread_mutex_t) * m->opts.philo_count);
	m->forks_s = malloc(sizeof(bool) * m->opts.philo_count);
	i = 0;
	while (i < m->opts.philo_count)
	{
		pthread_mutex_init(&m->forks[i], NULL);
		m->forks_s[i] = false;
		++i;
	}
	if (m->opts.eat_count == -1)
		m->stop_at_count = false;
	else
		m->stop_at_count = true;
	m->gameover = false;
	m->n_done_eating = 0;
	m->queue = create_queue(m->opts.philo_count);
	m->start_time = time_ms();
	m->philos = init_philos(m);
}

void	destroy_monitor(t_monitor *m)
{
	int	i;

	i = 0;
	while (i < m->opts.philo_count)
	{
		pthread_mutex_destroy(&m->forks[i]);
		++i;
	}
	pthread_mutex_destroy(&m->lock);
	pthread_mutex_destroy(&m->wlock);
	free(m->philos);
	free(m->forks);
	free(m->forks_s);
	free(m->queue);
}
