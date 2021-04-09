/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:54:42 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 22:03:06 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_size	lst_size(const t_list *sentinel)
{
	const t_list	*tmp = sentinel->next;
	t_size			size;

	size = 0;
	while (tmp != sentinel)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
