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



int	main(int ac, char **av, char **env)
{
	(void)ac;
	start_alloc();
	pocket_new("ola");
	pocket_new("ola2");
//	ft_malloc(10,NULL);

	t_list_ *list = get_pocket_list(SETD,NULL);
	ft_printf("list peketd is %s ",list->content);
	(void)av;
	return (0);
}
