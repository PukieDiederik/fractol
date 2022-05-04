#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

int main()
{
	t_data *data = init(600);
	mlx_key_hook(data->window, hook_key_mgr, data);
	mlx_expose_hook(data->window, hook_expose_mgr,data);
	mlx_hook(data->window, 17, 0, exit_clean, data);
	render_fractal(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img->img, 0, 0);
	mlx_loop(data->mlx);
}