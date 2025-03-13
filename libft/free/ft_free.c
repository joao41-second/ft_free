/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:33:39 by jperpct           #+#    #+#             */
/*   Updated: 2024/11/29 14:24:24 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_and_list.h" 

void	*ft_malloc(size_t size, void *pocket)
{
	t_list_ *list;
	t_list_* new_node;
	t_list_ *pocket_setd;
	list= get_list_free(END);
	pocket_setd = get_pocket_list(SETD, NULL);
	if(pocket_setd == NULL)
		ft_free_all(NULL);	
	if(pocket == NULL)
		new_node = ft_node_new_free(inicializ_struct_free(ff_strdup( get_pocket_list(SETD, NULL)->content), size));
	else if(chek_pocket_in_list(pocket) == TRUE)
		new_node = ft_node_new_free(inicializ_struct_free(ff_strdup(pocket), size));
	else 
		return (write(2,"error: pocket not valid\n",25),NULL);
	if(new_node->content == NULL)
		ft_free_all(NULL);	
	ft_node_add_front(&list, new_node);
	return (new_node->content);
}

void	ft_free_all(void *list_set)
{
	t_list_	*list;
	t_list_			*temp;
	(void)list_set;

	list = get_list_free(START);

	while (list != NULL)
	{
		temp = list->next;
		if (list->content != NULL)
			free_struct_free(list->content);
		free(list);
		list = temp;
	}
	list = get_pocket_list(START, NULL);
	while (list != NULL)
	{
		temp = list->next;
		if (list->content != NULL)
			free(list->content);
		free(list);
		list = temp;
	}
	get_pocket_list(FREE,NULL);
}

void	ft_free(void *var, void *list_set)
{
	static t_list_	*list;
	t_list_			*temp;

	if (list == NULL && list_set != NULL)
	{
		list = list_set;
		return ;
	}
	temp = list;
	while (list != NULL)
	{
		if (list->content == var)
		{
			free(list->content);
			list->content = NULL;
			var = NULL;
			list = free_next(list);
			break ;
		}
		list = list->next;
	}
	list = temp;
}

void	start_alloc(void)
{

	 get_list_free(0);
	 get_pocket_list(0, NULL);
	//t_list_	*list;

	//list = ft_node_new_free(malloc(sizeof(t_list_)));
	//ft_malloc(3, list);
	//ft_free_all(list);
	//ft_free(NULL, list);
}
