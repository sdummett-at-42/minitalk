/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:59:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/25 17:56:11 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

t_char_byte	*char_to_bits(int n)
{
	int			i;
	t_char_byte	*byte;
	t_char_byte	*tmp;

	byte = new_linked_lst();
	tmp = byte;
	i = 31;
	while (i >= 0)
	{
		if (1 << i & n)
			tmp->bit = 1;
		else
			tmp->bit = 0;
		tmp = tmp->next;
		i--;
	}
	return (byte);
}

/*
** SIGUSR1 : 0
** SIGUSR2 : 1
*/

void	send_byte(t_char_byte *byte, int pid)
{
	while (byte != NULL)
	{
		if (byte->bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(30);
		byte = byte->next;
	}
}

int	convert_each_byte(const char *str, int pid)
{
	t_char_byte	*byte;

	byte = NULL;
	byte = char_to_bits(getpid());
	if (byte == NULL)
		return (-1);
	send_byte(byte, pid);
	free_linked_lst(byte);
	while (*str != '\0')
	{
		byte = char_to_bits(*str);
		if (byte == NULL)
			return (-1);
		send_byte(byte, pid);
		free_linked_lst(byte);
		str++;
	}
	byte = char_to_bits(0);
	if (byte == NULL)
		return (-1);
	send_byte(byte, pid);
	pause();
	free_linked_lst(byte);
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
	sigaction(SIGUSR1, &sa, NULL);
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
