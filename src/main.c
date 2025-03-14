/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:12:18 by jperpect          #+#    #+#             */
/*   Updated: 2025/03/13 16:31:20 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void print_free_list()
{
	t_list_ *list;
	int i;
	i = 0;
	list = get_list_free(START);
	t_free_list *content;
	while(list != NULL)
	{
		content =(t_free_list *) list->content;
		printf(" %d :: link , name %s\n",i,content->pocket);
		printf("------^-----\n");
		list = list->next;
		i++;
	}
}

void print_pocket_list()
{
	t_list_ *list;
	int i;
	i = 0;
	list = get_pocket_list(START,NULL);
	char *content;
	printf("________\n");
	while(list != NULL)
	{
		content =list->content;
		printf(" %d :: pocket , name %s\n",i,content);
		list = list->next;
		i++;
	}

	printf("________\n");
}





int	main(int ac, char **av, char **env)
{
	(void)ac;
	char *ok;
	ft_start_alloc();

	ft_malloc(10,NULL);
	ft_malloc(10,NULL);
	pocket_new("ola");
	ft_malloc(10,NULL);
	ft_malloc(10,"main");
	ft_malloc(10,NULL);
	pocket_new("ola2");
	ok = ft_malloc(10,NULL);
	ft_pocket_set("main");
	ft_malloc(10,NULL);
	ft_malloc(10,"ola");
	pocket_new("ola2");
	pocket_new("ola3");
	pocket_new("ola4");


//	t_list_ *list = get_pocket_list(SETD,NULL);
	print_pocket_list();
	print_free_list();
	ft_free_all_pocket("ola");
	ft_free(ok);
	printf("\n");
	print_free_list();
//	ft_printf("list peketd is %s ",list->content);
	(void)av;
	ft_free_all(NULL);
	return (0);
}
