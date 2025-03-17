/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpct <jperpect@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:50:59 by jperpct           #+#    #+#             */
/*   Updated: 2025/03/17 11:06:05 by jperpct          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_free.h"

int	ff_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
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

char	*ff_strdup(char *str)
{
	char	*dup;
	int		i;

	i = -1;
	dup = malloc(ff_strlen(str) + 1 * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (str[++i] != '\0')
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
