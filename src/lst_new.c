/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:32:02 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 20:52:53 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list	*lst_new(void)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->next = new_list;
	new_list->prev = new_list;
	new_list->size = 0L;
	return (new_list);
}

int	lst_init(t_list **empty_data)
{
	*empty_data = lst_new();
	return (!*empty_data * -1);
}
