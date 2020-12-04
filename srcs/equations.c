/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:30:08 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/11/30 10:21:32 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			distance_exist(t_ray r, double *distance, double t)
{
	*distance = t;
	return (t);
}

double			equation_sphere(t_ray r, t_objects *obj, double *distance)
{
	t_sphere	*sp;
	t_vector	oc;
	double		eq[4];
	double		t;

	sp = ((t_sphere*)obj->content);
	oc = substract(r.a, sp->sphere_center);
	eq[0] = scalar(r.b, r.b);
	eq[1] = 2.0 * scalar(oc, r.b);
	eq[2] = scalar(oc, oc) - ((double)(sp->sphere_diametre / 2)\
			* (double)(sp->sphere_diametre / 2));
	eq[3] = (eq[1] * eq[1]) - (4 * eq[0] * eq[2]);
	if (eq[3] < 0)
		return (-1.0);
	else
	{
		t = (-eq[1] - sqrt(eq[3])) / (2.0 * eq[0]);
		if (t <= *distance && t >= 0)
			return (distance_exist(r, distance, t));
		return (-1);
	}
}

double			equation_plane(t_ray r, t_objects *obj, double *distance)
{
	t_plane		*pl;
	t_vector	oc;
	double		e[2];
	double		t;

	pl = ((t_plane*)obj->content);
	oc = substract(r.a, pl->plane_center);
	pl->plane_norm = make_unit_vector(pl->plane_norm);
	e[0] = scalar(r.b, pl->plane_norm);
	e[1] = scalar(oc, pl->plane_norm);
	if (e[0] != 0)
	{
		t = -e[1] / e[0];
		if (t <= *distance && t >= 0)
			return (distance_exist(r, distance, t));
	}
	return (-1);
}

double			equation_square(t_ray r, t_objects *obj, double *distance)
{
	t_square	*sq;
	t_vector	oc;
	double		e[2];
	double		t;

	sq = ((t_square*)obj->content);
	oc = substract(r.a, sq->square_center);
	e[0] = scalar(r.b, make_unit_vector(sq->square_norm));
	e[1] = scalar(oc, make_unit_vector(sq->square_norm));
	if (fabs(e[0]) > 0)
	{
		t = -e[1] / e[0];
		oc = substract(sq->square_center, line_point(r, t));
		if (fabs(oc.x) <= (double)(sq->size / 2) \
			&& fabs(oc.y) <= (double)(sq->size / 2) \
			&& fabs(oc.z) <= (double)(sq->size / 2) && t <= *distance && t > 0)
			return (distance_exist(r, distance, t));
	}
	return (-1);
}
