/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:19:40 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2023/12/20 13:47:15 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*array;
	int		e;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	e = 0;
	array = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (array == NULL)
		return (NULL);
	while (s1[i])
		array[e++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		array[e] = s2[i];
		i++;
		e++;
	}
	array[e] = '\0';
	free(s1);
	return (array);
}

char	*ft_strcpy(char *buffer)
{
	char	*copy;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	copy = malloc(ft_strlen(buffer) + 1);
	if (copy == NULL)
		return (NULL);
	while (buffer[i])
	{
		copy[i] = buffer[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}