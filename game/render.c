/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:37:21 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/03 12:24:47 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	draw_wall(t_win g)
// {
// 	int	x;
// 	int	y;
// 	int	a;
// 	int	b;

// 	y = -1;
// 	while (g.map.map[++y])
// 	{
// 		x = -1;
// 		while (g.map.map[y][++x])
// 		{
// 			if (g.map.map[y][x] == '1')
// 				mlx_put_image_to_window(g.mlx, g.mlx_wind, g.img.img, y * 64, x * 64);
// 		}
// 	}
// 	printf("wall printed\n");
// }

// void	render_helper()
// {
	
// }

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

	imgs.player = load_img(mlx, "img/Tarrare1.xpm");
	// imgs.player1 = load_img(mlx, "sprites/64px/Player/Player_1.xpm");
	// imgs.player2 = load_img(mlx, "sprites/64px/Player/Player_2.xpm");
	// imgs.coin = load_img(mlx, "sprites/64px/Coin/Coin.xpm");
	// imgs.coin1 = load_img(mlx, "sprites/64px/Coin/Coin_1.xpm");
	// imgs.coin2 = load_img(mlx, "sprites/64px/Coin/Coin_2.xpm");
	imgs.wall = load_img(mlx, "img/wall.xpm");
	imgs.Void = load_img(mlx, "img/Void.xpm");
	// imgs.enemy = load_img(mlx, "sprites/64px/Enemy/Enemy.xpm");
	// imgs.enemy1 = load_img(mlx, "sprites/64px/Enemy/Enemy_1.xpm");
	// imgs.enemy2 = load_img(mlx, "sprites/64px/Enemy/Enemy_2.xpm");
	// imgs.exit = load_img(mlx, "sprites/64px/Exit/Exit.xpm");
	//imgs.background = load_img(mlx, "sprites/64px/Background/Background.xpm");
	// imgs.background2 = load_img(mlx, "sprites/64px/Background/Background2.xpm");
	return (imgs);
}

void	render(t_data *var, t_cont imgs)
{
	int	i;
	int	j;

	i = 0;
	printf("CULO\n");
	printf("pisello\n");


	while (var->map[i])
	{
		j = 0;
		printf("i: %d\n", i);
		while (var->map[i][j])
		{
			mlx_put_image_to_window(var->mlx, var->mlx_wind, imgs.Void.img, j * 64, i * 64);
			printf("j: %d\n", j);
			if (var->map[i][j] == '1')
				mlx_put_image_to_window(var->mlx, var->mlx_wind, imgs.wall.img, j * 64, i * 64);
			// else if (var->map[i][j] == '0')
			else if (var->map[i][j] == 'P')
				mlx_put_image_to_window(var->mlx, var->mlx_wind, imgs.player.img, j * 64, i * 64);
			//else
				//imgs.wall.addr="si";
			j++;
		}
		i++;
	}
	printf("cacca");
}

