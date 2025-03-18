/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:16:54 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/17 18:05:20 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	*resize_content(char *content, size_t total_size,
	size_t bytes_read, char *buffer)
{
	char	*new_content;

	new_content = malloc(total_size + bytes_read + 1);
	if (!new_content)
	{
		free(content);
		return (NULL);
	}
	if (content)
	{
		ft_memcpy(new_content, content, total_size);
		free(content);
	}
	ft_memcpy(new_content + total_size, buffer, bytes_read + 1);
	return (new_content);
}

char	*read_file_content(int fd)
{
	char	buffer[MAX_BUFFER_SIZE];
	char	*file_content;
	int		bytes_read;
	size_t	total_size;

	file_content = NULL;
	total_size = 0;
	bytes_read = read(fd, buffer, MAX_BUFFER_SIZE - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		file_content = resize_content(
				file_content, total_size, bytes_read, buffer);
		if (!file_content)
			return (NULL);
		total_size += bytes_read;
		bytes_read = read(fd, buffer, MAX_BUFFER_SIZE - 1);
	}
	return (file_content);
}

int	count_lines(char *content)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

char	**allocate_map(int height)
{
	char	**map;

	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		ft_putstr_fd("Error: Memory allocation failed for map\n", 2);
	return (map);
}

int	get_line_length(char *content, int index)
{
	int	len;

	len = 0;
	while (content[index + len] && content[index + len] != '\n')
	{
		len++;
		if (len > MAX_LINE_LENGTH)
		{
			ft_putstr_fd("Error: Line too long\n", 2);
			return (-1);
		}
	}
	return (len);
}
