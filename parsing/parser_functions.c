/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:28:46 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/23 11:40:40 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			r_insertion(t_data *d, char **data)
{
	d->r.x = atoi(data[1]);
	d->r.y = atoi(data[2]);
	d->r.done = 1;
}

void			a_insertion(t_data *d, char **data)
{
	char		**ambient_color;

	d->a.perc = ft_atof(data[1]);
	ambient_color = ft_split(data[2], ',');
	d->a.t_ambient_color = (t_vector){ ft_atof(ambient_color[0])\
		, ft_atof(ambient_color[1]), ft_atof(ambient_color[2]) };
}

void			c_insertion(t_data *d, char **data)
{
	char		**view_point;
	char		**cam_normal;
	t_objects	*p;

	view_point = ft_split(data[1], ',');
	cam_normal = ft_split(data[2], ',');
	if (!d->obj)
	{
		if (!(d->obj = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		d->obj = cam_initializer(view_point, cam_normal, data[3]);
		d->last_obj = d->obj;
	}
	else
	{
		p = d->obj;
		while (p->next != NULL)
			p = p->next;
		if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		p->next = cam_initializer(view_point, cam_normal, data[3]);
		d->last_obj = p->next;
	}
}

void			l_insertion(t_data *d, char **data)
{
	char		**light_vecs[2];
	t_objects	*p;

	light_vecs[0] = ft_split(data[1], ',');
	light_vecs[1] = ft_split(data[3], ',');
	if (!d->obj)
	{
		if (!(d->obj = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		d->obj = ligth_initializer(light_vecs[0], light_vecs[1], data[2]);
		d->last_obj = d->obj;
	}
	else
	{
		p = d->obj;
		while (p->next != NULL)
			p = p->next;
		if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		p->next = ligth_initializer(light_vecs[0], light_vecs[1], data[2]);
		d->last_obj = p->next;
	}
}

void			sp_insertion(t_data *d, char **data)
{
	char		**sphere_center;
	char		**color_sphere;
	t_objects	*p;

	sphere_center = ft_split(data[1], ',');
	color_sphere = ft_split(data[3], ',');
	if (!d->obj)
	{
		if (!(d->obj = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		d->obj = sphere_initialize(sphere_center, color_sphere, data[2]);
		d->last_obj = d->obj;
	}
	else
	{
		p = d->obj;
		while (p->next != NULL)
			p = p->next;
		if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		p->next = sphere_initialize(sphere_center, color_sphere, data[2]);
		d->last_obj = p->next;
	}
}
