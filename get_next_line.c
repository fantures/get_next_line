/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantures <fantures@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:06:44 by fantures          #+#    #+#             */
/*   Updated: 2023/05/13 18:20:19 by fantures         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*content;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	content = read_to_content(fd, content);
	if (!content)
		return (NULL);
	line = line_maker(content);
	content = future_content(content);
	return (line);
}

char	*read_to_content(int fd, char *content)
{
	long	r_bytes;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	r_bytes = 1;
	while (!ft_strchr(content, '\n') && r_bytes)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(buf);
			free(content);
			return (NULL);
		}
		buf[r_bytes] = '\0';
		content = ft_strjoin(content, buf);
	}
	free(buf);
	return (content);
}

char	*line_maker(const char *content)
{
	char	*line;
	int	i;

	if (!ft_strlen(content))
		return (NULL);
	i = 0;
	while (content[i] != '\n' && content[i])
		i++;
	if (content[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = content[i];
	return (line);
}

char	*future_content(char *content)
{
	char	*futent;
	long	i;
	long	j;

	if (!content)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	futent = (char *)malloc(sizeof(char) * (ft_strlen(content) - i) + 1);
	if (!futent)
		return (NULL);
	j = 0;
	while (content[i])
		futent[j++] = content[i++];
	futent[j] = '\0';
	free(content);
	return (futent);
}

int	main(void)
{
	long	fd;
	int	i;

	fd = open("test.txt", O_RDONLY);
	while (i < 8)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}
