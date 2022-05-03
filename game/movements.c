#include "../so_long.h"

void	you_won()
{

}

bool	move_helper(t_data *var, t_cont *imgs, int x_dest, int y_dest)
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

int	check(int keycode, t_map *map, t_data var)
{
	if (keycode == 13 || keycode == 126)
		p_moveup(*map);
	if (keycode == 0 || keycode == 123)
		p_moveleft(*map);
	if (keycode == 1 || keycode == 125)
		p_movedwon(*map);
	if (keycode == 2 || keycode == 124)
		p_moveright(*map);
	return (0);
}

void	p_moveup(t_data *var, t_cont imgs, t_pos)
{
	if (!move_helper(var->map, , map.map_y+1))
	{

		mlx_put_image_to_window(var->mlx, var->mlx_wind, imgs.player.img, j * 64, i * 64);
	}
		return ;

}

void	p_movedown(t_map map)
{
	if (!move_helper(map, map.map_x, map.map_y-1))
		return ;
}

void	p_moveleft(t_map map)
{
	if (!move_helper(map, map.map_x-1, map.map_y))
		return ;
}

void	p_moveright(t_map map)
{
	if (!move_helper(map, map.map_x+1, map.map_y))
		return ;
}
