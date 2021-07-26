/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 19:39:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/26 14:50:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_SERVER_BONUS_H
# define MT_SERVER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_char_byte
{
	unsigned char		bit;
	struct s_char_byte	*next;
}				t_char_byte;

int		ft_atoi(const char *str);
void	print_bits(t_char_byte *byte);
void	ft_putstr(char *str);
char	*ft_itoa(int n);

#endif