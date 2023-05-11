#include "execute.h"

void	set_texture_element(t_texture *texture, int *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < texture->height)
	{
		while (j < texture->width)
		{
			texture->texture[texture->width * i + j] = data[texture->width * i + j];
			j++;
		}
		i++;
		j = 0;
	}
}

void	texture_setting(t_texture *texture, int *data)
{
	texture->texture = ft_calloc(texture->height * texture->width, sizeof(int));
	malloc_check(texture->texture);
	set_texture_element(texture, data);
}

void	init_texture(t_texture *texture, char *texture_path, void *mlx)
{
	t_img	img;

	// img.img = mlx_xpm_file_to_image(mlx, texture_path, &texture->width, &texture->height);
	img.img = mlx_png_file_to_image(mlx, texture_path, &texture->width, &texture->height);
	null_check(img.img, "mlx file to image failed");
	img.data = (int *) mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	null_check(img.data, "mlx get data addr failed");
	texture_setting(texture, img.data);
}
