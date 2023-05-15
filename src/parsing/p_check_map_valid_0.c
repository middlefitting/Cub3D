/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_map_valid_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:10:31 by tyi               #+#    #+#             */
/*   Updated: 2023/05/15 16:25:18 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		is_space(char c);
int		is_num(char c);
int		is_nswe(char c);
void	check_linking_zereos(t_info *info, int i, int j);
void	check_zero_on_side(t_info *info, int i, int j);

void	check_linking_space(t_info *info, int i, int j)
{
	char	**map;

	map = info->map;
	if (i != 0)
	{
		if (map[i - 1][j] == ' ')
			exit_with_error("Player is not surrounded ");
	}
	if (i != info->map_height - 1)
	{
		if (map[i + 1][j] == ' ')
			exit_with_error("Player is not surrounded");
	}
	if (j != 0)
	{
		if (map[i][j - 1] == ' ')
			exit_with_error("Player is not surrounded");
	}
	if (j != info->map_width - 1)
	{
		if (map[i][j + 1] == ' ')
			exit_with_error("Player is not surrounded");
	}
}

void	check_and_fill_player(t_info *info, int i, int j)
{
	if (info->player_view)
		exit_with_error("player is not unique");
	check_linking_space(info, i, j);
	if (i == 0 || i == info->map_height - 1
		|| j == 0 || j == info->map_width - 1)
		exit_with_error("player is not surrounded");
	info->player_view = info->map[i][j];
	info->player_x = j;
	info->player_y = i;
}

void	check_map_valid(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j] != '\n' && info->map[i][j] != '\0')
		{
			if (is_space(info->map[i][j]))
				check_linking_zereos(info, i, j);
			else if (is_num(info->map[i][j]))
				check_zero_on_side(info, i, j);
			else if (is_nswe(info->map[i][j]))
				check_and_fill_player(info, i, j);
			else
				exit_with_error("element of map is false");
			j++;
		}
		i++;
	}
	if (!info->player_view)
		exit_with_error("player is not exist");
}
