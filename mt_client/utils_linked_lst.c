/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:12:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/26 13:27:44 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt_client.h"

void	init_linked_lst(t_char_byte *new)
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

t_char_byte	*new_linked_lst(void)
{
	int			i;
	t_char_byte	*new;
	t_char_byte	*tmp;

	new = malloc(sizeof(t_char_byte));
	if (new == NULL)
		return (NULL);
	init_linked_lst(new);
	tmp = new;
	i = 0;
	while (i < 7)
	{
		tmp->next = malloc(sizeof(t_char_byte));
		if (tmp->next == NULL)
		{
			free_linked_lst(new);
			return (NULL);
		}
		init_linked_lst(tmp->next);
		tmp = tmp->next;
		i++;
	}
	return (new);
}
