#ifndef EXECUTE_H
# define EXECUTE_H

#include "cub3d.h"


typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	// int		img_width;
	// int		img_height;
}				t_img;


typedef struct	s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_ray;


typedef struct	s_window
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[GAME_HEIGHT][GAME_WIDTH];
}				t_window;


typedef struct	s_texture
{
	int	*texture;
	int	height;
	int	width;
}				t_texture;


typedef struct	s_textures
{
	t_texture		north_wall;
	t_texture		south_wall;
	t_texture		east_wall;
	t_texture		west_wall;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
}				t_textures;

typedef struct	s_data
{
	t_ray		ray;
	t_window	window;
	t_textures	textures;
	char		**map;
}				t_data;

void	executer(t_info *info);

void	init_game_data(t_data *data, t_info *info);
void	init_ray(t_ray *ray, t_info *info);
void	init_texture(t_texture *texture, char *texture_path, void *mlx);


#endif
