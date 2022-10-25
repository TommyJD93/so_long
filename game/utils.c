/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:34:21 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/01 17:48:07 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	you_won(t_data *var)
{
	mlx_put_image_to_window(var->mlx, var->mlx_wind, \
	var->imgs->background.img, var->p_x * 64, var->p_y * 64);
	mlx_put_image_to_window(var->mlx, var->mlx_wind, \
	var->imgs->win.img, (var->width / 2), (var->height / 2));
	exit(0);
}

void	you_lost(t_data *var)
{
	mlx_put_image_to_window(var->mlx, var->mlx_wind, \
	var->imgs->background.img, var->p_x * 64, var->p_y * 64);
	mlx_put_image_to_window(var->mlx, var->mlx_wind, \
	var->imgs->loose.img, ((var->width / 2) * 64) - 180, \
	((var->height / 2) * 64) - 70);
	exit(0);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	exitporkodyo(t_data *var)
{
	mlx_destroy_window(var->mlx, var->mlx_wind);
	free_matrix(var->map);
	exit(0);
	return (0);
}
