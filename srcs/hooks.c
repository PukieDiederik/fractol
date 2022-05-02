#include "mlx.h"
#include "fractol.h"
#include <stdio.h>

//manages key hooks
int hook_key_mgr(int keycode, t_data *data)
{
	if(keycode == 65307) //ESC
		exit_clean(data);
	return (0);
}