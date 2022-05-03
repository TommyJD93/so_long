#include "../so_long.h"

void	you_won()
{

}

bool	move_helper(t_data *var)
{
	if (var->map[x_dest][y_dest] == '1')
		return (false);
	if (var->map[x_dest][y_dest] == 'C')
		mlx_put_image_to_window(var->mlx, var->mlx_wind, imgs->player.img, x_dest * 64, y_dest * 64);
	if (var->map[x_dest][y_dest] == 'H')
	if (var->map[x_dest][y_dest] == 'E' && var->c_cont == 0)
		you_won();
	else
		return (false);
}

int	check(int keycode, t_data *var)
{
	if (keycode == 13 || keycode == 126)
		p_moveup(var, var->imgs);
	if (keycode == 0 || keycode == 123)
		
	if (keycode == 1 || keycode == 125)
		
	if (keycode == 2 || keycode == 124)
	
	return (0);
}

void	p_moveup(t_data *var, t_cont *imgs)
{
	if (!move_helper(var->map))
	{

		mlx_put_image_to_window(var->mlx, var->mlx_wind, &var->imgs->player.img, j * 64, i * 64);
	}
		return ;

}
