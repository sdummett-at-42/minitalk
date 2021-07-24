/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str_to_bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:26:20 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/24 22:52:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

t_char_byte	*char_to_bits(int n)
{
	int			i;
	int			bit_shifted;
	t_char_byte	*byte;
	t_char_byte	*tmp;

	byte = new_linked_lst();
	tmp = byte;
	bit_shifted = 1;
	i = 31;
	while (i >= 0)
	{
		if (bit_shifted << i & n)
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
		usleep(225);
		byte = byte->next;
	}
}

int	decompose_str(const char *str, int pid)
{
	t_char_byte *byte;

	byte = NULL;
	while (*str != '\0')
	{
		byte = char_to_bits(*str);
		if (byte == NULL)
			return (-1);
//		print_bits(byte);
		send_byte(byte, pid);
		free_linked_lst(byte);
		str++;
	}
	byte = char_to_bits(0);
	if (byte == NULL)
		return (-1);
//	print_bits(byte);
	send_byte(byte, pid);
	free_linked_lst(byte);
	return (0);
}