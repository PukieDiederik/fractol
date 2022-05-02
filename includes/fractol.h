#ifndef FRACTOL_H
# define FRACTOL_H


//structs
typedef struct s_data
{
	void *mlx;
	void *window;
	void *img;
}	t_data;

// Functions
//initializes stuff from mlx
t_data *init(int width, int height);
void exit_clean(t_data *data);

//hooks
int hook_key_mgr(int keycode, t_data *data);


#endif
