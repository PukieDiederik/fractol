#include "fractol.h"
#include "math.h"
#include "libft.h"

int abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

double lerp(unsigned int a, unsigned int b, double t)
{
	return ((1 - t) * (double)a + t * (double)b);
}

unsigned int get_color(unsigned int color1, unsigned int color2, int i, int max)
{
	unsigned int c;
	c = ((int)(lerp(color1 >> 16 & 0xff, color2 >> 16 & 0xff, (float)i / (float)max)) << 16)
		|  ((int)(lerp(color1 >> 8 & 0xff, color2 >> 8 & 0xff, (float)i / (float)max)) << 8)
		|  ((int)(lerp(color1& 0xff, color2 & 0xff, (float)i / (float)max)));
	return (c);
}

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
			int fractal = data->fractal(((double)x / data->size) * data->scale + data->x_offset, ((double)y / data->size) * data->scale + data->y_offset, data);
			int color = get_color(0x00000000, 0x00ffffff, fractal, data->max_iter);
			img_put_pixel(data->img, x, y, color);
		}
	}
}