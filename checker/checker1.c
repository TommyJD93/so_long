/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:15:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/04/08 17:24:21 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_error(void)
{
	printf("\033[31m_MAP_INVALID_BORDERS_\033[0m");
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

void	wall_checker(char *map)
{
	char	**matrix;
	int		y;
	int		x;
	int		max_y;
	int		max_x;

	matrix = ft_split(map, '\n');
	y = -1;
	max_x = ft_mat_col(matrix[0]);
	max_y = ft_mat_row(matrix);
	conditions(matrix, max_y, max_x);
	printf("[\033[32mwall checker\033[0m]\n");
}
