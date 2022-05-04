#include "mlx.h"
#include "fractol.h"
#include <stdio.h>

//manages key hooks
int hook_key_mgr(int keycode, t_data *data)
{
//	printf("keycode: %d\n", keycode);
	if(keycode == K_ESC) //ESC
		exit_clean(data);
	return (0);
}

int hook_mouse_mgr(int button, int x, int y, t_data *data)
{
	if (button == 4)
		zoom_in(data, x, y);
	else if (button == 5)
		zoom_out(data);
	return (0);
}

int hook_expose_mgr(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img->img, 0, 0);
	return (0);
}