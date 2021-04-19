/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:36:48 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 21:11:04 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

static t_list	*lst_new_element(void *data, t_size size)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->data.first = malloc(size);
	if (!new_element->data.first)
	{
		free(new_element);
		new_element = NULL;
		return (NULL);
	}
	ft_memcpy(new_element->data.first, data, size);
	new_element->data.second = (void *)size;
	return (new_element);
}

int	lst_push_front(t_list *sentinel, void *data, t_size size)
{
	t_list	*new_element;

	new_element = lst_new_element(data, size);
	if (!new_element)
		return (-1);
	new_element->prev = sentinel;
	new_element->next = sentinel->next->next;
	if (new_element->next == sentinel)
		new_element = sentinel->next;
	new_element->next->prev = new_element;
	sentinel->next = new_element;
	return (0);
}

int	lst_push_back(t_list *sentinel, void *data, t_size size)
{
	t_list	*new_element;

	new_element = lst_new_element(data, size);
	if (!new_element)
		return (-1);
	new_element->next = sentinel;
	new_element->prev = sentinel->prev->prev;
	if (new_element->prev == sentinel)
		new_element = sentinel->prev;
	new_element->prev->next = new_element;
	sentinel->prev = new_element;
	return (0);
}
