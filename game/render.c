/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:37:21 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/09 15:59:42 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_dic	load_img(void *mlx, char *path)
{
	int		img_width;
	int		img_height;
	t_dic	win_img;

	win_img.img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	win_img.addr = mlx_get_data_addr(win_img.img, &win_img.bpp,
			&win_img.line_len, &win_img.endian);
	return (win_img);
}

t_cont	load_imgs(void *mlx)
{
	t_cont	imgs;

	imgs.player = load_img(mlx, "img/dioporco.xpm");
	// imgs.player1 = load_img(mlx, "sprites/64px/Player/Player_1.xpm");
	// imgs.player2 = load_img(mlx, "sprites/64px/Player/Player_2.xpm");
	imgs.coin = load_img(mlx, "img/coins.xpm");
	imgs.coin1 = load_img(mlx, "img/coin1.xpm");
	// imgs.coin2 = load_img(mlx, "sprites/64px/Coin/Coin_2.xpm");
	imgs.loose = load_img(mlx, "img/looser.xpm");
	imgs.win = load_img(mlx, "img/win.xpm");
	imgs.wall = load_img(mlx, "img/wall.xpm");
	imgs.Void = load_img(mlx, "img/Void.xpm");
	imgs.enemy = load_img(mlx, "img/Tarrare1.xpm");
	// imgs.enemy1 = load_img(mlx, "sprites/64px/Enemy/Enemy_1.xpm");
	// imgs.enemy2 = load_img(mlx, "sprites/64px/Enemy/Enemy_2.xpm");
	imgs.exit = load_img(mlx, "img/exit.xpm");
	imgs.exit1 = load_img(mlx, "img/exit1.xpm");
	imgs.background = load_img(mlx, "img/Void.xpm");
	// imgs.background2 = load_img(mlx, "sprites/64px/Background/Background2.xpm");
	return (imgs);
}

void	img_selector(t_data *var, int i, int j, int *n)
{
	if (var->map[i][j] == '1')
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->wall.img, j * 64, i * 64);
	if (var->map[i][j] == 'C')
	{
		var->c_cont++;
		var->coins[n].c_x = j;
		var->coins[n].c_y = i;
		n++;
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->coin.img, j * 64, i * 64);
	}
	if (var->map[i][j] == 'E')
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->exit.img, j * 64, i * 64);
		var->e_x = j;
		var->e_y = i;
	}
	if (var->map[i][j] == 'H')
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->enemy.img, j * 64, i * 64);
	else if (var->map[i][j] == 'P')
	{
		mlx_put_image_to_window(var->mlx, var->mlx_wind, var->imgs->player.img, j * 64, i * 64);
		var->p_x = j;
		var->p_y = i;
	}
}

void	render(t_data *var, t_cont imgs)
{
	int	i;
	int	j;
	int	*n;

	n = 0;
	i = 0;
	var->c_cont = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			mlx_put_image_to_window(var->mlx, var->mlx_wind, imgs.Void.img, j * 64, i * 64);
			img_selector(var, i, j, &n);
			j++;
		}
		i++;
	}
	int b = 0;
	while (&var->coins[b])
	{
		printf("x(%d) y(%d)", var->coins[b].c_x, var->coins[b].c_y);
	}
	
}
