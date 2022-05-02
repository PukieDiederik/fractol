#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	t_data *data = init(600, 600);
	mlx_key_hook(data->window, hook_key_mgr, data);
	mlx_expose_hook(data->window, hook_expose_mgr,data);
	for (int x = 0; x < 600; x++) {
		for (int y = 0; y < 600; y++) {
			img_put_pixel(data->img, x, y, 0x00027fd3);
		}
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img->img, 0, 0);
	mlx_loop(data->mlx);
}