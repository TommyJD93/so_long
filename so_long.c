#include "so_long.h"

void	elements_string_manager(char *map, t_data *var)
{
	int		fd;
	char	*to_check;

	var->path_map = "maps/";
	var->path_map = ft_strjoin_elements(var->path_map, map);
	fd = open(var->path_map, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	to_check = get_next_line(fd);
	var->map = ft_split(to_check, '\n');
	var->height = ft_mat_row(var->map);
	var->width = ft_mat_col(var->map[1]);
	//invalid_elements_checker(to_check);
	//wall_checker(to_check, struct_map);


}

int	main(int argc, char **argv)
{
	t_data	var;

	if(argc != 2)
		return (0);
	elements_string_manager(argv[1], &var);
	var.mlx = mlx_init();
	var.mlx_wind = mlx_new_window(var.mlx, var.width * 64, var.height * 64, "sono frocio");
	mlx_loop(var.mlx);
	return 0;
}
/*



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

*/


/*







void	draw_wall(t_win g)
{
	int	x;
	int	y;

	y = -1;
	while (g.map.map[++y])
	{
		x = -1;
		while (g.map.map[y][++x])
		{
			if (g.map.map[y][x] == '1')
				mlx_put_image_to_window(g.mlx, g.mlx_wind, g.img.img, y * 64, x * 64);
		}
	}
	printf("wall printed\n");
}


int	main(void)
{
	void	*mlx;
	void	*wind;
	t_data	img;
	t_win	*lol;

	lol = NULL;
	img.rel_path = "img/Gerry.xpm";
	mlx = mlx_init();
	wind = mlx_new_window(mlx, 1920, 1080, "kekw");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.img = mlx_xpm_file_to_image(mlx, img.rel_path, &img.img_width, &img.img_height);
	draw_wall(*lol);
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
*/
