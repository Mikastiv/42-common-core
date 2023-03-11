/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:17:14 by mleblanc          #+#    #+#             */
/*   Updated: 2021/10/15 23:41:07 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>

# define SLEEP_INTERVAL 25

typedef struct s_options
{
	int	philo_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_count;
}	t_options;

typedef enum e_state
{
	thinking,
	taking_fork,
	eating,
	sleeping,
	dead,
}	t_state;

typedef struct s_philo
{
	int					id;
	pthread_t			tid;
	pthread_mutex_t		*fork1;
	pthread_mutex_t		*fork2;
	bool				*fork1_s;
	bool				*fork2_s;
	long				last_eat;
	int					eat_count;
	struct s_monitor	*m;
}	t_philo;

typedef struct s_monitor
{
	long			start_time;
	bool			gameover;
	int				n_done_eating;
	t_options		opts;
	bool			stop_at_count;
	t_philo			*philos;
	pthread_mutex_t	lock;
	pthread_mutex_t	wlock;
	pthread_mutex_t	*forks;
	bool			*forks_s;
	int				*queue;
}	t_monitor;

char	*parse_input(int argc, char **argv, t_options *opt);
void	init_monitor(t_monitor *m);
void	destroy_monitor(t_monitor *m);
void	*philo_cycle(void *data);
void	set_gameover_dead(t_philo *philo);
bool	is_over(t_monitor *m);
bool	philo_is_dead(t_philo *philo);
bool	philo_take_forks(t_philo *philo);
bool	philo_eat(t_philo *philo);
bool	philo_sleep(t_philo *philo);
void	philo_done(t_philo *philo);

#endif
