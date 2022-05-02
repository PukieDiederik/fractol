#include "mlx.h"
#include "stdlib.h"
#include "fractol.h"

t_data	*init(int width, int height)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(0);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data);
		exit(0);
	}
	data->window = mlx_new_window(data->mlx, width, height, "Fract'ol");
	data->img = malloc(sizeof(t_img_data));
	if (!data->window || !data->img)
		exit_clean(data);
	data->img->img = mlx_new_image(data->mlx, width, height);
	if (!data->img->img)
		exit_clean(data);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel,
		&data->img->line_length, &data->img->endian);
	return (data);
}

void	exit_clean(t_data *data)
{
	if (data->img != 0)
		mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->window);
	free(data->img);
	free(data);
	exit(0);
}

void img_put_pixel(t_img_data *img, int x, int y, unsigned int color)
{
	*((unsigned int *)(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)))) = color;
}
