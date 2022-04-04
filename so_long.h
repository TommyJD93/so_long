/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:24:59 by tterribi          #+#    #+#             */
/*   Updated: 2022/04/04 13:23:19 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_entityes
{
	int	p_cont;
	int	e_cont;
	int	c_cont;
	int	h_cont;
}	t_entityes;
 

//gnl
char	*get_next_line(int fd);

//gnl utils
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_gnl(char *backup, char *buff);
char	*ft_get_line(char *backup);
char	*ft_backup(char *backup);
char	*ft_read_to_backup(int fd, char *backup);

//utils
char	*ft_strtrim(char const *s1, char const *set);

// checekr utils
bool	is_in_strings(char c, char *str);
char	*ft_strjoin_elements(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);


#endif