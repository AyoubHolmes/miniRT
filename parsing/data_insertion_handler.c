/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_insertion_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:21:49 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/04 12:19:38 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			dat_id_helper(char **data)
{
	if (data[0][0] == 'r' && data[0][1] == 'o' && data[0][2] == 't' \
	&& ft_strlen(data[0]) == 3)
		return (-4);
	else if (data[0][0] == 't' && data[0][1] == 'r' && data[0][2] == 's' \
	&& ft_strlen(data[0]) == 3)
		return (-3);
	else if (data[0][0] == '#')
		return (-2);
	if (data[0][0] == 'R' && ft_strlen(data[0]) == 1)
		return (0);
	else if (data[0][0] == 'A' && ft_strlen(data[0]) == 1)
		return (1);
	else if (data[0][0] == 'c' && ft_strlen(data[0]) == 1)
		return (2);
	else if (data[0][0] == 'l' && ft_strlen(data[0]) == 1)
		return (3);
	return (-1);
}

int			data_id(char **data)
{
	int		i;

	i = dat_id_helper(data);
	if (i != -1)
		return (i);
	else if (data[0][0] == 's' && data[0][1] == 'p' && ft_strlen(data[0]) == 2)
		return (4);
	else if (data[0][0] == 'p' && data[0][1] == 'l' && ft_strlen(data[0]) == 2)
		return (5);
	else if (data[0][0] == 's' && data[0][1] == 'q' && ft_strlen(data[0]) == 2)
		return (6);
	else if (data[0][0] == 'c' && data[0][1] == 'y' && ft_strlen(data[0]) == 2)
		return (7);
	else if (data[0][0] == 't' && data[0][1] == 'r' && ft_strlen(data[0]) == 2)
		return (8);
	return (-1);
}

void		data_insertion_objects(t_data *d, char **data, int i)
{
	if (i == 4)
		sp_insertion(d, data);
	else if (i == 5)
		pl_insertion(d, data);
	else if (i == 6)
		sq_insertion(d, data);
	else if (i == 7)
		cy_insertion(d, data);
	else if (i == 8)
		tr_insertion(d, data);
}

void		data_insertion(t_data *d, char **data)
{
	int i;

	i = data_id(data);
	if (i == -4)
		rotate(d, data);
	if (i == -3)
		translate(d, data);
	if (i == 0)
		r_insertion(d, data);
	else if (i == 1)
		a_insertion(d, data);
	else if (i == 2)
		c_insertion(d, data);
	else if (i == 3)
		l_insertion(d, data);
	else
		data_insertion_objects(d, data, i);
}
