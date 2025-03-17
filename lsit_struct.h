/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsit_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:29:39 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/17 11:08:34 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSIT_STRUCT_H
# define LSIT_STRUCT_H

typedef struct s_list_
{
	void			*content;
	struct s_list_	*next;
	struct s_list_	*previous;
}					t_list_;
#endif
