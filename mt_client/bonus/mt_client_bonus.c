/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:59:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/29 23:58:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client_bonus.h"

/*
** SIGUSR1 : 0
** SIGUSR2 : 1
*/

void	send_bytes(unsigned int c, int pid, int ispid)
{
	int			i;

	i = 31;
	while (i >= 0)
	{
		if (1 << i & c)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		if (ispid == 1)
			usleep(200);
		else
			pause();
		i--;
	}
}

int	convert_each_byte(const char *str, int pid)
{
	send_bytes((unsigned int)getpid(), pid, 1);
	while (*str != '\0')
	{
		send_bytes(*(unsigned int *)str, pid, 0);
		str++;
	}
	send_bytes('\0', pid, 0);
	return (0);
}

void	sighandler(int signo)
{
	if (signo == SIGUSR1)
	{
		ft_putstr(">>>Message received<<<\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	sa.sa_handler = &sighandler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ac != 3)
	{
		ft_putstr("The client required 2 args.\n");
		ft_putstr("Usage: ./client [server_pid] [string_to_print]\n");
		return (0);
	}
	if (convert_each_byte(av[2], ft_atoi(av[1])) == -1)
	{
		ft_putstr("Error.\n");
		return (-1);
	}
	return (0);
}
