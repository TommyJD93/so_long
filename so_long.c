/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:39:07 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/01 17:59:29 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	elements_string_manager(char *map, t_data *var)
{
	int		fd;
	char	*to_check;

	var->path_map = "maps/";
	var->path_map = ft_strjoin_elements(var->path_map, map);
	fd = open(var->path_map, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	to_check = get_next_line(fd);
	new_lines_checker(to_check);
	var->map = ft_split(to_check, '\n');
	var->height = ft_mat_row(var->map) + 1;
	var->width = ft_mat_col(var->map[1]) + 1;
	var->moves = 0;
	invalid_elements_checker(to_check);
	wall_checker(to_check, var);
	free(var->path_map);
	free(to_check);
}

int	main(int argc, char **argv)
{
	t_data	var;
	t_cont	imgs;

	if (argc != 2)
		return (0);
	elements_string_manager(argv[1], &var);
	var.mlx = mlx_init();
	var.mlx_wind = mlx_new_window(var.mlx, (var.width + 1) * 64, \
	(var.height + 1) * 64, "so_long");
	imgs = load_imgs(var.mlx);
	var.imgs = &imgs;
	render(&var, imgs);
	mlx_hook(var.mlx_wind, 2, 1L << 0, check, &var);
	mlx_hook(var.mlx_wind, 17, 0, exitporkodyo, &var);
	mlx_loop(var.mlx);
}
