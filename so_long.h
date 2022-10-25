/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:24:59 by tterribi          #+#    #+#             */
/*   Updated: 2022/06/01 17:57:16 by tterribi         ###   ########.fr       */
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

typedef enum e_keys
{
	ESC = 53,
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ARROW_UP = 126,
	ARROW_DOWN = 125,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	QUIT = 36,
	START = 76,
}	t_keys;

typedef struct s_dic {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_dic;

typedef struct s_cont {
	t_dic	player;
	t_dic	coin;
	t_dic	coin1;
	t_dic	loose;
	t_dic	win;
	t_dic	wall;
	t_dic	vuoto;
	t_dic	enemy;
	t_dic	exit;
	t_dic	exit1;
	t_dic	background;
}	t_cont;

typedef struct s_coin {
	int	c_x;
	int	c_y;
}	t_coin;

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
	int		e_x;
	int		e_y;
	int		moves;
}				t_data;

typedef struct s_entities
{
	int	p_cont;
	int	e_cont;
	int	c_cont;
	int	h_cont;
}	t_entities;
//------------useless------------//

//gnl
char	*get_next_line(int fd);

//gnl utils
char	*ft_strjoin_gnl(char *backup, char *buff);
char	*ft_get_line(char *backup);
char	*ft_backup(char *backup);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_read_to_backup(int fd, char *backup);
void	print_moves(t_data *var);
// checekr utils
char	*ft_strjoin_elements(char *s1, char *s2);
void	img_selector(t_data *var, int i, int j);
// checker
void	wall_checker(char *map, t_data *var);
int		check(int keycode, t_data *var);
void	invalid_elements_checker(char *map);
void	new_lines_checker(char *map);

//movements
int		p_moveright(t_data *var);
int		p_moveleft(t_data *var);
int		p_movedown(t_data *var);
int		p_moveup(t_data *var);

//quit
void	you_won(t_data *var);
void	you_lost(t_data *var);
void	map_error(void);
//render
t_cont	load_imgs(void *mlx);
void	render(t_data *var, t_cont imgs);

//animations
int		animations(t_data *var);

int		exitporkodyo(t_data *var);
void	free_matrix(char **matrix);
#endif