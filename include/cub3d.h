#ifndef CUB3D_H
# define CUB3D_H
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "constant.h"

typedef struct	s_info
{
	char	*N_texpath;
	char	*S_texpath;
	char	*W_texpath;
	char	*E_texpath;

	int		texWidth;
	int		texHeight;

	//hexadecimal color
	int		floor_color;
	int		ceiling_color;

	int		mapWidth;
	int		mapHeight;
	char	**map;

	char	player_view;
	int 	player_x;
	int		player_y;

}			t_info;

void	exit_with_error(char *msg);
void	malloc_check(void *value);
void	null_check(void *value, char *msg);

#endif
