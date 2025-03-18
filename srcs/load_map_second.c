/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:40:31 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/17 17:41:15 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*extract_line(char *content, int *index)
{
	int		len;
	char	*line;
	int		i;

	len = get_line_length(content, *index);
	if (len == -1)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = content[*index + i];
		i++;
	}
	line[len] = '\0';
	*index += len;
	if (content[*index] == '\n')
		(*index)++;
	return (line);
}

char	**convert_to_map(char *file_content, int height)
{
	char	**map;
	int		i;
	int		index;

	map = allocate_map(height);
	if (!map)
		return (NULL);
	i = 0;
	index = 0;
	while (i < height)
	{
		map[i] = extract_line(file_content, &index);
		if (!map[i])
		{
			ft_putstr_fd("Error: Memory allocation failed\n", 2);
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	map[height] = NULL;
	return (map);
}

char	**load_map_from_file(char *filename)
{
	int		fd;
	int		height;
	char	**map;
	char	*file_content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Could not open map file\n", 2);
		return (NULL);
	}
	file_content = read_file_content(fd);
	close(fd);
	if (!file_content)
		return (NULL);
	height = count_lines(file_content);
	map = convert_to_map(file_content, height);
	free(file_content);
	return (map);
}
