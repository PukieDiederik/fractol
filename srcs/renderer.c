#include "fractol.h"

void render_fractal(t_data *data)
{
	unsigned int x;
	unsigned int y;

	x = -1;
	while (++x < data->size)
	{
		y = -1;
		while (++y < data->size)
		{
			int fractal = mandelbrot(((double)x / data->size) * data->scale + data->x_offset, ((double)y / data->size) * data->scale + data->y_offset);
			int color = 0x00000000;
			if (fractal >= 100)
				color = 0x00ffffff;
			img_put_pixel(data->img, x, y, color);
		}
	}
}