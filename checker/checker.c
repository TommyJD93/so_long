/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:46:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/03/30 18:46:21 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_e_cont(int *p_cont, int *e_cont, int *c_cont, int *h_cont)
{
	if (*p_cont < 1)
		exit(0);
	if (*e_cont < 1)
		exit(0);
	if (*c_cont < 1)
		exit(0);
	if (*h_cont < 1)
		exit(0);
}

void	cont_inc(char c, int *p_cont, int *e_cont, int *c_cont, int *h_cont)
{
	if (c == 'P')
		p_cont++;
	if (c == 'E')
		e_cont++;
	if (c == 'C')
		c_cont++;
	if (c == 'H')
		h_cont++;
}

void	entity_checker(char **matrix, int x, int y)
{
	int	*p_cont;
	int	*e_cont;
	int	*c_cont;
	int	*h_cont;


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
			cont_inc(matrix[y][x], p_cont, e_cont, c_cont, h_cont);
			x++;
		}
		y++;
	}
	printf("%d\n", *p_cont);
	printf("%d\n", *e_cont);
	printf("%d\n", *c_cont);
	printf("%d\n", *h_cont);
	check_e_cont(p_cont, e_cont, c_cont, h_cont);
	printf("okidoki");
}

void	elements_checker(char **matrix)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			// printf("matrix[%d][%d]: %c\n", y, x, matrix[y][x]);
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

char	*elements_string_manager(char *map)
{
	int		fd;
	char	*path;
	char	*tmp;
	char	*to_check;

	path = "maps/";
	path = ft_strjoin_elements(path, map);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("read error, check the map name");
		exit(EXIT_FAILURE);
	}
	write(1, "a\n", 2);
	while (fd != -1)
	{
		write(1, "1\n", 2);
		tmp = get_next_line(fd);
		to_check = ft_strjoin(to_check, tmp);
	}
	write(1, "b\n", 2);
	return ("okidoki");
}

int main(int argc, char **argv)
{
	elements_string_manager(argv[1]);
	return 0;
}


/*
int main()
{
	int	fd;
	char *line;
	char **matrix;
	int i = 0; // y
	int x, y = 0;

	fd = open("/Users/tterribi/Desktop/so_long./maps/map1.ber", O_RDONLY);
	if (fd == -1)
	{
		printf("read error");
		exit(0);
	}
//	write(1, "1\n",2);
	matrix = (char **)malloc(sizeof(char *) * 5);
	//write(1, "2\n",2);
	for (int i = 0; i < 9; i++)
		matrix[i] = (char*)malloc(sizeof(char) * 9);
	//write(1, "3\n",2);
	i = 0;
	matrix[i++] = get_next_line(fd);
	while (i < 6)
	{
		//printf("%d\n", i);
		matrix[i] = get_next_line(fd);
		matrix[i] = ft_strtrim(matrix[i], "\n\0");
		i++;
	}
	elements_checker(matrix);
//	entity_checker(matrix, 0, 0);
}*/

/*
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
	
	printf("a\n");
	printf("gnl output:\n");
	i = 0;
	matrix[i++] = get_next_line(fd);
	// printf("------------------\n");
	// printf("%s\n", matrix[0]);
	// printf("------------------\n");
	// printf("%s\n", matrix[0]);
	// printf("------------------\n");
	// printf("b\n");
	while (i < 6)
	{
		//printf("%d\n", i);
		matrix[i] = get_next_line(fd);
		matrix[i] = ft_strtrim(matrix[i], "\n\0");
		i++;
	}
	matrix[0] = ft_strtrim(matrix[i], "\n");
	printf("matrix:\n"); 
	while (y < 5)
	{
		printf("matrix[%d]: %s ", y, matrix[y]);
		printf("\n");
		y++;
	}
	printf("\n");
	map_checker(matrix);
}*/