/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:43:20 by tterribi          #+#    #+#             */
/*   Updated: 2022/04/07 12:44:44 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// bool	is_in_string(char c, char const *str)
// {
// 	while (*str)
// 	{
// 		if (*str == c)
// 			return (true);
// 		str++;
// 	}
// 	return (false);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	*buffer;

// 	if (!s1 || !set)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[j] && is_in_string(s1[j], set))
// 		j++;
// 	k = ft_strlen((char *) s1);
// 	while (k > j && is_in_string(s1[k - 1], set))
// 		k--;
// 	buffer = (char *) malloc(sizeof(*s1) * (k - j + 1));
// 	if (!buffer)
// 		return (NULL);
// 	i = 0;
// 	while (j < k)
// 		buffer[i++] = s1[j++];
// 	buffer[i] = '\0';
// 	return ((char *)buffer);
// }
