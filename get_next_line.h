/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:29 by ismaelmehdi       #+#    #+#             */
/*   Updated: 2023/12/22 17:51:35 by ismaelmehdi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);

char	*ft_strcpy(char *buffer);

char	*ft_strjoin(char *s1, char *s2);

int		ft_strlen(char *stash);

int		ft_compare(char	*s1, char *s2);

char	*ft_freestash(char *stash);

#endif