/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:46:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/03/23 20:00:31 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_checker(char **matrix)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			printf("matrix[%d][%d]: %c\n", y, x, matrix[y][x]);
			if (matrix[y][x] != '1' && matrix[y][x] != '0'
				&& matrix[y][x] != 'E' && matrix[y][x] != 'C'
					&& matrix[y][x] != 'P' && matrix[y][x] != 'H')
			{
				printf("_INVALID_MAP_, wrong cell: [%d][%d]", y, x);
				exit(0);
			}
			x++;
		}
		y++;
		printf("\n");
	}
	printf("good soup");
}

int

void	entity_checker(char **matrix)
{
	int	p_cont;
	int e_cont;
	int c_cont;
	int h_cont;
	int y;
	int x;

	p_cont = 0;
	e_cont = 0;
	c_cont = 0;
	h_cont = 0;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'P')
				p_cont++;
			if (matrix[y][x] == 'E')
				e_cont++;
			if (matrix[y][x] == 'C')
				c_cont++;
			if (matrix[y][x] == 'H')
				h_cont++;
			x++;
		}
		y++;
	}

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
	matrix[0] = ft_strtrim(matrix[i], "\n\0");
	printf("b\n");
	while (i < 6)
	{
		printf("%d\n", i);
		matrix[i] = get_next_line(fd);
		matrix[i] = ft_strtrim(matrix[i], "\n\0");
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