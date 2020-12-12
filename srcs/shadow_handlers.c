#include "minirt.h"

int			shadow_checker(t_p_shadow *t_shadow)
{
	double A;
	double B;
	t_vector v1;
	t_vector v2;

	A = length(substract(t_shadow->light_pos, t_shadow->new_start));
	B = length(substract(t_shadow->pos_hit, t_shadow->new_start));
	v1 = make_unit_vector(t_shadow->cam_dir);
	v2 = make_unit_vector(substract(t_shadow->pos_hit, t_shadow->light_pos));
	if (scalar(v1, v2) >= 0.01 && A >= B)
			return (1);
	return (0);
}

t_vector approCorrector(t_vector v)
{
	return (add(v, (t_vector){1e-4f,1e-4f,1e-4f}));
}

double		interShadowFuncs(t_p_shadow  *t_shadow, t_objects *p, t_objects *lights)
{
	double t;
	t_objects *l;
	t_ray r;

	t = -1;
	t_shadow->new_start = add(t_shadow->new_start, multiple(1e-4f, t_shadow->object_dir));
	r.a = approCorrector(t_shadow->new_start);
	l = lights;
	while (l != NULL)
	{
		t_shadow->light_pos = (*(t_light*)l->content).light_pos;
		r.b = make_unit_vector(approCorrector(\
			substract(t_shadow->light_pos, t_shadow->new_start)));
		if (p->id == 4)
			t = equation_sphere(r, p, &t_shadow->d_shadow);
		else if (p->id == 5)
			t = equation_plane(r, p, &t_shadow->d_shadow);
		else if (p->id == 6)
			t = equation_square(r, p, &t_shadow->d_shadow);
		else if (p->id == 7)
			t = equation_cylinder(r, p, &t_shadow->d_shadow).t;
		else if (p->id == 8)
			t = equation_triangle(r, p,&t_shadow->d_shadow);
		if (t > 0)
		{
			t_shadow->pos_hit = line_point(r, t);
			return (t);
		}
		l = l->next;
	}
	return (-1);
}

int shadow_handler(t_p_shadow *t_shadow, t_objects *lights, int color)
{
	t_vector shadowColor;
	t_objects *p;
	double	t;

	p = t_shadow->obj;
	while (p != NULL)
	{
		if (p != t_shadow->p)
		{
			t = interShadowFuncs(t_shadow, p, lights);
			if (t >= 0 && shadow_checker(t_shadow) == 1)
			{
				shadowColor = multiple(0.5, multiple((double)1 / 255, /* t_shadow->color_shadow */(t_vector){0, 0, 0}));
				return (rgb_maker(color_clamping(shadowColor)));
			}
		}
		p = p->next;
	}
	return (color);
}
