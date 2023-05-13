/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantures <fantures@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:03:01 by fantures          #+#    #+#             */
/*   Updated: 2023/05/13 18:25:54 by fantures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char    *get_next_line(int fd);
char    *read_to_content(int fd, char *content);
char    *line_maker(const char *content);
char    *future_content(char *content);
unsigned int    ft_strlen(const char *str);
const char    *ft_strchr(const char *str, char c);
char    *ft_strjoin(char *dst, char *src);

#endif
