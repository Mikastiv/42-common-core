/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:26:55 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/26 04:18:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}

static bool	is_digits(const char *str)
{
	if (*str == '-' || *str == '+')
		++str;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		++str;
	}
	return (true);
}

char	*parse_input(int argc, char **argv, t_options *opts)
{
	if (!(argc == 5 || argc == 6))
		return ("usage: ./philo number_of_philosophers time_to_die\
 time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]");
	opts->philo_count = ft_atoi(argv[1]);
	opts->time_to_die = ft_atoi(argv[2]);
	opts->time_to_eat = ft_atoi(argv[3]);
	opts->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		opts->eat_count = ft_atoi(argv[5]);
	else
		opts->eat_count = -1;
	if (opts->philo_count <= 0 || !is_digits(argv[1]))
		return ("number_of_philosophers must be > 0");
	if (opts->time_to_die <= 0 || !is_digits(argv[2]))
		return ("time_to_die must be > 0");
	if (opts->time_to_eat <= 0 || !is_digits(argv[3]))
		return ("time_to_eat must be > 0");
	if (opts->time_to_sleep <= 0 || !is_digits(argv[4]))
		return ("time_to_sleep must be > 0");
	if (argc == 6 && (opts->eat_count <= 0 || !is_digits(argv[5])))
		return ("number_of_times_each_philosopher_must_eat must be > 0");
	return (NULL);
}
