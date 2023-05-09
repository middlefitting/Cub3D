#ifndef CUB3D_H
# define CUB3D_H
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "execute.h"

typedef struct	s_info
{
	char			*N_texpath;
	char			*S_texpath;
	char			*W_texpath;
	char			*E_texpath;
	int				texWidth;
	int				texHeight;
	//hexadecimal color
	unsigned int	floor_color;
	unsigned int	ceiling_color;


	int				mapWidth;
	int				mapHeight;
	char			**map;
	int				point_of_view;
}				t_info;

void	executer(t_info *info);

#endif
