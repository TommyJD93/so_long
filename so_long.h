/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:24:59 by tterribi          #+#    #+#             */
/*   Updated: 2022/03/23 16:45:19 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "get-next-line/get_next_line.h"
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <strings.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

//gnl
char	*get_next_line(int fd);

//gnl utils
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *backup, char *buff);
char	*ft_get_line(char *backup);
char	*ft_backup(char *backup);
char	*ft_read_to_backup(int fd, char *backup);

// checekr utils
bool	is_in_strings(char c, char *str);


#endif