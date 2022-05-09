#include "../so_long.h"

void	collectible_animation(t_data *var)
{
	mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->exit1.img, var->e_y * 64, var->e_x * 64);
}

// void	exit_animation(t_data *var)
// {
// 	if (var->c_cont == 0)
// 		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->exit1.img, var->e_y * 64, var->e_x * 64);
// }

int	animations(t_data *var)
{
//	exit_animation(var);
	return (1);
}