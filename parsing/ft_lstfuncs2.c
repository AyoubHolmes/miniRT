/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfuncs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:37:14 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/11/26 20:37:27 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camlist		*get_cam_previous(t_camlist **alst)
{
	t_camlist	*p;

	if (*alst == NULL)
		return (0);
	p = *alst;
	*alst = p->prev;
	return (*alst);
}

t_camlist		*get_cam_next(t_camlist **alst)
{
	t_camlist	*p;

	if (*alst == NULL)
		return (0);
	p = *alst;
	*alst = p->next;
	return (*alst);
}
