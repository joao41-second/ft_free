/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:33:39 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/13 16:30:30 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_and_list.h" 

void	*ft_malloc(size_t size, void *pocket)
{
	t_list_ *list;
	t_list_* new_node;
	t_list_ *pocket_setd;
	t_free_list *pocket_var;

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
	pocket_var = new_node->content;
	return (pocket_var->memory);
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
}

void	ft_free(void *var, void *list_set)
{
	t_list_	*list;
	t_list_			*temp;
	t_free_list *pocket;

	list_set = NULL;
	list = get_list_free(START);
	temp = list;
	while (list != NULL)
	{
		pocket = list->content;
		if (pocket->memory == var)
		{
			free_struct_free(list->content);
			list->content = NULL;
			var = NULL;
			list = free_next(list);
			break ;
		}
		list = list->next;
	}
	list = temp;
}

void ft_free_all_pocket(char *name_pocket)
{
	t_list_	*list;
	t_free_list *pocket;

	list = get_list_free(START);
	while (list != NULL)
	{
		pocket = list->content;
		if(ff_strncmp(pocket->pocket, name_pocket, ff_strlen(pocket->pocket)+10) == 0)
		{

			free_struct_free(list->content);
			list->content = NULL;
			list = free_next(list);
		}
		list = list->next;
	}
}

void	start_alloc(void)
{
	 get_list_free(0);
	 get_pocket_list(0, NULL);
}
