/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pocket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:46:49 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/18 10:14:21 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h" 
#include "lsit_struct.h"
#include <stdlib.h>

int	chek_pocket_in_list(char *name)
{
	t_list_		*list_pocket;

	if (name == NULL)
		return (TRUE);
	list_pocket = get_pocket_list(START, NULL);
	while (list_pocket != NULL)
	{
		if (ff_strncmp(list_pocket->content, name,
				ff_strlen(list_pocket->content) + 10) == 0)
			return (TRUE);
		list_pocket = list_pocket->next;
	}
	return (FALSE);
}

void	*check_pocket_null(t_list_ **list_pocket, char **setd)
{
	char	*star;

	if (*list_pocket == NULL)
	{
		star = ff_strdup("main");
		if (star == NULL)
			return (NULL);
		*setd = star;
		if (star == NULL)
			return (NULL);
		*list_pocket = ft_node_new_free(star);
		if (list_pocket == NULL)
			return (free(star), free(list_pocket), NULL);
	}
	return ("oi");
}

t_list_	*get_pocket_list(int n, char *set)
{
	static t_list_	*list_pocket;
	static char		*setd;

	if (check_pocket_null(&list_pocket, &setd) == NULL)
		return (NULL);
	if (n == END)
		return (ff_node_end(list_pocket));
	if (n == START)
		return (ff_node_start(list_pocket));
	if (n == SETD && set != NULL)
		setd = set;
	list_pocket = ff_node_start(list_pocket);
	if (n == SETD && set == NULL )
	{
		while (list_pocket != NULL)
		{
			if (ff_strncmp(list_pocket->content, setd,
					ff_strlen(list_pocket->content) + 10) == 0)
				break ;
			if (list_pocket->next == NULL)
				break ;
			list_pocket = list_pocket->next;
		}
	}
	return (list_pocket);
}

void	ft_pocket_set(char *name)
{
	if (chek_pocket_in_list(name) == TRUE)
		get_pocket_list(SETD, name);
	else
		write(2, "error: the name not valid\n", 27);
}

void	ft_pocket_new(char *name)
{
	t_list_	*list_pocket;
	t_list_	*new_node;
	char	*dup;

	if (chek_pocket_in_list(name) == TRUE)
		return ;
	dup = ff_strdup(name);
	if (dup == NULL)
		return ;
	list_pocket = get_pocket_list(START, NULL);
	if (chek_pocket_in_list(name) == TRUE)
	{
		write(2, "error: this pocket name is used\n", 26);
		return ;
	}
	list_pocket = get_pocket_list(END, NULL);
	new_node = ft_node_new_free(dup);
	if (new_node == NULL)
		return ;
	ff_node_add_front(&list_pocket, new_node);
	get_pocket_list(SETD, dup);
}
