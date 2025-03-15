/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:09:12 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/14 23:09:37 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h"

void free_struct_free(t_free_list *node)
{
	free(node->memory);
	free(node->pocket);
	free(node);
	node = NULL;
}

t_free_list * inicializ_struct_free(char *str,size_t size)
{
	t_free_list *node;

	if(str == NULL)
		return (NULL);
	node = malloc(sizeof(t_free_list)*1);
	if(node == NULL)
		return(NULL);
	if(size > 0)
		node->memory = malloc(size);
	else
		return (free(node),NULL);
	node->pocket = str;
	return (node);
}


t_list_* get_list_free(int n)
{
	static t_list_ * list;
	t_free_list *list_free;
	if(list == NULL)
	{
		list_free = inicializ_struct_free(ff_strdup("main"), 5);
		if(list_free == NULL)
			return (NULL);
		list = ft_node_new_free(list_free);
		if(list->content == NULL)
		{
			free(list);
			return (NULL);
		}
	}
	if(n == END)
		list = ff_node_end(list);
	if(n == START)
		list = ff_node_start(list);
	return(list);
}
