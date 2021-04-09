/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:15:15 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 21:19:50 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list	*lst_at(const t_list *sentinel, int index)
{
	const t_list	*tmp = sentinel;

	while (index--)
	{
		tmp = tmp->next;
		if (tmp == sentinel)
			return (NULL);
	}
	return ((t_list *)tmp);
}
