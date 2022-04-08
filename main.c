#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;













// int main(void)
// {
// 	char	**matrix;
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	main(void)
{
	void	*mlx;
	void	*mlx_wind;
	void	*img;
	char	*img_rel_path;
	int		img_width;
	int		img_height;

	img_rel_path = "img/Gerry-Scotti-Carriera.xpm";
	img = mlx_xpm_file_to_image(mlx, img_rel_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_wind, img, 1 * 64, 1 * 64);
	mlx_loop(mlx);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int	y;
// 	int	x;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "kekw");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	y = 0;
// 	while (y < 100)
// 	{
// 		x = 0;
// 		while (x < 100)
// 		{
// 			if (x == 1 || y == 100 || x == 1 || y == 100)
// 			{
// 				my_mlx_pixel_put(&img, x, y, 0xccff00);
// 				mlx_put_image_to_window(mlx, mlx_win, img.img, x, y);
// 			}
// 			else
// 			{
// 				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
// 				mlx_put_image_to_window(mlx, mlx_win, img.img, x, y);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_loop(mlx);
// }
//my_mlx_pixel_put(&img, j, i, 0x00FF0000);
//mlx_put_image_to_window(mlx, mlx_win, img.img, j, i);