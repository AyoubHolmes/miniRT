/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 09:36:18 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/11/27 09:36:35 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			pl_insertion(t_data *d, char **data)
{
	char		**plane_center;
	char		**plane_norm;
	char		**color_plane;
	t_objects	*p;

	plane_center = ft_split(data[1], ',');
	plane_norm = ft_split(data[2], ',');
	color_plane = ft_split(data[3], ',');
	if (!d->obj)
	{
		if (!(d->obj = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		d->obj = plane_initialize(plane_center, plane_norm, color_plane);
		d->last_obj = d->obj;
	}
	else
	{
		p = d->obj;
		while (p->next != NULL)
			p = p->next;
		if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		p->next = plane_initialize(plane_center, plane_norm, color_plane);
		d->last_obj = p->next;
	}
}

void			sq_insertion(t_data *d, char **data)
{
	char		**sq_c;
	char		**square_norm;
	char		**color_square;
	t_objects	*p;

	sq_c = ft_split(data[1], ',');
	square_norm = ft_split(data[2], ',');
	color_square = ft_split(data[4], ',');
	if (!d->obj)
	{
		if (!(d->obj = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		d->obj = square_initialize(sq_c, square_norm, color_square, data[3]);
		d->last_obj = d->obj;
	}
	else
	{
		p = d->obj;
		while (p->next != NULL)
			p = p->next;
		if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		p->next = square_initialize(sq_c, square_norm, color_square, data[3]);
		d->last_obj = p->next;
	}
}

void			cy_insertion(t_data *d, char **data)
{
	t_cy_init	cy_init;
	t_objects	*p;

	cy_init.cylinder_center = ft_split(data[1], ',');
	cy_init.cylinder_norm = ft_split(data[2], ',');
	cy_init.cylinder_diametre = data[4];
	cy_init.cylinder_height = data[5];
	cy_init.color_cylinder = ft_split(data[3], ',');
	if (!d->obj)
	{
		if (!(d->obj = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		d->obj = cylinder_initialize(cy_init);
		d->last_obj = d->obj;
	}
	else
	{
		p = d->obj;
		while (p->next != NULL)
			p = p->next;
		if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		p->next = cylinder_initialize(cy_init);
		d->last_obj = p->next;
	}
}

void			tr_insertion(t_data *d, char **data)
{
	char		**tr_v[4];
	t_objects	*p;

	tr_v[0] = ft_split(data[1], ',');
	tr_v[1] = ft_split(data[2], ',');
	tr_v[2] = ft_split(data[3], ',');
	tr_v[3] = ft_split(data[4], ',');
	if (!d->obj)
	{
		if (!(d->obj = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		d->obj = triangle_initialize(tr_v[0], tr_v[1], tr_v[2], tr_v[3]);
		d->last_obj = d->obj;
	}
	else
	{
		p = d->obj;
		while (p->next != NULL)
			p = p->next;
		if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		p->next = triangle_initialize(tr_v[0], tr_v[1], tr_v[2], tr_v[3]);
		d->last_obj = p->next;
	}
}
