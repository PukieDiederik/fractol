#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	t_data *data = init(SIZE, SIZE);
	mlx_key_hook(data->window, hook_key_mgr, data);
	mlx_expose_hook(data->window, hook_expose_mgr,data);
	mlx_hook(data->window, 17, 0, exit_clean, data);
	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			int i = mandelbrot(((x - ((double)SIZE / 2)) / ((double)SIZE / 2)) * 2 - 0.5, ((y - ((double)SIZE / 2)) / ((double)SIZE / 2)) * 2);
			int color;
			if (i >= 100)
				color = 0x00ffffff;
			else if (i >= 50)
				color = 0x000000ff;
			else if (i >= 25)
				color = 0x0000ff00;
			else if (i >= 10)
				color = 0x00ff0000;
			else
				color = 0x00000000;
			img_put_pixel(data->img, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img->img, 0, 0);
	mlx_loop(data->mlx);
}