/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:19:37 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/13 16:30:23 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FREE_AND_LIST_H
#ifdef FREE_AND_LIST_H

#define START 2
#define END   3
#define SETD  5

# define FREE 8

# define TRUE 0
# define FALSE 1

# include "list.h"
# include <aio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_free_list
{
	char *pocket;
	void *memory;

} t_free_list;

/**
 * @brief this function is used for allocate memory 
 * @param size nuber bits for alocade 
 * @param list_set set is null;
 */
void	*ft_malloc(size_t size, void *list_set);

/**
 * @brief this function is used to free memory of the program 
 * @param list_set set is null
 */
void	ft_free_all();

/**
 * @brief this function is used for free in specifly variabel
 * @param var for free memory
 * @param list_set set ins null
 */
void	ft_free(void *var);

/**
 * @brief the start the library the malloc not use not 
 * possible use neither the all function
 */
void	ft_start_alloc(void);

/**
 * @brief alloc the memory reght for Created new node t_list_
 *
 * @param n variabel used in list
 * @return node t_list_ alocad with memory alocade
 */
t_list_	*ft_node_new_free(void *n);

// utilis.c
t_list_	*ft_maolloc_next(t_list_ *list_set, t_list_ *list, size_t size);

t_list_	*ft_node_new_free(void *n);

void	ft_remove(t_list_ **node);

t_list_	*free_next(t_list_ *list);

void free_struct_free(t_free_list *node);

t_list_* get_list_free(int n);



t_free_list * inicializ_struct_free(char *str,size_t size);

void *ft_add_memory(void *memory,char *pocket);

int chek_pocket_in_list(char *name);

void ft_pocket_new(char *name);

t_list_ *get_pocket_list(int n,char *set);

void ft_free_all_pocket(char *name_pocket);

void ft_pocket_set(char *name);

// str

char *ff_strdup(char *str);

int	ff_strncmp(const char *s1, const char *s2, size_t n);

int ff_strlen(char *str);


#endif
