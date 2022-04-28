/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:37:21 by tterribi          #+#    #+#             */
/*   Updated: 2022/04/20 18:27:59 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_wall(t_win g)
{
	int	x;
	int	y;
	int	a;
	int	b;

	y = -1;
	while (g.map.map[++y])
	{
		x = -1;
		while (g.map.map[y][++x])
		{
			if (g.map.map[y][x] == '1')
				mlx_put_image_to_window(g.mlx, g.mlx_wind, g.img.img, y * 64, x * 64);
		}
	}
	printf("wall printed\n");
}

void	render_helper()
{
	
}


void	render(t_map map)
{
	int		fd;
	char	*s;
	int		i;

	fd = open(map.name, O_RDONLY);
	if (fd == -1)
		error_message("_AN_ERROR_OCCURRED_WHILE_RENDERING_THE_MAP_: 01");
	
	while (s)
	{
	
	}
	
	
}
