/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 22:05:19 by mleblanc          #+#    #+#             */
/*   Updated: 2021/10/15 23:44:49 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

bool	philo_is_dead(t_philo *philo)
{
	return (time_ms() - philo->last_eat >= philo->m->opts.time_to_die);
}

static bool	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	*philo->fork1_s = true;
	pthread_mutex_lock(philo->fork2);
	*philo->fork2_s = true;
	rotate_queue(philo->m->queue, philo->m->opts.philo_count);
	if (philo_is_dead(philo))
	{
		*philo->fork1_s = false;
		pthread_mutex_unlock(philo->fork1);
		*philo->fork1_s = false;
		pthread_mutex_unlock(philo->fork2);
		set_gameover_dead(philo);
		return (false);
	}
	return (true);
}

bool	philo_take_forks(t_philo *philo)
{
	while (*philo->fork1_s || *philo->fork2_s)
	{
		if (philo_is_dead(philo))
		{
			set_gameover_dead(philo);
			return (false);
		}
		usleep(SLEEP_INTERVAL);
	}
	return (pick_forks(philo));
}

bool	philo_eat(t_philo *philo)
{
	philo->last_eat = time_ms();
	print_status(philo, eating);
	if (!ph_sleep(philo->m->opts.time_to_eat, philo))
	{
		*philo->fork1_s = false;
		pthread_mutex_unlock(philo->fork1);
		*philo->fork2_s = false;
		pthread_mutex_unlock(philo->fork2);
		return (false);
	}
	*philo->fork1_s = false;
	pthread_mutex_unlock(philo->fork1);
	*philo->fork2_s = false;
	pthread_mutex_unlock(philo->fork2);
	++philo->eat_count;
	if (philo->eat_count == philo->m->opts.eat_count)
		philo_done(philo);
	return (true);
}

bool	philo_sleep(t_philo *philo)
{
	print_status(philo, sleeping);
	if (!ph_sleep(philo->m->opts.time_to_sleep, philo))
		return (false);
	return (true);
}
