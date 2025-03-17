/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:16:04 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/17 11:04:27 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h"
#include "lsit_struct.h"
#include <unistd.h>

t_list_	*ft_node_new_free(void *n)
{
	t_list_	*new_node;

	if (n == NULL)
		return (NULL);
	new_node = (t_list_ *)malloc(1 * sizeof(t_list_));
	if (new_node == NULL)
		return (NULL);
	new_node->content = n;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void	ft_remove(t_list_ **node)
{
	t_list_	*prv;
	t_list_	*temp;

	temp = *node;
	prv = temp->previous;
	prv->next = NULL;
	free(*node);
	*node = prv;
}

void	ft_emove(t_list_ **node)
{
	t_list_	*prv;
	t_list_	*nex;
	t_list_	*temp;

	temp = *node;
	nex = temp->next;
	prv = temp->previous;
	nex->previous = prv;
	prv->next = nex;
	free(*node);
	*node = prv;
}

t_list_	*free_next(t_list_ *list)
{
	if (list->next == NULL )
	{
		ft_remove(&list);
	}
	else if (list->next != NULL && list->previous != NULL)
		ft_emove(&list);
	return (list);
}

void	*ft_add_memory(void *memory, char *pocket)
{
	t_list_		*new_node;
	t_free_list	*node;
	t_list_		*list;

	if (chek_pocket_in_list(pocket) == TRUE || pocket == NULL)
	{
		node = malloc(1 *(sizeof(t_free_list)));
		if (node == NULL)
			ft_free_all();
		if (pocket == NULL)
			node->pocket = ff_strdup("main");
		else
			node->pocket = ff_strdup(pocket);
		if (node == NULL)
			return (free(node), ft_free_all(), NULL);
		node->memory = memory;
	}
	list = get_list_free(END);
	if (pocket == NULL)
		new_node = ft_node_new_free(node);
	else if (chek_pocket_in_list(pocket) == TRUE)
		new_node = ft_node_new_free(node);
	else
		return (write(2, "error: pocket not valid\n", 25), NULL);
	return (ff_node_add_front(&list, new_node), memory);
}
