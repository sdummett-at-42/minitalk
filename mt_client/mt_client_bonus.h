/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:34:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/26 14:50:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_CLIENT_BONUS_H
# define MT_CLIENT_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_char_byte
{
	unsigned char		bit;
	struct s_char_byte	*next;
}				t_char_byte;

char		*ft_strdup(const char *str);
void		ft_putstr(char *str);
int			ft_atoi(const char *str);
t_char_byte	*new_linked_lst(void);
void		free_linked_lst(t_char_byte *lst);
t_char_byte	*char_to_bits(int c);
int			convert_each_byte(const char *str, int pid);

#endif