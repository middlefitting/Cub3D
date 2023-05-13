#include "execute.h"

void	sample(t_info *info)
{
	// info->N_texpath = "./textures/brick-texture-png-23885.png";
	// info->S_texpath = "./textures/brick-texture-png-23868.png";
	// info->W_texpath = "./textures/brick-texture-png-23873.png";
	// info->E_texpath = "./textures/brick-texture-png-23887.png";
	info->N_texpath = "./textures/AnyConv.com__brick-texture-png-23868.xpm";
	// info->S_texpath = "./textures/AnyConv.com__brick-texture-png-23873.xpm";
	info->W_texpath = "./textures/AnyConv.com__brick-texture-png-23885.xpm";
	///////////////
	info->E_texpath = "./textures/AnyConv.com__brick-texture-png-23873.xpm";
	info->S_texpath = "./textures/AnyConv.com__brick-texture-png-23887.xpm";
	// info->E_texpath = "./textures/AnyConv.com__brick-texture-png-23887.xpm";
	info->floor_color = 16711680;
	info->ceiling_color = 65280;
	info->mapHeight = 24;
	info->mapWidth = 24;
	info->player_x = 3;
	info->player_y = 2;
	info->player_view = 'E';
	// char map[24][24] =
	// 				{
	// 					{'1','1', '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','1','1','0','1','1','1','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','1','1','1','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','1','1','W','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','1','1','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','1'},
	// 					{'1','1', '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
	// 				};
	// info->map = (char **) map;
	info->map = calloc(24, sizeof(char *));
	info->map[0] = "111111111111111111111111";
	for (int i = 1; i < 23; i++)
		info->map[i] = "100000000000000000000001";
	info->map[9] = "111001111111111111111111";
	info->map[10] = "111111111111111111111111";
	info->map[11] = "1000000000000000001010W1";
	info->map[12] = "111111111111111111111111";
	info->map[23] = "111111111111111111111111";

	info->map[0] = "111111111111111111111111";
	info->map[1] = "110001111111111111111111";
	info->map[2] = "110001111111111111111111";
	info->map[3] = "110001111111111111111111";
	info->map[4] = "110001111111111111111111";
	info->map[5] = "100000011111111111111111";
}

void	calloc_data(t_data **data)
{
	*data = ft_calloc(1, sizeof(t_data));
	malloc_check(*data);
}

void	executer(t_info *info) {
	t_data	*data;

	//
	// sample(info);
	//
	calloc_data(&data);
	init_game_data(data, info);
	mlx_loop_hook(data->window.mlx, &game, data);
	mlx_hook(data->window.win, X_EVENT_CLOSE_BUTTON, 0, finish_game, 0);
	mlx_hook(data->window.win, X_EVENT_KEY_PRESS, 0, press_events, data);
	mlx_hook(data->window.win, X_EVENT_KEY_RELEASE, 0, release_events, data);
	mlx_loop(data->window.mlx);
}
