/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_f_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:59:42 by jperpect          #+#    #+#             */
/*   Updated: 2024/11/05 11:05:20 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_and_list.h"

void	ft_add_node_list(t_list_ **list, void *content)
{
	t_list_	*new;

	new = ft_node_new(content);
	*list = ft_node_end(*list);
	ft_node_add_front(list, new);
}

void	ft_node_add_inver(t_list_ **lst, t_list_ *new)
{
	t_list_	*temp;

	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	temp = *lst;
	temp->previous = new;
	*lst = new;
}

t_list_	*ft_node_end(t_list_ *list)
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

int	ft_list_size(t_list_ *list)
{
	int	i;

	list = ft_node_start(list);
	i = 0;
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	*get_list(t_list_ *list, void	*loc,
			void	*(*locate_node)(void*, void*))
{
	void	*ret;

	ret = NULL;
	list = ft_node_start(list);
	while (list != NULL)
	{
		ret = (locate_node)(list, loc);
		if (ret != NULL)
			return (ret);
		if (list->next != NULL)
			list = list->next;
		else
			break ;
	}
	return (NULL);
}
