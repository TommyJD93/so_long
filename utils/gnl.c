/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:44:15 by tterribi          #+#    #+#             */
/*   Updated: 2022/05/26 11:52:26 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*line(char *a, int i)
{
	char	*new_a;

	new_a = malloc(i + 1);
	i = 0;
	while (a[i])
	{
		new_a[i] = a[i];
		i++;
	}
	new_a[i] = '\0';
	return (new_a);
}

char	*get_next_line(int fd)
{
	char	a[999999];
	char	buffer[1];
	char	*new_a;
	int		i;

	if (fd < 0)
		return (NULL);
	i = 0;
	a[i] = 0;
	while (read(fd, buffer, 1))
	{
		a[i] = buffer[0];
		a[i + 1] = '\0';
		if (a[i] == '\0')
			break ;
		i++;
	}
	new_a = line(a, i);
	return (new_a);
}
