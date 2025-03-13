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

int	ff_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while ((s1[a] != '\0' && s2[a] != '\0') && a < n - 1)
	{
		if (s1[a] != s2[a])
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

char *ff_strdup(char *str)
{
	char *dup;
	int i;

	i = -1;
	dup = malloc(ff_strlen(str)+1*sizeof(char));
	if(dup == NULL)
		return (NULL);
	while (str[++i] != '\0') 
	 dup[i] = str[i];
	dup[i]= '\0';
	return (dup);	
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
	t_free_list *list_free;
	if(list == NULL)
	{
		list_free = inicializ_struct_free("main", 5);
		if(list_free == NULL)
			return (NULL);
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

int chek_pocket_in_list(char *name)
{

	static t_list_ *list_pocket;
	get_pocket_list(START, NULL);
	while (list_pocket != NULL) 
	{
		if(ff_strncmp(list_pocket->content, name, ff_strlen(list_pocket->content)+10) == 0)
			return (TRUE);
		list_pocket = list_pocket->next;
	}
	return (FALSE);
}

t_list_ *get_pocket_list(int n,char *set)
{
	static t_list_ *list_pocket;
	static char *setd;
	char *star;
	if( list_pocket == NULL)
	{
		star = ff_strdup("main");
		if(star == NULL)
			return NULL;
		setd = ff_strdup("main");
		if(star == NULL)
			return NULL;
		list_pocket = ft_node_new_free(star);
		if(list_pocket == NULL)
			return(free(list_pocket),NULL);
	}
	if(n == END)
		list_pocket = ft_node_end(list_pocket);
	if(n == START)
		list_pocket = ft_node_start(list_pocket);
	if(n == SETD && set != NULL)
	{
		free(setd);
		setd = set;
	}
	list_pocket = ft_node_start(list_pocket);
	if(n == SETD && set == NULL ){
		while (list_pocket != NULL) 
		{

			if(ff_strncmp(list_pocket->content, setd, ff_strlen(list_pocket->content)+10) == 0)
				break;
			if(list_pocket->next == NULL)
				break;
			list_pocket = list_pocket->next;
		}}
	return (list_pocket);
}

void pocket_new(char *name)
{
	t_list_ *list_pocket;
	t_list_ *new_node;
	char *dup;
	dup = ff_strdup(name);
	if(dup == NULL)
		return;
	list_pocket = get_pocket_list(START,NULL);
	if(chek_pocket_in_list(name) == TRUE)
	{
		write(2,"error: this pocket name is used\n",26);
		return;
	}
	list_pocket = get_pocket_list(END,NULL);
	new_node = ft_node_new_free(dup);
	if(new_node == NULL)
		return;
	ft_node_add_front(&list_pocket,new_node);
	get_pocket_list(SETD, dup);
}
