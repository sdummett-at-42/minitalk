/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:39:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/26 13:34:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_server.h"

void	sighandler(int signo)
{
	static int				i = 7;
	static unsigned char	c = 0;

	if (signo == SIGUSR2)
		c = c | (1 << i);
	i--;
	if (i < 0)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		i = 7;
		c = 0;
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
