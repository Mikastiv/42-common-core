/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:14:08 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/20 10:34:45 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#define NONE 0
#define BIT_RECEIVED 1
#define MESSAGE_END 2

volatile sig_atomic_t data[2] = { NONE, NONE };

void build_message(char c)
{
    static t_string msg = (t_string){ NULL, 0, 0 };

    if (c == '\0') {
        ft_putendl_fd(msg.data, STDOUT_FILENO);
        ft_str_free(&msg);
        data[0] = MESSAGE_END;
    } else {
        data[0] = BIT_RECEIVED;
        ft_str_push(&msg, c);
    }
}

void handler(int signo, siginfo_t* info, void* ctx)
{
    static char c;
    static int bit = 0;

    (void)ctx;
    data[1] = info->si_pid;
    if (bit == 0) {
        c = 0;
        bit = sizeof(char) * 8;
    }
    --bit;
    if (signo == SIGUSR1)
        c |= (1 << bit);
    if (bit == 0) {
        build_message(c);
    } else {
        data[0] = BIT_RECEIVED;
    }
}

int main(int argc, char** argv)
{
    struct sigaction action_recv;

    if (argc != 1) {
        ft_putstr_fd("usage: ", STDERR_FILENO);
        ft_putstr_fd(argv[0], STDERR_FILENO);
        ft_putstr_fd("\n", STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    ft_putnbr_fd(getpid(), STDOUT_FILENO);
    ft_putstr_fd("\n", STDOUT_FILENO);
    action_recv.sa_sigaction = &handler;
    action_recv.sa_flags = SA_SIGINFO;
    sigemptyset(&action_recv.sa_mask);
    sigaction(SIGUSR1, &action_recv, NULL);
    sigaction(SIGUSR2, &action_recv, NULL);
    while (true) {
        while (data[0] == NONE)
            ;
        if (data[0] == BIT_RECEIVED) {
            data[0] = NONE;
            kill(data[1], SIGUSR1);
        } else {
            data[0] = NONE;
            kill(data[1], SIGUSR2);
        }
    }
}
