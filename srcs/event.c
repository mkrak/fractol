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

void		ft_zoom(t_coef *e, int x, int y)
{
		e->imx += x / 5;
		e->imy += y / 5;
		e->zoom *= 1.2;
		e->imx *= 1.2;
		e->imy *= 1.2;
}

void		ft_dezoom(t_coef *e, int x, int y)
{
		e->imx -= x / 5;
		e->imy -= y / 5;
		e->zoom /= 1.2;
		e->imx /= 1.2;
		e->imy /= 1.2;
}

int					ft_mousehook(int key, int x, int y, t_coef *e)
{
	 if (key == 1 || key == 4)
	 	ft_zoom(e, x, y);
	 else if (key == 2 || key == 5)
	 	ft_dezoom(e, x, y);
	else
		return (0);
	mlx_destroy_image(e->mlx, e->img);
	new_image(e);
	ft_fractal(e);
	return (0);
}

int 	fluide(int x, int y, t_coef *f)
{
	if (f->stop == 0)
	{
			f->paramx = x / 2 + 40;
			f->paramy = y / 2 + 40;
	}
	mlx_destroy_image(f->mlx, f->img);
	new_image(f);
	ft_fractal(f);
	return (0);
}

int			ft_keyhook(int key, t_coef *e)
{
	if (key == 65307)
		exit(EXIT_SUCCESS);
	else if (key == 65451)
		e->imax += 10;
	else if (key == 65453)
		e->imax -= 10;
	else if (key == 65361)
		e->imx -= 20;
	else if (key == 65363)
		e->imx += 20;
	else if (key == 65362)
		e->imy -= 20;
	else if (key == 65364)
		e->imy += 20;
	else if (key == 99)
		e->col -= 7;
	else if (key == 118)
		e->col += 7;
	else if (key == 112)
	{
		if (e->stop == 1)
			e->stop = 0;
		else if (e->stop == 0)
			e->stop = 1;
	}
	else if (key == 114)
		init_fract(e);
	else
		return (0);
	mlx_destroy_image(e->mlx, e->img);
	new_image(e);
	ft_fractal(e);
	return (0);
}

/*
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
		e->col -= 7;
	else if (key == 9)
		e->col += 7;
	//else if (key != 53)
	//	printf("key = %d\n", key);
	else if (key == 15)
		mandelbrot_init(e);
	else
		return (0);
	mlx_destroy_image(e->mlx, e->img);
	new_image(e);
	ft_fractal(e);
	return (0);
}
*/
