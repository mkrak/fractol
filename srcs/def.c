/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:02:30 by mkrakows          #+#    #+#             */
/*   Updated: 2017/04/13 21:47:35 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				init_fract(t_coef *e)
{
	e->zoom = 100;
	e->imax = 50;
	e->imx = -300;
	e->imy = -300;
	e->paramx = 300;
	e->paramy = 300;
	e->stop = 0;
	e->col = 0;
	e->r = 0;
	e->g = 0;
	e->b = 0;
	e->t = 0;
	e->d = 0;
	if (e->av == 7)
		e->r = 40;
	ft_fractal(e);
}

void				def_mand_burn(t_coef *e, int x, int y)
{
	e->cr = x / e->zoom;
	e->ci = y / e->zoom;
	e->zr = 0;
	e->zi = 0;
}

void				def_jul(t_coef *e, int x, int y)
{
	e->zr = x / e->zoom;
	e->zi = y / e->zoom;
}

void				ft_zoom(t_coef *e, int x, int y)
{
	e->imx += x / 5;
	e->imy += y / 5;
	e->zoom *= 1.2;
	e->imx *= 1.2;
	e->imy *= 1.2;
}

void				ft_dezoom(t_coef *e, int x, int y)
{
	e->imx -= x / 5;
	e->imy -= y / 5;
	e->zoom /= 1.2;
	e->imx /= 1.2;
	e->imy /= 1.2;
}
