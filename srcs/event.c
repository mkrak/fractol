/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:02:30 by mkrakows          #+#    #+#             */
/*   Updated: 2017/09/07 17:04:47 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					ft_mousehook(int key, int x, int y, t_coef *e)
{
	if (key == 1 || key == 4)
		ft_zoom(e, x, y);
	else if (key == 2 || key == 5)
		ft_dezoom(e, x, y);
	else
		return (0);
	ft_fractal(e);
	return (0);
}

int					fluide(int x, int y, t_coef *f)
{
	if (f->stop == 0 && f->av == 3)
	{
		f->paramx = x / 2 + 40;
		f->paramy = y / 2 + 40;
	}
	ft_fractal(f);
	return (0);
}

int					ft_keyhook(int key, t_coef *e)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 69)
		e->imax += 10;
	else if (key == 78)
		e->imax -= 10;
	else if (key == 124)
		e->imx -= 20;
	else if (key == 123)
		e->imx += 20;
	else if (key == 125)
		e->imy -= 20;
	else if (key == 126)
		e->imy += 20;
	else if (key == 8)
		e->col -= 4;
	else if (key == 9)
		e->col += 4;
	else if (key == 15)
		e->r += 10;
	else if (key == 5)
		e->g -= 10;
	else if (key == 11)
		e->b += 10;
	else if (key == 17)
		e->t += 10;
	else if (key == 46)
	{
		if (e->m == 1)
			e->m = 0;
		else if (e->m == 0)
			e->m = 1;
	}	
	else if (key == 35)
	{
		if (e->stop == 1)
			e->stop = 0;
		else if (e->stop == 0)
			e->stop = 1;
	}
	else if (key == 83)
	{
		e->av = 1;
		init_fract(e);
	}
	else if(key == 84)
	{
		e->av = 2;
		init_fract(e);
	}
	else if(key == 85)
	{
		e->av = 3;
		init_fract(e);
	}
	else
		return (0);
	ft_fractal(e);
	return (0);
}
