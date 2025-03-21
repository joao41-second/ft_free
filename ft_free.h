/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:19:37 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/17 11:08:55 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_H
# define FT_FREE_H

# define START 2
# define END 3
# define SETD 5

# define FREE 8

# define TRUE 0
# define FALSE 1

# include "lsit_struct.h"
# include <aio.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_free_list
{
	char	*pocket;
	void	*memory;

}			t_free_list;

//------------------------START------------------------------//
/**
 * @brief the start the library the malloc not use not 
 * possible use neither the all function
 */
void		ft_start_alloc(void);

//-------------------------ALOC-------------------------------//

/**
 * @brief this function is used for allocate memory 
 * @param size nuber bits for alocade 
 * @param pocket use for alocad memory pocket;
 */
void		*ft_malloc(size_t size, void *pocket);

/**
 * @brief this function add memory in linked list 
 * pocket name the pocket (opcion)
 * memory pointer or memory 
 */
void		*ft_add_memory(void *memory, char *pocket);
//---------------------------FREE-----------------------------//

/**
 * @brief this function is used to free memory of the program 
 * @param list_set set is null
 */
void		ft_free_all(void);

/**
 * @brief this function is used for free in specifly variabel
 */
void		ft_free(void *var);
/**
 * @brief free the all memory the pocket specific (not valid main pocket)
 * @param name the pocket
 */
void		ft_free_all_pocket(char *name_pocket);

//---------------------------------------------------------//
// utilis.c
t_list_		*ft_maolloc_next(t_list_ *list_set, t_list_ *list, size_t size);

t_list_		*ft_node_new_free(void *n);

void		ft_remove(t_list_ **node);

t_list_		*free_next(t_list_ *list);

//geters

t_list_		*get_list_free(int n);

t_list_		*get_pocket_list(int n, char *set);

//struct

void		free_struct_free(t_free_list *node);

t_free_list	*inicializ_struct_free(char *str, size_t size);

//pocket

int			chek_pocket_in_list(char *name);

void		ft_pocket_new(char *name);

void		ft_pocket_set(char *name);

// str

char		*ff_strdup(char *str);

int			ff_strncmp(const char *s1, const char *s2, size_t n);

int			ff_strlen(char *str);

// list

void		ff_node_add_front(t_list_ **lst, t_list_ *new_);

t_list_		*ff_node_end(t_list_ *list);

t_list_		*ff_node_start(t_list_ *list);

/**
 * @brief alloc the memory reght for Created new node t_list_
 * @param n variabel used in list
 * @return node t_list_ alocad with memory alocade
 */
t_list_		*ft_node_new_free(void *n);

#endif
