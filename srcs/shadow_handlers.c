#include "minirt.h"

int			shadow_cheker(t_vector a, t_vector b, t_vector c)
{
	double A;
	double B;


	A = length(substract(b, a));
	B = length(substract(c, a));
	return (A >= B);
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
			if (t >= 0 && shadow_cheker(t_shadow->new_start, t_shadow->light_pos, t_shadow->pos_hit))
			{
				shadowColor = multiple(0.5, multiple((double)1 / 255, t_shadow->color_shadow));
				return (rgb_maker(color_clamping(shadowColor)));
			}
		}
		p = p->next;
	}
	return (color);
}