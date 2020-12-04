/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:40:16 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/04 14:45:03 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int sphere_handler(t_ray r, double *distance, double *t, t_p_shadow *t_shadow)
{
	t_vector new_start;
	t_vector N;

	r.id = 0;
    *t = equation_sphere(r, t_shadow->p, distance);
    if (*t > 0 && *t <= *distance)
    {
        t_shadow->new_start = line_point(r, *t);
        N = make_unit_vector(substract(t_shadow->new_start ,(*(t_sphere*)t_shadow->p->content).sphere_center));
		t_shadow->color_shadow = (*(t_sphere*)t_shadow->p->content).color_sphere;
		t_shadow->object_dir = N;
		r.color_obj = t_shadow->color_shadow;
		t_shadow->color = color_calculator(r, *t, t_shadow->lights, N);
    }
    return (t_shadow->color);
}

int plane_handler(t_ray r, double *distance, double *t, t_p_shadow *t_shadow)
{
    t_plane pl;

	r.id = 0;
    *t = equation_plane(r, t_shadow->p, distance);
    if (*t > 0 && *t >= *distance)
    {
		t_shadow->new_start = line_point(r, *t);
		pl = *(t_plane*)t_shadow->p->content;
		t_shadow->color_shadow = pl.color_plane;
		t_shadow->object_dir = pl.plane_norm;
    	if (scalar(r.b, pl.plane_norm) > 0)
			pl.plane_norm = multiple(-1, pl.plane_norm);
		r.color_obj = t_shadow->color_shadow;
		t_shadow->color = color_calculator(r, *t, t_shadow->lights, pl.plane_norm);
	}
	return (t_shadow->color);
}

int square_handler(t_ray r, double *distance, double *t, t_p_shadow *t_shadow)
{
    t_square sq;

	r.id = 0;
    *t = equation_square(r, t_shadow->p, distance);
	if (*t >= 0 && *t >= *distance)
	{
		t_shadow->new_start = line_point(r, *t);
		sq = *((t_square*)t_shadow->p->content);
		t_shadow->color_shadow = sq.color_square;
		t_shadow->object_dir = sq.square_norm;
		if (scalar(r.b, sq.square_norm) > 0)
			sq.square_norm = multiple(-1, sq.square_norm);
		r.color_obj = t_shadow->color_shadow;
		t_shadow->color = color_calculator(r, *t, t_shadow->lights, sq.square_norm);
	}
    return (t_shadow->color);
}

int cylinder_handler(t_ray r, double *distance, double *t, t_p_shadow *t_shadow)
{
    t_cylinder cy;
	t_passage_cy pass;

	r.id = 0;
    pass = equation_cylinder(r, t_shadow->p, distance);
	*t = pass.t;
	if (*t >= 0 && *t >= *distance)
	{
		t_shadow->new_start = line_point(r, *t);
		cy = *((t_cylinder*)t_shadow->p->content);
		t_shadow->color_shadow = cy.cylinder_color;
		t_shadow->object_dir = cy.cylinder_norm;
		r.color_obj = t_shadow->color_shadow;
		t_shadow->color = color_calculator(r, *t, t_shadow->lights, pass.n);
	}
    return (t_shadow->color);
}

int triangle_handler(t_ray r, double *distance, double *t, t_p_shadow *t_shadow)
{
    t_triangle tr;
	t_vector V1;
	t_vector V2;
	t_vector V;

	r.id = 0;
    *t = equation_triangle(r, t_shadow->p, distance);
    if (*t > 0)
    {
		t_shadow->new_start = line_point(r, *t);
		tr = *(t_triangle*)t_shadow->p->content;
		t_shadow->color_shadow = tr.triangle_color;
		V1 = substract(tr.second_point, tr.first_point);
		V2 = substract(tr.third_point, tr.first_point);
		V = make_unit_vector(v_product(V1, V2));
		if (scalar(r.b, V) > 0)
			V = multiple(-1, V);
		t_shadow->object_dir = V;
		r.color_obj = t_shadow->color_shadow;
		t_shadow->color = color_calculator(r, *t, t_shadow->lights, V);
	}
	return (t_shadow->color);
}