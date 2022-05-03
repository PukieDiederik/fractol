#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE 600

//structs
typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_data
{
	void *mlx;
	void *window;
	t_img_data *img;
}	t_data;

// Functions
//initializes stuff from mlx
t_data *init(int width, int height);
void exit_clean(t_data *data);
//puts pixel on img
void img_put_pixel(t_img_data *img, int x, int y, unsigned int color);

//hooks
int hook_key_mgr(int keycode, t_data *data);
int hook_expose_mgr(t_data *data);

//fractals
int mandelbrot(double x_p, double y_p);

#endif
