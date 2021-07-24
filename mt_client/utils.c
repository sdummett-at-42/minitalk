/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:35:45 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/24 19:31:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	nb;

	nb = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - 48;
		str++;
		if (sign < 0 && nb > 2147483648)
			return (0);
		if (sign > 0 && nb > 2147483647)
			return (-1);
	}
	return (nb * sign);
}

void	init_link(t_char_byte *new)
{
	new->bit = 0;
	new->next = NULL;
}

void	free_linked_lst(t_char_byte *lst)
{
	t_char_byte	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

t_char_byte *new_linked_lst(void)
{
	int i;
	t_char_byte *new;
	t_char_byte	*tmp;

	new = malloc(sizeof(t_char_byte));
	if (new == NULL)
		return (NULL);
	init_link(new);
	tmp = new;
	i = 0;
	while (i < 31)
	{
		tmp->next = malloc(sizeof(t_char_byte));
		if (tmp->next == NULL)
		{
			//free_linked_lst(new);
			return (NULL);
		}
		init_link(tmp->next);
		tmp = tmp->next;
		i++;
	}
	return (new);
}

int ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char *ft_strdup(const char *str)
{
	int i;
	char *ptr;

	ptr = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (*(str + i))
	{
		*(ptr + i) = *(str + i);
		i++;
	}
	*(ptr + i) = 0;
	return (ptr);
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}