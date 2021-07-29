/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:39:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/29 23:23:37 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_server_bonus.h"

void	sighandler(int signo)
{
	static int	pid = 0;
	static int	i = 31;
	static int	c = 0;

	if (signo == SIGUSR2)
		c = c | (1 << i);
	i--;
	if (i < 0)
	{
		if (pid == 0)
			pid = c;
		else
			write(1, &c, 1);
		if (c == '\0')
		{
			write(1, "\n", 1);
			usleep(150);
			kill(pid, SIGUSR1);
			pid = 0;
			i = 31;
			c = 0;
			return ;
		}
		i = 31;
		c = 0;
	}
	if (pid != 0)
	{
		usleep(30);
		kill(pid, SIGUSR2);
	}
}

int	main(void)
{
	char				*str;
	struct sigaction	sa;

	sa.sa_handler = &sighandler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID : ");
	str = ft_itoa(getpid());
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
	while (1)
	{
	}
	return (0);
}
