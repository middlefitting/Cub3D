#include "execute.h"

int	release_events(int key_num, t_data *data)
{
	if (key_num < 256)
		data->press[key_num] = FALSE;
	return (0);
}
