/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pocket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:53:21 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/12 14:55:20 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_and_list.h" 
#include <stdlib.h>

int ff_strlen(char *str)
{
	int i;
	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

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
	char *copy;
	int i;

	i=-1;
	node = malloc(sizeof(t_free_list)*1);
	if(node == NULL)
		return(NULL);
	if(size > 0)
		node->memory = malloc(size);
	else
		return (free(node),NULL);
	copy = malloc(ff_strlen(str)+1*sizeof(char));
	if(copy == NULL)	
		return (free(node->memory),free(node), NULL);	
	node->pocket = str;
	while (str[++i] != '\0') 
	 copy[i] = str[i];
	copy[i]= '\0';
	return (node);
}

t_list_* get_list_free(int n)
{
	static t_list_ * list;
	if(list == NULL)
	{
		list = ft_node_new_free(inicializ_struct_free("main", 5));
		if(list->content == NULL)
		{
			free(list);
			return (NULL);
		}
	}
	if(n == END)
		list = ft_node_end(list);
	if(n == START)
		list = ft_node_start(list);
	return(list);
}
