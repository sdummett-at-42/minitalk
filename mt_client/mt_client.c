/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:59:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/29 13:05:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

/*
** SIGUSR1 : 0
** SIGUSR2 : 1
*/

void	send_byte(unsigned char c, int pid)
{
	int			i;

	i = 7;
	while (i >= 0)
	{
		if (1 << i & c)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(30);
		i--;
	}
}

int	convert_each_byte(const char *str, int pid)
{
	while (*str != '\0')
	{
		send_byte(*str, pid);
		str++;
	}
	send_byte('\0', pid);
	return (0);
}

int	main(int ac, char **av)
{
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
