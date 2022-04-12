/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:46:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/04/08 17:35:45 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	entity_counter(t_entities entities, char *map)
{
	char	**matrix;
	int		x;
	int		y;

	matrix = ft_split(map, '\n');
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'P')
				entities.p_cont++;
			else if (matrix[y][x] == 'E')
				entities.e_cont++;
			else if (matrix[y][x] == 'C')
				entities.c_cont++;
			else if (matrix[y][x] == 'H')
				entities.h_cont++;
			x++;
		}
		y++;
	}
}

void	entitiy_checker(t_entities entities, char *map)
{
	entity_counter(entities, map);
	if (entities.p_cont != 1)
	{
		ft_printf("\033[31m_INVALID_NUMBER_OF_PLAYERS\033[0m]");
		exit(0);
	}
	if (entities.e_cont != 1)
	{
		ft_printf("\033[31m_INVALID_NUMBER_OF_EXIT\033[0m]");
		exit(0);
	}
	if (entities.c_cont < 1)
	{
		ft_printf("\033[31m_INVALID_NUMBER_OF_COLLECTIBLES\033[0m]");
		exit(0);
	}
	printf("[\033[32mentitiy checker\033[0m]\n");
}

void	invalid_elements_checker(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'E' && map[i] != 'C'
			&& map[i] != 'P' && map[i] != 'H' && map[i] != '\n')
		{
			printf("_INVALID_MAP_, wrong cell: [%d]", i);
			exit(0);
		}
		i++;
	}
	printf("[\033[32minvalid elements passed\033[0m]\n");
}

void	elements_string_manager(t_entities entities, char *map)
{
	int		fd;
	char	*path;
	char	*to_check;

	path = "maps/";
	path = ft_strjoin_elements(path, map);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("\033[31mread error, check the map name\033[0m]");
		exit(EXIT_FAILURE);
	}
	to_check = get_next_line(fd);
	write(1, "b\n", 2);
	invalid_elements_checker(to_check);
	wall_checker(to_check);
}

int	main(int argc, char **argv)
{
	t_entities	entities;

	elements_string_manager(entities, argv[1]);
	return (0);
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
	invalid_elements_checker(matrix);
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