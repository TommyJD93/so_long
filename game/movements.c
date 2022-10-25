/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:30:43 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/01 17:50:39 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	move_helper(t_data *var, int x_dest, int y_dest)
{
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
	var->moves++;
	print_moves(var);
	return (false);
}

int	p_moveup(t_data *var)
{
	if (!move_helper(var, var->p_x, (var->p_y - 1)))
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->background.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->player.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->background.img, var->p_x * 64, (var->p_y + 1) * 64);
	}
	return (1);
}

int	p_movedown(t_data *var)
{
	if (!move_helper(var, var->p_x, (var->p_y + 1)))
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->background.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->player.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->background.img, var->p_x * 64, (var->p_y - 1) * 64);
	}
	return (1);
}

int	p_moveleft(t_data *var)
{
	if (!move_helper(var, (var->p_x - 1), var->p_y))
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->background.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->player.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->background.img, (var->p_x + 1) * 64, var->p_y * 64);
	}
	return (1);
}

int	p_moveright(t_data *var)
{
	if (!move_helper(var, (var->p_x + 1), var->p_y))
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->background.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->player.img, var->p_x * 64, var->p_y * 64);
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->background.img, (var->p_x - 1) * 64, var->p_y * 64);
	}
	return (1);
}
