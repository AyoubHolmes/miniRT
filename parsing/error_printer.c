/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:02:56 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/23 11:15:11 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_err					file_extension_checker(char *str)
{
	t_err				err;
	int					i;
	char				**tab;
	char				*name;

	err.is_checked = -22;
	i = ft_nbr_words(str, '/');
	if (i > 1)
	{
		tab = ft_split(str, '/');
		name = tab[i - 1];
		free(tab);
	}
	else
		name = str;
	i = ft_nbr_words(name, '.');
	if (i == 2)
	{
		tab  = ft_split(name, '.');
		if (ft_strncmp(tab[1], "rt", 2) == 0 && ft_strlen(tab[1]) == 2)
			err.is_checked = 1;

	}
	return (err);
}

void					error_printer_helper1(int id)
{
	if (id == -1)
		ft_putstr_fd("not a data type \n", 2);
	else if (id == -2)
		ft_putstr_fd("Resolution has wrong number of values \n", 2);
	else if (id == -3)
		ft_putstr_fd("Resolution has a wrong entry \n", 2);
	else if (id == -4)
		ft_putstr_fd("Ambient has wrong number of values \n", 2);
	else if (id == -5)
		ft_putstr_fd("Ambient has a wrong entry \n", 2);
	else if (id == -6)
		ft_putstr_fd("Camera has wrong number of values \n", 2);
	else if (id == -7)
		ft_putstr_fd("Camera has a wrong entry \n", 2);
	else if (id == -8)
		ft_putstr_fd("Light has wrong number of values \n", 2);
	else if (id == -9)
		ft_putstr_fd("Light has a wrong entry \n", 2);
	else if (id == -10)
		ft_putstr_fd("Sphere has wrong number of values \n", 2);
	else if (id == -11)
		ft_putstr_fd("Sphere has a wrong entry \n", 2);
}

void					error_printer_helper2(int id)
{
	if (id == -12)
		ft_putstr_fd("Plane has wrong number of values\n", 2);
	else if (id == -13)
		ft_putstr_fd("Plane has a wrong entry\n", 2);
	else if (id == -14)
		ft_putstr_fd("Square has wrong number of values\n", 2);
	else if (id == -15)
		ft_putstr_fd("Square has a wrong entry\n", 2);
	else if (id == -16)
		ft_putstr_fd("Cylinder has wrong number of values\n", 2);
	else if (id == -17)
		ft_putstr_fd("Cylinder has a wrong entry\n", 2);
	else if (id == -18)
		ft_putstr_fd("Triangle has wrong number of values\n", 2);
	else if (id == -19)
		ft_putstr_fd("Triangle has a wrong entry\n", 2);
	else if (id == -20)
		ft_putstr_fd("File doesnt exist\n", 2);
	else if (id == -21)
		ft_putstr_fd("Wrong Inputs\n", 2);
	else if (id == -22)
		ft_putstr_fd("Wrong Extension\n", 2);
	else if (id == -23)
		ft_putstr_fd("Double Resolution\n", 2);
	else if (id == -24)
		ft_putstr_fd("Double Ambient\n", 2);
	else if (id == -25)
		ft_putstr_fd("No Camera\n", 2);
	else if (id == -26)
		ft_putstr_fd("No Resolution\n", 2);
	else if (id == -27)
		ft_putstr_fd("No Ambient\n", 2);
}

void					error_printer(t_err err)
{
	ft_putstr_fd("ERROR\n", 2);
	if (err.is_checked >= -11)
		error_printer_helper1(err.is_checked);
	else
		error_printer_helper2(err.is_checked);
	if (err.line > 0)
	{
		ft_putstr_fd(" at line: ", 2);
		ft_putnbr_fd(err.line, 2);
	}
	exit(1);
}
