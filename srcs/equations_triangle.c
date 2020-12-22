/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:38:40 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/22 17:53:35 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			t_calculator(double t, double *distance, double epsilon, int id)
{
	if (t <= *distance && t > epsilon)
	{
		if (id == 0)
			*distance = t;
		return (t);
	}
	return (-1);
}

double			equation_triangle(t_ray r, t_objects *obj, double *distance)
{
	double		epsilon;
	t_triangle	*tr;
	t_vector	vecs[5];
	double		vars[4];

	epsilon = 0.0000001;
	tr = ((t_triangle*)obj->content);
	vecs[0] = substract(tr->second_point, tr->first_point);
	vecs[1] = substract(tr->third_point, tr->first_point);
	vecs[2] = v_product(r.b, vecs[1]);
	vars[0] = scalar(vecs[0], vecs[2]);
	if (vars[0] > -epsilon && vars[0] < epsilon)
		return (-1);
	vecs[3] = substract(r.a, tr->first_point);
	vars[1] = (double)(1.0 / vars[0]) * scalar(vecs[3], vecs[2]);
	if (vars[1] < 0.0 || vars[1] > 1.0)
		return (-1);
	vecs[4] = v_product(vecs[3], vecs[0]);
	vars[2] = (double)(1.0 / vars[0]) * scalar(r.b, vecs[4]);
	if (vars[2] < 0.0 || vars[1] + vars[2] > 1.0)
		return (-1);
	vars[3] = (double)(1.0 / vars[0]) * scalar(vecs[1], vecs[4]);
	return (t_calculator(vars[3], distance, epsilon, r.id));
}
