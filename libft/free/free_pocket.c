/*                                                        :::      ::::::::   */
/*   free_pocket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:53:21 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/12 14:55:20 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h" 
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

//lsit_
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

int chek_pocket_in_list(char *name)
{

	printf("star pocket %s \n",name);
	t_list_ *list_pocket;
 	list_pocket = get_pocket_list(START, NULL);
	while (list_pocket != NULL) 
	{
		printf("ola %s \n",(char *)list_pocket->content);
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
	char *star = NULL;
	if( list_pocket == NULL)
	{
		star = ff_strdup("main");
		if(star == NULL)
			return NULL;
		setd = star;
		if(star == NULL)
			return NULL;
		list_pocket = ft_node_new_free(star);
		if(list_pocket == NULL)
			return(free(star),free(list_pocket),NULL);
	}
	if(n == END)
		return(ff_node_end(list_pocket));
	if(n == START)
		return(ff_node_start(list_pocket));
	if(n == SETD && set != NULL)
		setd = set;
	list_pocket = ff_node_start(list_pocket);
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

void ft_pocket_set(char *name)
{
	if(chek_pocket_in_list(name) == TRUE)
		get_pocket_list(SETD, name);
	else
	 write(2,"error: the name not valid\n",27);
}


void ft_pocket_new(char *name)
{
	t_list_ *list_pocket;
	t_list_ *new_node;
	char *dup;
	if(chek_pocket_in_list(name) == TRUE)
		return;
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
	ff_node_add_front(&list_pocket,new_node);
	get_pocket_list(SETD, dup);
}
