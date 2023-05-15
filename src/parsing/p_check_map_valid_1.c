/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_map_valid_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: middlefitting <middlefitting@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:29:12 by tyi               #+#    #+#             */
/*   Updated: 2023/05/15 14:49:16 by middlefitti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '1')
		return (1);
	return (0);
}

int	is_nswe(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	check_linking_zereos(t_info *info, int i, int j)
{
	char	**map;

	map = info->map;
	if (i != 0)
	{
		if (map[i - 1][j] == '0')
			exit_with_error("Map is not surrounded Error\n");
	}
	if (i != info->map_height - 1)
	{
		if (map[i + 1][j] == '0')
			exit_with_error("Map is not surrounded Error\n");
	}
	if (j != 0)
	{
		if (map[i][j - 1] == '0')
			exit_with_error("Map is not surrounded Error\n");
	}
	if (j != info->map_width - 1)
	{
		if (map[i][j + 1] == '0')
			exit_with_error("Map is not surrounded Error\n");
	}
}

void	check_zero_on_side(t_info *info, int i, int j)
{
	if (info->map[i][j] == '0')
	{
		if (i == 0 || i == info->map_height - 1 || \
		j == 0 || j == info->map_width - 1)
			exit_with_error("Zero is on side Error\n");
	}
}
