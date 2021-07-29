/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:59:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/29 23:57:40 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

/*
** SIGUSR1 : 0
** SIGUSR2 : 1
*/

void	send_bytes(unsigned char c, int pid)
{
	int			i;

	i = 7;
	while (i >= 0)
	{
		if (1 << i & c)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		i--;
	}
}

void	send_pid(unsigned int c, int pid)
{
	int			i;

	i = 31;
	while (i >= 0)
	{
		if (1 << i & c)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		i--;
	}
}

int	convert_each_byte(const char *str, int pid)
{
	send_pid((unsigned int)getpid(), pid);
	while (*str != '\0')
	{
		send_bytes(*(unsigned int *)str, pid);
		str++;
	}
	send_bytes('\0', pid);
	return (0);
}

void	sighandler(int signo)
{
	(void)signo;
	return ;
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
