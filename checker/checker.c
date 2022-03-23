/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:46:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/03/23 17:49:26 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_checker(char **matrix)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (matrix[y][x])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] != '0' || matrix[y][x] != '1'
				|| matrix[y][x] != 'P' || matrix[y][x] != 'E'
					|| matrix[y][x] != 'C' || matrix[y][x] != 'H' || matrix[y][x] != '\n')
			{
				printf("_INVALID_MAP_");
				exit(0);
			}
			x++;
		}
		y++;
	}
	printf("good soup");
}

int main(void)
{
	int	fd;
	char *line;
	char **matrix;
	int i = 0; // y
	int x, y = 0;

	fd = open("../maps/map1.ber", O_RDONLY);
	if (fd == -1)
	{
		printf("read error");
		exit(0);
	}
	matrix = (char **)malloc(sizeof(char *) * 5);
	for (int i = 0; i < 9; i++)
		matrix[i] = (char*)malloc(sizeof(char) * 9);
	i = 0;
	printf("a\n");
	matrix[i++] = get_next_line(fd);
	printf("b\n");
	while (i < 6)
	{
		printf("%d\n", i);
		matrix[i] = get_next_line(fd);
		i++;
	}
	while (y < 5)
	{
		printf("%s ", matrix[y]);
		printf("\n");
		y++;
	}
	printf("\n");
	map_checker(matrix);
}