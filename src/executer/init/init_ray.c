#include "execute.h"

void	dir_and_plane_setting(t_ray *ray, char player_view)
{
	if (player_view == 'N')
	{
		ray->dir_y = -1.0;
		ray->pos_x = 0.66;
	}
	else if (player_view == 'S')
	{
		ray->dir_y = 1.0;
		ray->pos_x = -0.66;
	}
	else if (player_view == 'W')
	{
		ray->dir_x = -1.0;
		ray->plane_y = 0.66;
	}
	else
	{
		ray->dir_x = 1.0;
		ray->plane_y = -0.66;
	}
}

void	init_ray(t_ray *ray, t_info *info)
{
	ray->pos_x = info->player_x;
	ray->pos_y = info->player_y;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->plane_x = 0.0;
	ray->plane_y = 0.0;
	dir_and_plane_setting(ray, info->player_view);
}
