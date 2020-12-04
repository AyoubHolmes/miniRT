/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_checker_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:14:05 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/11/26 18:50:28 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			data_checker_helper1(char *line, int i)
{
	if (i == -4)
		return (1);
	if (i == -3)
		return (1);
	if (i == -2)
		return (1);
	if (i == 0)
		return (r_checker(line));
	else if (i == 1)
		return (a_checker(line));
	else if (i == 2)
		return (c_checker(line));
	else if (i == 3)
		return (l_checker(line));
	return (-1);
}

int			data_checker_helper2(char *line, int i)
{
	if (i == 4)
		return (sp_checker(line));
	else if (i == 5)
		return (pl_checker(line));
	else if (i == 6)
		return (sq_checker(line));
	else if (i == 7)
		return (cy_checker(line));
	else if (i == 8)
		return (tr_checker(line));
	return (-1);
}

int			data_checker(char *line)
{
	int		i;
	char	**data;

	data = ft_split_whitespaces(line);
	i = data_id(data);
	if (i <= 3)
		return (data_checker_helper1(line, i));
	else
		return (data_checker_helper2(line, i));
	return (-1);
}
