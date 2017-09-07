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

void	init_fract(t_coef *e)
{
	e->zoom = 100;
	e->imax = 100;
	e->imx = -200;
	e->imy = -250;
	e->paramx = 300;
	e->paramy = 300;
	e->jul = 1;
	e->stop = 0;
	ft_fractal(e);
}

void	def_mand_burn(t_coef *e, int x, int y)
{
	e->cr = x / e->zoom;
	e->ci = y / e->zoom;
	e->zr = 0;
	e->zi = 0;
}

void	def_jul(t_coef *e, int x, int y)
{
	e->cr = 0.285;
	e->ci = 0.01;
	e->zr = x / e->zoom;
	e->zi = y / e->zoom;
}
