/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:57:08 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/17 11:04:50 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h"

void	ff_node_add_front(t_list_ **lst, t_list_ *new_)
{
	t_list_	*temp;

	if (lst == NULL || new_ == NULL)
		return ;
	new_->previous = *lst;
	temp = *lst;
	temp->next = new_;
	*lst = new_;
}

t_list_	*ff_node_start(t_list_ *list)
{
	if (list->previous != NULL)
	{
		while (list != NULL)
		{
			if (list->previous == NULL)
				break ;
			list = list->previous;
		}
	}
	return (list);
}

t_list_	*ff_node_end(t_list_ *list)
{
	if (list->next != NULL)
	{
		while (list != NULL)
		{
			if (list->next == NULL)
				break ;
			list = list->next;
		}
	}
	return (list);
}

void	ft_start_alloc(void)
{
	get_list_free(0);
	get_pocket_list(0, NULL);
}
