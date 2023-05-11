#include "execute.h"

void	floor_ceiling(t_window *window, t_textures textures)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < GAME_HEIGHT)
	{
		while (j < GAME_WIDTH)
		{
			// 왜 반대인지 알아내기
			if (i >= GAME_HEIGHT / 2)
				window->buf[i][j] = textures.floor_color;
			else
				window->buf[i][j] = textures.ceiling_color;
			j++;
		}
		i++;
		j = 0;
	}
}
