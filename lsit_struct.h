/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsit_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:29:39 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/14 22:30:26 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_STRUCT_H
#define LIST_STRUCT_H
typedef struct s_list_
{
	void			*content;
	struct s_list_	*next;
	struct s_list_	*previous;
}					t_list_;
#endif

