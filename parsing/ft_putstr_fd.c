/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:28:29 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/11/26 20:29:38 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_putstr_fd(char *s, int fd)
{
	int index;

	index = 0;
	if (s)
	{
		while (s[index])
		{
			write(fd, &s[index], 1);
			index++;
		}
	}
	return (index);
}
