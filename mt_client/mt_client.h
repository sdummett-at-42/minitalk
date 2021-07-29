/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:34:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/29 13:48:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_CLIENT_H
# define MT_CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void		ft_putstr(char *str);
int			ft_atoi(const char *str);
int			convert_each_byte(const char *str, int pid);

#endif