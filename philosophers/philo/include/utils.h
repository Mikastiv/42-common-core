/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:34:55 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/24 22:12:01 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

void	ft_putstr_fd(const char *str, int fd);
int		quit_error(const char *msg);
long	time_ms(void);
void	print_status(t_philo *philo, t_state state);
bool	ph_sleep(long time, t_philo *philo);
int		*create_queue(int philo_count);
void	rotate_queue(int *queue, int size);
#endif
