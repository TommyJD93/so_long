#include "so_long.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;













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

// int	main(void)

// 	t_data	*img;
// 	char	*img_rel_path;
// 	int		img_width;
// 	int		img_height;

// 	mlx_init(img.mlx);
// 	img_rel_path = "img/player.xpm";
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "kekw");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img = mlx_xpm_file_to_image(mlx, img_rel_path, &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, mlx_wind, img, 1 * 64, 1 * 64);
// 	mlx_loop(mlx);
// }

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	int		img_width;
	int		img_height;
	char	*addr;
	char	*rel_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*wind;
	t_data	img;

	img.rel_path = "img/player.xpm";
	mlx = mlx_init();
	wind = mlx_new_window(mlx, 1920, 1080, "kekw");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.img = mlx_xpm_file_to_image(mlx, img.rel_path, &img.img_width, &img.img_height);
	mlx_put_image_to_window(mlx, wind, img.img, 1 * 64, 1 * 64);

	mlx_loop(mlx);








	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// y = 0;
	// while (y < 100)
	// {
	// 	x = 0;
	// 	while (x < 100)
	// 	{
	// 		if (x == 1 || y == 100 || x == 1 || y == 100)
	// 		{
	// 			my_mlx_pixel_put(&img, x, y, 0xccff00);
	// 			mlx_put_image_to_window(mlx, mlx_win, img.img, x, y);
	// 		}
	// 		else
	// 		{
	// 			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 			mlx_put_image_to_window(mlx, mlx_win, img.img, x, y);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
//	mlx_loop(mlx);
}
// my_mlx_pixel_put(&img, j, i, 0x00FF0000);
// mlx_put_image_to_window(mlx, mlx_win, img.img, j, i);