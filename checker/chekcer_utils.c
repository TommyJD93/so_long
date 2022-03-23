/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekcer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:13:12 by tterribi          #+#    #+#             */
/*   Updated: 2022/03/23 16:33:29 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_in_strings(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}
