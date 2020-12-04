/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:17:59 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/01 14:21:56 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		initialize_vector(double x, double y, double z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector		v_product(t_vector v1, t_vector v2)
{
	t_vector	v3;

	v3.x = v1.y * v2.z - v1.z * v2.y;
	v3.y = v1.z * v2.x - v1.x * v2.z;
	v3.z = v1.x * v2.y - v1.y * v2.x;
	return (v3);
}

double			squared_length(t_vector v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double			length(t_vector v)
{
	return (sqrt(squared_length(v)));
}

t_vector		make_unit_vector(t_vector v)
{
	return (multiple(1 / length(v), v));
}
