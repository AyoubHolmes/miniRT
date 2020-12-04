/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:47:35 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/04 12:21:23 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_isint(char *c)
{
	int i;

	i = 0;
	if (c[0] == '-' || c[0] == '+')
		i = 1;
	while (c[i] != '\0')
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_ispositiveint(char *c)
{
	int i;

	i = 0;
	if (c[0] == '+')
		i = 1;
	while (c[i] != '\0')
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_isfloat(char *c)
{
	int i;
	int k;

	i = 0;
	if (c[0] == '-' || c[0] == '+')
		i = 1;
	while (c[i] != '\0')
	{
		if (!ft_isdigit(c[i]) && c[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		ft_ispositivefloat(char *c)
{
	int i;
	int k;

	i = 0;
	if (c[0] == '+')
		i = 1;
	while (c[i] != '\0')
	{
		if (!ft_isdigit(c[i]) && c[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
