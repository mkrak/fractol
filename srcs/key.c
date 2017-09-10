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

int					stock_av(char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(av, "burningship") == 0)
		return (2);
	else
		return (3);
}

void				ft_keyhook4(int key, t_coef *e)
{
	if (key == 69)
		e->imax += 10;
	else if (key == 78)
		e->imax -= 10;
	else if (key == 124)
		e->imx -= 20;
	else if (key == 123)
		e->imx += 20;
	else if (key == 125)
		e->imy -= 20;
	else if (key == 5)
		e->g -= 10;
	else if (key == 11)
		e->b += 10;
	else if (key == 126)
		e->imy += 20;
	else
		e->col -= 4;
}

void				ft_keyhook1(int key, t_coef *e)
{
	if (key == 9)
		e->col += 4;
	else if (key == 15)
		e->r += 10;
	else if (key == 17)
	{
		if (e->t != 400)
			e->t = 400;
		else
			e->t = 0;
	}
	else if (key == 46)
	{
		if (e->m == 1)
			e->m = 0;
		else if (e->m == 0)
			e->m = 1;
	}
	else
	{
		if (e->stop == 1)
			e->stop = 0;
		else if (e->stop == 0)
			e->stop = 1;
	}
}

void				ft_keyhook2(int key, t_coef *e)
{
	if (key == 82)
	{
		e->av = 10;
		init_fract(e);
	}
	else if (key == 83)
	{
		e->av = 1;
		init_fract(e);
	}
	else if (key == 84)
	{
		e->av = 2;
		init_fract(e);
	}
	else if (key == 85)
	{
		e->av = 3;
		init_fract(e);
	}
	else
	{
		e->av = 4;
		init_fract(e);
	}
}

void				ft_keyhook3(int key, t_coef *e)
{
	if (key == 87)
	{
		e->av = 5;
		init_fract(e);
	}
	else if (key == 88)
	{
		e->av = 6;
		init_fract(e);
	}
	else if (key == 89)
	{
		e->av = 7;
		init_fract(e);
	}
	else if (key == 91)
	{
		e->av = 8;
		init_fract(e);
	}
	else
	{
		e->av = 9;
		init_fract(e);
	}
}
