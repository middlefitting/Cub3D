#include "execute.h"

void	init_textures(t_data *data, t_info *info)
{
	data->textures.ceiling_color = info->ceiling_color;
	data->textures.floor_color = info->floor_color;
	//텍스쳐 작업
	init_texture(&data->textures.north_wall, info->N_texpath, data->window.mlx);
	init_texture(&data->textures.south_wall, info->S_texpath, data->window.mlx);
	init_texture(&data->textures.east_wall, info->E_texpath, data->window.mlx);
	init_texture(&data->textures.west_wall, info->W_texpath, data->window.mlx);
}

void	init_window(t_window *window)
{
	window->mlx = mlx_init();
	null_check(window->mlx, "mlx init failed");
	window->img.img = mlx_new_image(window->mlx, GAME_WIDTH, GAME_HEIGHT);
	null_check(window->img.img, "mlx new image failed");
	window->img.data = (int *) mlx_get_data_addr(window->img.img, &window->img.bpp, &window->img.size_l, &window->img.endian);
	null_check(window->img.data, "mlx get data addr failed");
	//title mlx -> cub3d로 수정하기
	window->win = mlx_new_window(window->mlx, GAME_WIDTH, GAME_HEIGHT, "mlx");
}

void	init_game_data(t_data *data, t_info *info)
{
	init_ray(&data->ray, info);
	init_window(&data->window);
	init_textures(data, info);
	data->map = info->map;
}
