/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_step1_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:56:13 by tyi               #+#    #+#             */
/*   Updated: 2023/05/15 16:27:58 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	fill_info(char *line, t_info *info);
int		line_is_end_of_map(t_info *info, char *line);
int		line_is_middle_of_map(t_info *info, char *line);

void	push_new_line(t_info *info, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		info->map_start_idx++;
		if (line == NULL)
			exit_with_error("map is not exist");
		else if (line_is_new_line(line))
		{
			free(line);
			continue ;
		}
		else
		{
			info->map_width = ftt_strlen(line) - 1;
			free(line);
			break ;
		}
	}
}

void	fill_before_map(t_info *info, int fd)
{
	char	*line;

	while (!line_is_in_map(info))
	{
		info->map_start_idx++;
		line = get_next_line(fd);
		if (line == NULL)
			exit_with_error("info before map is not enough error");
		else if (line_is_new_line(line))
		{
			free(line);
			continue ;
		}
		else
			fill_info(line, info);
		free(line);
	}
	if (info->floor_color == info ->ceiling_color)
		exit_with_error("floor and ceiling color is same error");
}

void	check_map_info(t_info *info, int fd)
{
	char	*line;
	int		h;

	h = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line_is_new_line(line))
		{
			free (line);
			exit_with_error("line of map must be never newline error");
		}
		else
		{
			if (!(line_is_middle_of_map(info, line) \
			|| line_is_end_of_map(info, line)))
				exit_with_error("line of map is error");
			h++;
		}
		free(line);
	}
	info->map_height = h;
	close(fd);
}

void	check_map_size(t_info *info)
{
	if (info->map_width > 1000 || info->map_height > 1000)
		exit_with_error("map size is too big error");
}

void	step1(t_info *info, int fd)
{
	fill_before_map(info, fd);
	push_new_line(info, fd);
	check_map_info(info, fd);
	check_map_size(info);
	close (fd);
}
