/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:35:47 by mleblanc          #+#    #+#             */
/*   Updated: 2021/10/15 23:41:54 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr_fd(const char *str, int fd)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		++len;
	write(fd, str, len);
}

int	quit_error(const char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

long	time_ms(void)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec * 1000) + (curr.tv_usec / 1000));
}

void	print_status(t_philo *philo, t_state state)
{
	long	timestamp;

	timestamp = time_ms() - philo->m->start_time;
	pthread_mutex_lock(&philo->m->wlock);
	if (state != dead && is_over(philo->m))
	{
		pthread_mutex_unlock(&philo->m->wlock);
		return ;
	}
	if (state == eating)
	{
		printf("%ld %d %s\n", timestamp, philo->id, "has taken a fork");
		printf("%ld %d %s\n", timestamp, philo->id, "has taken a fork");
		printf("%ld %d %s\n", timestamp, philo->id, "is eating");
	}
	else if (state == thinking)
		printf("%ld %d %s\n", timestamp, philo->id, "is thinking");
	else if (state == sleeping)
		printf("%ld %d %s\n", timestamp, philo->id, "is sleeping");
	else if (state == dead)
		printf("%ld %d %s\n", timestamp, philo->id, "died");
	pthread_mutex_unlock(&philo->m->wlock);
}

bool	ph_sleep(long time, t_philo *philo)
{
	long	start;

	start = time_ms();
	while ((time_ms() - start) < time)
	{
		if (philo_is_dead(philo))
		{
			set_gameover_dead(philo);
			return (false);
		}
		usleep(SLEEP_INTERVAL);
	}
	return (true);
}
