#include "mlx.h"
#include "fractol.h"

void zoom_in(t_data *data, int x, int y)
{
	double scaling = 0.9;
	data->x_offset = data->x_offset + (((double)x / data->size) * data->scale) - ((data->scale * scaling) / 2);
	data->y_offset = data->y_offset + (((double)y / data->size) * data->scale) - ((data->scale * scaling) / 2);
	data->scale *= scaling;
	render_fractal(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img->img, 0, 0);
}

void zoom_out(t_data *data)
{
	double scaling = 1.1;
	data->x_offset += (data->scale - (data->scale * ((scaling * 0.5) + 0.5)));
	data->y_offset += (data->scale - (data->scale * ((scaling * 0.5) + 0.5)));
	data->scale *= scaling;
	render_fractal(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img->img, 0, 0);
}