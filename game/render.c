/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:37:21 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/01 18:00:29 by tterribi         ###   ########.fr       */
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
	imgs.coin = load_img(mlx, "img/coin.xpm");
	imgs.coin1 = load_img(mlx, "img/coin1.xpm");
	imgs.loose = load_img(mlx, "img/looser.xpm");
	imgs.win = load_img(mlx, "img/win.xpm");
	imgs.wall = load_img(mlx, "img/wall.xpm");
	imgs.vuoto = load_img(mlx, "img/Void.xpm");
	imgs.enemy = load_img(mlx, "img/Tarrare1.xpm");
	imgs.exit = load_img(mlx, "img/exit.xpm");
	imgs.exit1 = load_img(mlx, "img/exit1.xpm");
	imgs.background = load_img(mlx, "img/Void.xpm");
	return (imgs);
}

void	render(t_data *var, t_cont imgs)
{
	int	i;
	int	j;

	i = 0;
	var->c_cont = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			mlx_put_image_to_window(var->mlx, var->mlx_wind, \
			imgs.vuoto.img, j * 64, i * 64);
			img_selector(var, i, j);
			j++;
		}
		i++;
	}
}
