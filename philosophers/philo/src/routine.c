/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 22:59:06 by mleblanc          #+#    #+#             */
/*   Updated: 2021/10/15 23:44:26 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>

bool	is_over(t_monitor *m)
{
	bool	over;

	pthread_mutex_lock(&m->lock);
	over = m->gameover;
	pthread_mutex_unlock(&m->lock);
	return (over);
}

void	set_gameover_dead(t_philo *philo)
{
	bool	over;

	pthread_mutex_lock(&philo->m->lock);
	over = philo->m->gameover;
	philo->m->gameover = true;
	pthread_mutex_unlock(&philo->m->lock);
	if (!over)
		print_status(philo, dead);
}

void	philo_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->m->lock);
	philo->m->n_done_eating++;
	if (philo->m->n_done_eating == philo->m->opts.philo_count)
		philo->m->gameover = true;
	pthread_mutex_unlock(&philo->m->lock);
}

static bool	routine(t_philo *philo)
{
	if (!philo_take_forks(philo))
		return (false);
	if (!philo_eat(philo))
		return (false);
	if (is_over(philo->m))
		return (false);
	if (!philo_sleep(philo))
		return (false);
	if (is_over(philo->m))
		return (false);
	print_status(philo, thinking);
	return (true);
}

void	*philo_cycle(void *data)
{
	t_philo	*philo;

	philo = data;
	while (true)
	{
		if (is_over(philo->m))
			return (NULL);
		if (philo_is_dead(philo))
		{
			set_gameover_dead(philo);
			return (NULL);
		}
		if (philo->m->queue[0] != philo->id)
		{
			usleep(SLEEP_INTERVAL);
			continue ;
		}
		if (!routine(philo))
			return (NULL);
	}
	return (NULL);
}
