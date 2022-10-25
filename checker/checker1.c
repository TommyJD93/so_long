/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:15:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/01 17:52:41 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_error(void)
{
	ft_printf("\033[31m_MAP_INVALID_BORDERS_\033[0m");
	exit(0);
}

void	conditions(char **matrix, int max_y, int max_x)
{
	int	x;
	int	y;

	y = -1;
	while (matrix[++y])
	{
		x = -1;
		while (matrix[y][++x])
		{
			if (matrix[0][x] != '1')
				map_error();
			else if (matrix[y][0] != '1')
				map_error();
			else if (matrix[y][max_x] != '1')
				map_error();
			else if (matrix[max_y][x] != '1')
				map_error();
		}
	}
}

void	wall_checker(char *map, t_data *var)
{
	char	**matrix;

	matrix = ft_split(map, '\n');
	var->width = ft_mat_col(matrix[0]);
	var->height = ft_mat_row(matrix);
	conditions(matrix, var->height, var->width);
	ft_printf("[\033[32mwall checker\033[0m]\n");
	free_matrix(matrix);
}

void	print_moves(t_data *var)
{
	char	*s;

	s = ft_itoa(var->moves);
	img_selector(var, 0, 1);
	img_selector(var, 0, 0);
	mlx_string_put(var->mlx, var->mlx_wind, 10, 15, 0x0, "MOVES: ");
	mlx_string_put(var->mlx, var->mlx_wind, 8, 14, 0x0, "MOVES: ");
	mlx_string_put(var->mlx, var->mlx_wind, 12, 16, 0x0, "MOVES: ");
	mlx_string_put(var->mlx, var->mlx_wind, 10, 15, 16777215, "MOVES: ");
	ft_putstr("Moves: ");
	mlx_string_put(var->mlx, var->mlx_wind, 80, 15, 0x0, s);
	mlx_string_put(var->mlx, var->mlx_wind, 78, 14, 0x0, s);
	mlx_string_put(var->mlx, var->mlx_wind, 82, 16, 0x0, s);
	mlx_string_put(var->mlx, var->mlx_wind, 80, 15, 16777215, s);
	ft_putstr(s);
	ft_putchar_void('\n');
	free(s);
}
