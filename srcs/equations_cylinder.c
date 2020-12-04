/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:28:59 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/01 14:12:17 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void					eq_init(double *eq, \
						t_ray r, t_cylinder *cy, t_vector oc)
{
	eq[4] = (-eq[1] - sqrt(eq[3])) / (2 * eq[0]);
	eq[5] = (-eq[1] + sqrt(eq[3])) / (2 * eq[0]);
	eq[6] = scalar(r.b, cy->cylinder_norm) * eq[4] \
			+ scalar(oc, cy->cylinder_norm);
	eq[7] = scalar(r.b, cy->cylinder_norm) * eq[5] + \
			scalar(oc, cy->cylinder_norm);
}

t_passage_cy			cy_helper(double *eq, t_ray r, \
						t_cylinder *cy, t_passage_cy pass)
{
	t_vector			oc;

	oc = substract(r.a, cy->cylinder_center);
	eq_init(eq, r, cy, oc);
	if (eq[6] >= 0 && eq[6] <= (double)(cy->cylinder_height))
	{
		eq[5] = eq[4];
		eq[7] = eq[6];
	}
	if (eq[5] > 0 && (eq[7] >= 0 && eq[7] <= (double)(cy->cylinder_height)))
	{
		if (eq[5] <= pass.distance && eq[5] >= 0)
		{
			pass.t = eq[5];
			if (r.id == 0)
				pass.distance = eq[5];
			pass.n = substract(substract(line_point(r, eq[5]),
			cy->cylinder_center), multiple(eq[7], cy->cylinder_norm));
			pass.n = make_unit_vector(pass.n);
		}
	}
	return (pass);
}

t_passage_cy			equation_cylinder(t_ray r, t_objects *obj, \
					double *distance)
{
	t_cylinder			*cy;
	t_vector			oc;
	double				*eq;
	t_passage_cy		pass;

	pass.t = -1;
	pass.distance = *distance;
	cy = ((t_cylinder*)obj->content);
	cy->cylinder_norm = make_unit_vector(cy->cylinder_norm);
	oc = substract(r.a, cy->cylinder_center);
	eq = (double *)malloc(sizeof(double) * 8);
	eq[0] = scalar(r.b, r.b) - (double)(scalar(r.b, cy->cylinder_norm) \
		* scalar(r.b, cy->cylinder_norm));
	eq[1] = 2 * (scalar(r.b, oc) - (scalar(r.b, cy->cylinder_norm) \
		* scalar(oc, cy->cylinder_norm)));
	eq[2] = scalar(oc, oc) - (scalar(oc, cy->cylinder_norm) \
		* scalar(oc, cy->cylinder_norm)) \
		- ((double)(cy->cylinder_diametre / 2) * \
		(double)(cy->cylinder_diametre / 2));
	eq[3] = (eq[1] * eq[1]) - 4 * (eq[0] * eq[2]);
	if (eq[3] > 0)
		pass = cy_helper(eq, r, cy, pass);
	*distance = pass.distance;
	free(eq);
	return (pass);
}
