/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:24:59 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/02 16:20:42 by tterribi         ###   ########.fr       */
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

# define IMG_SIZE 64

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};
typedef struct s_data {
	void	*mlx;
	void	*mlx_wind;
	void	*path_map;
	char	**map;
	t_cont	*imgs;
	int		width;
	int		height;
	int		c_cont;
	int		p_x;
	int		p_y;
	int		moves;
}				t_data;

typedef struct s_dic {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_dic;

typedef struct s_cont {
	t_dic	player;
	// t_dic	player1;
	// t_dic	player2;
	// t_dic	coin;
	// t_dic	coin1;
	// t_dic	coin2;
	t_dic	wall;
	t_dic	Void;
	// t_dic	enemy;
	// t_dic	enemy1;
	// t_dic	enemy2;
	// t_dic	exit;
	t_dic	background;
	// t_dic	background2;
}				t_cont;

//------------useless------------//

typedef struct s_entities
{
	//counters
	int	p_cont;
	int	e_cont;
	int	c_cont;
	int	h_cont;
	//idk
}	t_entities;

typedef struct s_map
{
	//positions
	int		p_x;
	int		p_y;
	int		h_x;
	int		h_y;
	t_entities entities;
}	t_map;

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
void	wall_checker(char *map, t_map struct_map);

//movements
int		check(int keycode, t_map *map);
void	p_moveup(t_data *var, t_cont *imgs);
void	p_movedown(t_map map);
void	p_moveleft(t_map map);
void	p_moveright(t_map map);

//mammt fe bucchin n'ha capit che te patt pop

t_cont	load_imgs(void *mlx);
void	render(t_data *var, t_cont imgs);

//void	draw_wall(t_win g);


//quit
void	quit();
void	error_message(char *s);
#endif