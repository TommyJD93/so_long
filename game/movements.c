#include "../so_long.h"

void	you_won(t_data *var)
{
	mlx_put_image_to_window(var->mlx, var->mlx_wind, &var->imgs->background.img, var->p_x * 64, var->p_y * 64);
	mlx_put_image_to_window(var->mlx, var->mlx_wind, &var->imgs->win.img, (var->width/2), (var->height/2));
}

void	you_lost(t_data *var, int x_dest, int y_dest)
{
	mlx_put_image_to_window(var->mlx, var->mlx_wind, &var->imgs->background.img, var->p_x * 64, var->p_y * 64);
	mlx_put_image_to_window(var->mlx, var->mlx_wind, &var->imgs->loose.img, (var->width/2), (var->height/2));
}

bool	move_helper(t_data *var, int x_dest, int y_dest)
{
	if (var->map[x_dest][y_dest] == '1')
		return (false);
	if (var->map[x_dest][y_dest] == '0')
		var->p_x = x_dest;
		var->p_y = y_dest;
		return (true);
	if (var->map[x_dest][y_dest] == 'C')
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, &var->imgs->background.img, x_dest * 64, y_dest * 64);
		var->p_x = x_dest;
		var->p_y = y_dest;
		return (true);
	}
	if (var->map[x_dest][y_dest] == 'H')
		you_lost(var, x_dest, y_dest);
	if (var->map[x_dest][y_dest] == 'E' && var->c_cont == 0)
		you_won(var);
	else
		return (false);
}

int	check(int keycode, t_data *var)
{
	if (keycode == 13 || keycode == 126)
		p_moveup(var);
	if (keycode == 0 || keycode == 123)
		
	if (keycode == 1 || keycode == 125)
		
	if (keycode == 2 || keycode == 124)
	
	return (0);
}

void	p_moveup(t_data *var)
{
	if (!move_helper(var->map, var->p_x, var->p_y))
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, &var->imgs->player.img, var->p_x * 64, var->p_y * 64);
	}
		return ;

}
