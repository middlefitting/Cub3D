/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:37:41 by sechung           #+#    #+#             */
/*   Updated: 2023/05/15 15:54:14 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "constant.h"

typedef struct s_info
{
	char	*n_texpath;
	char	*s_texpath;
	char	*w_texpath;
	char	*e_texpath;

	int		floor_color;
	int		ceiling_color;

	int		map_start_idx;
	int		map_width;
	int		map_height;
	char	**map;

	char	player_view;
	int		player_x;
	int		player_y;
}				t_info;

void	exit_with_error(char *msg);
void	malloc_check(void *value);
void	null_check(void *value, char *msg);

#endif
