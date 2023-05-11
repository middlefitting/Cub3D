#include "execute.h"

int	game(t_data *data)
{
	floor_ceiling(&data->window, data->textures);
	draw_window(data->window);

	return (0);
}
