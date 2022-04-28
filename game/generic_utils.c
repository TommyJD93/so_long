#include "so_long.h"

void	error_message(char *s)
{
	ft_printf("%s", s);
	exit(0);
}

void	map_allocator(t_map map)
{
	int rows;
	int fd;

	fd = open(map.name, O_RDONLY);
	if (fd == -1)
		error_message("_ERROR_WHILE_ALLOCATING_THE_MAP_");
	map.map = malloc(sizeof(char) * rows)
}