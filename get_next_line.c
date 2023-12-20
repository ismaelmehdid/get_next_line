/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:41:00 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2023/12/20 13:47:07 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_crop_new_stash(char *stash)
{
	char	*newstash;
	int		i;
	int		e;
	int		sizestash;

	sizestash = ft_strlen(stash);
	e = 0;
	i = 0;
	while (stash[i] != '\n' && i != sizestash)
		i++;
	if (stash[i] == '\n')
		i++;
	while (stash[i] && i != sizestash)
	{
		e++;
		i++;
	}
	newstash = malloc(sizeof(char) * (e + 1));
	i -= e;
	e = 0;
	while (stash[i])
		newstash[e++] = stash[i++];
	newstash[e] = '\0';
	free(stash);
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
	static int	nbcall;
	int			bytesread;

	while ((!ft_is_stash_ready(stash, BUFFER_SIZE)) && *endfile == 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < BUFFER_SIZE)
			*endfile = 1;
		buffer[bytesread] = '\0';
		if (nbcall == 0)
			stash = ft_strcpy(buffer);
		else
			stash = ft_strjoin(stash, buffer);
		nbcall++;
		free(buffer);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*theline;
	static char	*stash;
	int			endfile;

	endfile = 0;
	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, &theline, 0) < 0)
		return (NULL);
	theline = NULL;
	if (stash)
		stash = ft_crop_new_stash(stash);
	stash = ft_read_file(fd, stash, &endfile);
	if (!stash)
	{
		free (stash);
		return (NULL);
	}
	theline = ft_crop_to_get_line(stash);
	if (!*theline)
	{
		free(theline);
		return (NULL);
	}
	return (theline);
}
