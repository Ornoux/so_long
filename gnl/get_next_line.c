/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:08:04 by npatron           #+#    #+#             */
/*   Updated: 2023/07/11 10:25:21 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(char *save, char *buffer)
{
	char	*newsave;

	newsave = ft_strjoin(save, buffer);
	free(save);
	return (newsave);
}

char	*build_line(char	*dest)
{
	char	*line;
	int		i;

	i = 0;
	if (!dest[i])
		return (NULL);
	while (dest[i] && dest[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (dest[i] && dest[i] != '\n')
	{
		line[i] = dest[i];
		i++;
	}
	if (dest[i] && dest[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*build_next(char	*dest)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (dest[i] && dest[i] != '\n')
		i++;
	if (!dest[i])
		return (free(dest), NULL);
	line = ft_calloc((ft_strlen(dest) - i + 1), sizeof(char));
	j = 0;
	i++;
	while (dest[i])
		line[j++] = dest[i++];
	free(dest);
	return (line);
}

char	*read_file(int fd, char *save)
{
	int		i;
	char	*buffer;

	if (!save)
		save = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(buffer), free(save), NULL);
		buffer[i] = 0;
		save = create_line(save, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*dest;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_file(fd, save);
	if (!save)
		return (NULL);
	dest = build_line(save);
	save = build_next(save);
	return (dest);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("1st : %s\n", get_next_line(fd));
// 	printf("2nd : %s\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
