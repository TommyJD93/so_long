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
	var->height = ft_mat_row(var->map) + 1;
	var->width = ft_mat_col(var->map[1]) + 1;
	//invalid_elements_checker(to_check);
	//wall_checker(to_check, struct_map);
}
int	you_lost2(t_data *var)
{
	mlx_destroy_window(var->mlx, var->mlx_wind);
	exit(0);
	return (0);
}
int	main(int argc, char **argv)
{
	t_data	var;
	t_cont	imgs;
//	t_map	map;
	if(argc != 2)
		return (0);
	elements_string_manager(argv[1], &var);
	var.mlx = mlx_init();
	var.mlx_wind = mlx_new_window(var.mlx, var.width * 64, var.height * 64, "sono frocio");
	imgs = load_imgs(var.mlx);
	var.imgs = &imgs;
	var.c_cont = 1;
	render(&var, imgs);
	mlx_hook(var.mlx_wind, 2, 1L << 0, check, &var);
	mlx_hook(var.mlx_wind, 17, 0, you_lost2, &var);
	mlx_loop(var.mlx);
	return 0;
}
