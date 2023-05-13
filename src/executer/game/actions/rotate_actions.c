#include "execute.h"

void	rotate(t_data *data, double speed)
{
	double	temp;

	temp = data->ray.dir_x;
	data->ray.dir_x = data->ray.dir_x * cos(speed) - data->ray.dir_y * sin(speed);
	data->ray.dir_y = temp * sin(speed) + data->ray.dir_y * cos(speed);

	temp = data->ray.plane_x;
	data->ray.plane_x = data->ray.plane_x * cos(speed) - data->ray.plane_y * sin(speed);
	data->ray.plane_y = temp * sin(speed) + data->ray.plane_y * cos(speed);
}

void	rotate_left(t_data *data)
{
	rotate(data, ROT_SPEED * -1);
}

void	rotate_right(t_data *data)
{
	rotate(data, ROT_SPEED);
}
