/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantures <fantures@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:07:12 by fantures          #+#    #+#             */
/*   Updated: 2023/05/13 18:25:34 by fantures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int 	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

const char	*ft_strchr(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_strjoin(char *dst, char *src)
{
	unsigned int	i;
	unsigned int	j;
	char	*str;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * ((i + j) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (dst)
		while (dst[i])
		{
			str[i] = dst[i];
			i++;
		}
	while (*src)
	{
		str[i++] = *src;
		src++;
	}
	str[i] = '\0';
	free(dst);
	return (str);
}	
