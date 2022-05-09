#include "../so_long.h"

void	you_won(t_data *var)
{
	printf("PORCODDIO HAI VINTO");
	mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->background.img, var->p_x * 64, var->p_y * 64);
	mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->win.img, (var->width/2), (var->height/2));
	exit(0);
}

void	you_lost(t_data *var)
{
	printf("diocane\n");
	mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->background.img, var->p_x * 64, var->p_y * 64);
	mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->loose.img, ((var->width / 2) * 64) - 180, ((var->height / 2) * 64) - 70);
	printf("x(%d) y(%d) type: %c", var->p_x, var->p_y, var->map[var->p_y][var->p_x]);

}

bool	move_helper(t_data *var, int x_dest, int y_dest)
{
	printf("trying to move on: %c\n", var->map[y_dest][x_dest]);
	if (var->map[y_dest][x_dest] == '1')
		return (true);
	else if (var->map[y_dest][x_dest] == 'H')
		you_lost(var);
	else if (var->map[y_dest][x_dest] == 'E' && var->c_cont == 0)
		you_won(var);
	else if (var->map[y_dest][x_dest] == 'E' && var->c_cont != 0)
		return (true);
	else if (var->map[y_dest][x_dest] == 'C')
		var->c_cont--;
	var->map[var->p_y][var->p_x] = '0';
	var->p_x = x_dest;
	var->p_y = y_dest;
	return (false);
}

int	p_moveup(t_data *var)
{
	if (!move_helper(var, var->p_x, (var->p_y - 1)))
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->background.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->player.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->background.img, var->p_x * 64, (var->p_y + 1) * 64);
	}
	return (1);
}

int	p_movedown(t_data *var)
{
	if (!move_helper(var, var->p_x, (var->p_y + 1)))
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->background.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->player.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->background.img, var->p_x * 64, (var->p_y - 1) * 64);
	}
	return (1);
}

int	p_moveleft(t_data *var)
{
	if (!move_helper(var, (var->p_x - 1), var->p_y))
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->background.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->player.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->background.img, (var->p_x + 1) * 64, var->p_y * 64);
	}
	return (1);
}

int	p_moveright(t_data *var)
{
	if (!move_helper(var, (var->p_x + 1), var->p_y))
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->background.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->player.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->background.img, (var->p_x - 1) * 64, var->p_y * 64);
	}
	return (1);
}

int	check(int keycode, t_data *var)
{
	if (keycode == KEY_UP || keycode == ARROW_UP)
	{
		printf("2: UP\n");
		var->moves += p_moveup(var);
	}
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
	{
		printf("2: DOWN\n");
		var->moves += p_movedown(var);
	}
	if (keycode == KEY_LEFT || keycode == ARROW_LEFT)
	{
		printf("2: LEFT\n");
		var->moves += p_moveleft(var);
	}	
	if (keycode == KEY_RIGHT || keycode == ARROW_RIGHT)
	{
		printf("2: RIGHT\n");
		var->moves += p_moveright(var);
	}
	printf("moves: %d\n", var->moves);
	return (0);
}
