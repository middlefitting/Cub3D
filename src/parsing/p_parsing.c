/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:22:43 by tyi               #+#    #+#             */
/*   Updated: 2023/05/13 17:47:00 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parsing.h"

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	init_info(t_info *info)
{
	info->n_texpath = 0;
	info->s_texpath = 0;
	info->w_texpath = 0;
	info->e_texpath = 0;
	info->floor_color = -1;
	info->ceiling_color = -1;
	info->map_width = 0;
	info->map_height = 0;
	info->map_start_idx = -1;
	info->map = 0;
	info->player_view = 0;
	info->player_x = 0;
	info->player_y = 0;
}

void	parsing(t_info *info, char *path)
{
	init_info(info);
	step1(info, cub_file_open(path));
	step2(info, cub_file_open(path));
	check_map_valid(info);
}
