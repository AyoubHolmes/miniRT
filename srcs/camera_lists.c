/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:44:51 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/11/26 19:18:27 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			getcamhelper(t_data d, t_objects **obj, t_camlist **liste)
{
	*obj = d.obj;
	while (obj != NULL)
	{
		if ((*obj)->id == 2)
			break ;
		(*obj) = (*obj)->next;
	}
	(*liste) = ft_double_lst_cam_new(*(t_cam_data*)(*obj)->content);
	(*obj) = (*obj)->next;
}

t_camlist		*getcams(t_data d)
{
	t_objects	*obj;
	t_camlist	*liste;
	t_camlist	*q;

	if (!(liste = (t_camlist*)malloc(sizeof(t_camlist))))
		return (0);
	getcamhelper(d, &obj, &liste);
	while (obj != NULL)
	{
		if (obj->id == 2)
		{
			q = ft_double_lst_cam_new(*(t_cam_data*)obj->content);
			fcam_add(&liste, q);
		}
		obj = obj->next;
	}
	q = fcam_last(&liste);
	q->next = liste;
	liste->prev = q;
	return (liste);
}
