/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utill_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:48:46 by tyi               #+#    #+#             */
/*   Updated: 2023/05/15 15:18:13 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_file_open(char **path, char *value)
{
	int	fd;
	int	end;

	if (*path != NULL)
		exit_with_error("tex File path exist\n");
	*path = value;
	end = ftt_strlen(*path);
	path[0][end - 1] = '\0';
	fd = open(*path, O_RDONLY);
	if (fd == -1)
		exit_with_error("tex File open Error\n");
	close(fd);
}

int	cub_file_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error("cub File open Error\n");
	return (fd);
}

int	line_is_new_line(char *line)
{
	if (line == NULL)
		return (0);
	if (line[0] == '\n')
		return (1);
	return (0);
}

int	line_is_in_map(t_info *info)
{
	if (info->n_texpath == 0)
		return (0);
	if (info->s_texpath == 0)
		return (0);
	if (info->w_texpath == 0)
		return (0);
	if (info->e_texpath == 0)
		return (0);
	if (info->floor_color == -1)
		return (0);
	if (info->ceiling_color == -1)
		return (0);
	return (1);
}
