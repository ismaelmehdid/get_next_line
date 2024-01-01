/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:41:00 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2024/01/01 17:36:21 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_crop_new_stash(char *stash)
{
	char	*newstash;
	int		i;
	int		e;

	e = 0;
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	e = ft_strlen(stash) - i;
	i = ft_strlen(stash);
	newstash = malloc(sizeof(char) * (e + 1));
	if (newstash == NULL)
	{
		free (stash);
		return (NULL);
	}
	i -= e;
	e = 0;
	while (stash[i])
		newstash[e++] = stash[i++];
	newstash[e] = '\0';
	free (stash);
	return (newstash);
}

char	*ft_crop_to_get_line(char *stash)
{
	char	*croped;
	int		i;
	int		e;

	e = 0;
	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	croped = malloc(sizeof(char) * (i + 1));
	if (croped == NULL)
		return (NULL);
	while (e != i)
	{
		croped[e] = stash[e];
		e++;
	}
	croped[e] = '\0';
	return (croped);
}

int	ft_is_stash_ready(char *stash, int bytes)
{
	int	i;
	int	e;

	e = ft_strlen(stash);
	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	if (e == i && bytes == 0)
		return (1);
	return (0);
}

char	*ft_read_file(int fd, char *stash, int *endfile)
{
	char		*buffer;
	int			bytesread;

	while ((!ft_is_stash_ready(stash, BUFFER_SIZE)) && *endfile == 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free (buffer);
			return (NULL);
		}
		if (bytesread < BUFFER_SIZE)
			*endfile = 1;
		buffer[bytesread] = '\0';
		if (!stash)
			stash = ft_strcpy(buffer);
		else
			stash = ft_strjoin(stash, buffer);
		free(buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*theline;
	static char	*stash;
	static int	endfile;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	theline = NULL;
	if (stash)
		stash = ft_crop_new_stash(stash);
	stash = ft_read_file(fd, stash, &endfile);
	if (!stash || ft_strlen(stash) == 0)
	{
		stash = ft_freestash(stash);
		return (NULL);
	}
	theline = ft_crop_to_get_line(stash);
	if (!theline || ft_strlen(theline) == 0)
	{
		free(theline);
		return (NULL);
	}
	if (ft_compare(theline, stash) == 1)
		stash = ft_freestash(stash);
	return (theline);
}
