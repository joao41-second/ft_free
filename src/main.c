/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:12:18 by jperpect          #+#    #+#             */
/*   Updated: 2025/01/16 11:32:58 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void print_free_list()
{
	t_list_ *list;
	list = get_list_free(START);
	t_free_list *content;
	while(list != NULL)
	{
		content =(t_free_list *) list->content;
		printf("link , name %s\n",content->pocket);
		printf("------^-----\n");
		list = list->next;
	}
}



int	main(int ac, char **av, char **env)
{
	(void)ac;
	start_alloc();

	ft_malloc(10,NULL);
	ft_malloc(10,NULL);
	pocket_new("ola");
	ft_malloc(10,NULL);
	pocket_new("ola2");
	ft_malloc(10,NULL);


//	t_list_ *list = get_pocket_list(SETD,NULL);
	print_free_list();
//	ft_printf("list peketd is %s ",list->content);
	(void)av;
	return (0);
}
