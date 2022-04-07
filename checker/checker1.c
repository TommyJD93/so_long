/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:15:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/04/07 18:01:24 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wall_checker(char *map)
{
	char	**matrix;
	int		y;
	int		x;

	matrix = ft_split(map, '\n');
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[1][x] == 1 && matrix[y][1] == 1 && matrix[y][1] == 1 && matrix[y][1] == 1)
			x++;
		}
		y++;
	}
}