/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:33:09 by tterribi          #+#    #+#             */
/*   Updated: 2022/03/23 15:45:35 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	*reader_caller()

void obj_printer(char c, t_win win)
{
	void	*img;
	
	if (c == '1')
			img = mlx_xpm_file_to_image(win.mlx, "", &img_width, &img_height);
			mlx_put_image_to_window(win.mlx, win.mlx_win, img, 1 * 64, 1 * 64);
	else if (c == 'C')
	
	else if (c == 'P')
	
	else if (c == '0')
	
	else if (c == 'E')
}

char	*map_manager(char **matrix, char map_path)
{
	int		fd;
	char	*line;
	
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		printf("read error");
		exit(0);
	}
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		while (line)
		{
			obj_printer()
		}
	}
}