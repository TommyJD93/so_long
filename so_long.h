/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:24:59 by tterribi          #+#    #+#             */
/*   Updated: 2022/04/12 17:32:40 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

typedef struct s_entities
{
	//counters
	int	p_cont;
	int	e_cont;
	int	c_cont;
	int	h_cont;

	
}	t_entities;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_wind;

}	t_win;
// typedef struct s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;

//gnl
char	*get_next_line(int fd);

//gnl utils
char	*ft_strjoin_gnl(char *backup, char *buff);
char	*ft_get_line(char *backup);
char	*ft_backup(char *backup);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_read_to_backup(int fd, char *backup);

// checekr utils
char	*ft_strjoin_elements(char *s1, char *s2);

// checker
void	wall_checker(char *map);

//quit
void	quit();
#endif