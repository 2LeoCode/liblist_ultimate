/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:01:24 by lsuardi           #+#    #+#             */
/*   Updated: 2021/04/09 22:27:30 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

static void	update_smallest_if_head_lower(t_list **smallest, t_list *head,
				t_cmpf cmp_fun)
{
	t_size	cmp_size;
	int		cmp_ret;

	if ((t_size)head->data.second > (t_size)(*smallest)->data.second)
		cmp_size = (t_size)(*smallest)->data.second;
	else
		cmp_size = (t_size)head->data.second;
	cmp_ret = (*cmp_fun)(head->data.first, (*smallest)->data.first,
			cmp_size);
	if (cmp_ret <= 0)
		*smallest = head;
}

void	lst_sort(t_list *sentinel, t_cmpf cmp_fun)
{
	t_list	*smallest;
	t_list	*iterator;
	t_list	*head;

	iterator = sentinel->next;
	while (iterator != sentinel)
	{
		smallest = iterator;
		head = iterator->next;
		while (head != sentinel)
		{
			update_smallest_if_head_lower(&smallest, head, cmp_fun);
			head = head->next;
		}
		ft_swap(&smallest->data, &iterator->data, sizeof(t_pair));
		iterator = iterator->next;
	}
}
