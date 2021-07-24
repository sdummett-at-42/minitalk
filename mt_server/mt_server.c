/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:39:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/24 22:30:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_server.h"

void	sighandler(int signo)
{
	static int	i = 31;
	static int	c = 0;

	if (signo == SIGUSR2)
		c = c | (1 << i);
	i--;
	if (i < 0)
	{
		write(1, &c, 1);
		if (c == '\0')
			ft_putstr("\n>>>Message received.<<<\n");
		i = 31;
		c = 0;
	}
}

int main()
{
	char	*str;
	struct sigaction sa;

	ft_putstr("PID : ");
	str = ft_itoa(getpid());
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
	sa.sa_handler = &sighandler;
	sa.sa_flags = SA_RESTART;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}