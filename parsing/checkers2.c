/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 12:53:48 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/23 11:36:10 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_isintensityfloat(char *c)
{
	int		i;
	float	k;

	i = 0;
	if (c[0] == '+')
		i = 1;
	while (c[i] != '\0')
	{
		if (!ft_isdigit(c[i]) && c[i] != '.')
			return (0);
		i++;
	}
	k = ft_atof(c);
	if (k >= 0 && k <= 1)
		return (1);
	return (0);
}

int		ft_iscolorfloat(char *c)
{
	int		i;
	float	k;

	i = 0;
	if (c[0] == '+')
		i = 1;
	while (c[i] != '\0')
	{
		if (!ft_isdigit(c[i]) && c[i] != '.')
			return (0);
		i++;
	}
	k = ft_atof(c);
	if (k > 255)
		return (0);
	return (1);
}

int		ft_isvector(char *c, int (*func)())
{
	char	**vector;
	int		i;

	if (ft_nbr_words(c, ',') != 3)
		return (0);
	vector = ft_split(c, ',');
	i = 0;
	while (i < 3)
	{
		if (!func(vector[i]))
			return (0);
		i++;
	}
	return (1);
}
