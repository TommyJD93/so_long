/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:00:34 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/01 18:01:13 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_selector_2(t_data *var, int i, int j)
{
	if (var->map[i][j] == 'E')
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->exit.img, j * 64, i * 64);
		var->e_x = j;
		var->e_y = i;
	}
	if (var->map[i][j] == 'H')
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->enemy.img, j * 64, i * 64);
	else if (var->map[i][j] == 'P')
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->player.img, j * 64, i * 64);
		var->p_x = j;
		var->p_y = i;
	}
}

void	img_selector(t_data *var, int i, int j)
{
	if (var->map[i][j] == '1')
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->wall.img, j * 64, i * 64);
	if (var->map[i][j] == 'C')
	{
		var->c_cont++;
		mlx_put_image_to_window(var->mlx, var->mlx_wind, \
		var->imgs->coin.img, j * 64, i * 64);
	}
	else
		img_selector_2(var, i, j);
}
