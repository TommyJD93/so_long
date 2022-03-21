#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	i;
	int	j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "kekw");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	i = 0;
	j = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			// if (i == 1 || i == 100 || j == 1 || j == 100)
			// {
			// 	my_mlx_pixel_put(&img, j, i, 0xccff00);
			// 	mlx_put_image_to_window(mlx, mlx_win, img.img, j, i);
			// }
			// else
			// {
				my_mlx_pixel_put(&img, j, i, 0x00FF0000);
				mlx_put_image_to_window(mlx, mlx_win, img.img, j, i);
			// }
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
//my_mlx_pixel_put(&img, j, i, 0x00FF0000);
//mlx_put_image_to_window(mlx, mlx_win, img.img, j, i);