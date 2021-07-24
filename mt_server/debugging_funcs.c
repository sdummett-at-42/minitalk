/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:57:50 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/24 19:58:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_server.h"

void	print_bits(t_char_byte *byte)
{
	int i;
	
	i  = 31;
	printf(">>");
	while (byte != NULL)
	{
		printf("%d", byte->bit);
		if (i == 24 || i == 16 || i == 8)
			printf(" ");
		byte = byte->next;
		i--;
	}
	printf("<<\n");
}