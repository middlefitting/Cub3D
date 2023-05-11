#include "execute.h"

void	draw_window(t_window window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < GAME_HEIGHT)
	{
		while (j < GAME_WIDTH)
		{
			window.img.data[i * GAME_WIDTH + j] = window.buf[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(window.mlx, window.win, window.img.img, 0, 0);
}
