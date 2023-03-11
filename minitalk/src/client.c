/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:14:11 by mleblanc          #+#    #+#             */
/*   Updated: 2021/07/27 12:41:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t response = 0;

void send_char(char c, pid_t spid)
{
    int bit = 0;
    int res;

    bit = sizeof(char) * 8;
    while (bit) {
        --bit;
        if (c & (1 << bit))
            res = kill(spid, SIGUSR1);
        else
            res = kill(spid, SIGUSR2);
        if (res < 0) {
            ft_putendl_fd("Bad server pid", STDERR_FILENO);
            exit(EXIT_FAILURE);
        }
        while (response != 1)
            ;
        response = 0;
    }
}

void ack(int signo)
{
    (void)signo;
    response = 1;
}

void quit(int signo)
{
    (void)signo;
    ft_putendl_fd("Message received", STDOUT_FILENO);
    exit(EXIT_SUCCESS);
}

void send_message(const char* msg, pid_t spid)
{
    while (*msg) {
        send_char(*msg, spid);
        ++msg;
    }
    send_char(*msg, spid);
}

int main(int argc, char** argv)
{
    struct sigaction action_sent;
    struct sigaction action_ack;
    pid_t spid;

    if (argc != 3) {
        ft_putstr_fd("usage: ", STDERR_FILENO);
        ft_putstr_fd(argv[0], STDERR_FILENO);
        ft_putstr_fd(" <server pid> <message>\n", STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    spid = ft_atoi(argv[1]);
    action_sent.sa_handler = &ack;
    action_sent.sa_flags = 0;
    sigemptyset(&action_sent.sa_mask);
    sigaction(SIGUSR1, &action_sent, NULL);
    action_ack.sa_handler = &quit;
    action_ack.sa_flags = 0;
    sigemptyset(&action_ack.sa_mask);
    sigaction(SIGUSR2, &action_ack, NULL);
    send_message(argv[2], spid);
    pause();
}
