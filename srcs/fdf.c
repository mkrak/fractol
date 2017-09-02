/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2017/09/01 16:00:19 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					main(int ac, char **av)
{
	t_coef	*scoef;
	int flag ;

	flag = 1;
	if (ac != 2)
	{
		ft_putendl("Usage : ../fractol <mandelbrot>");
		return (-1);
	}
	av = NULL;
	scoef = (t_coef*)malloc(sizeof(t_coef));

	init_struct(scoef);
	new_image(scoef);
	mlx_hook(scoef->win, 2, 3, ft_keyhook, scoef);
	mlx_mouse_hook(scoef->win, ft_mousehook, scoef);
	mandelbrot_init(scoef);
	mlx_loop(scoef->mlx);
	free(scoef);
	return (0);
}


void	mandelbrot_init(t_coef *e) // on définit la zone que l'on dessine.
{
	e->x1 = -2.1;
	e->y1 = -1.2;
	e->zoom = 100;
	e->imax = 100;
	e->imx = -50;
	e->imy = -150;
	mandelbrot_basic(e);
}

void	mandelbrot_basic(t_coef *e) // calcul de la taille de l'image.
{
	int x;
	int y;

	x = e->imx - 1;
	while (++x < VERTI + e->imx)
	{
		y = e->imy - 1;
		while (++y < HORI + e->imy)
		{
			e->cr = x / e->zoom + e->x1;
			e->ci = y / e->zoom + e->y1;
			e->zr = 0;
			e->zi = 0;
			mandelbrot(e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	mandelbrot(t_coef *e, int x, int y) // magie noir de l'algo de mandelbrot
{
	int i;

	i = -1;
	while (++i< e->imax && e->zr * e->zr + e->zi * e->zi < 4)
	{
		e->tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * e->zi * e->tmp + e->ci;
	}
	color(i, e);

	put_pixel(e, x - e->imx, y - e->imy, e->c);
}


void	color(int i, t_coef *e)
{
	int r;
	int g;
	int b;

	if (i == e->imax)
		e->c = 0x00000000;
	else
	{
		r = (i * 5) * 2;
		g = (255 - (i * 10)) * 2;
		b = (255 - (i * 2)) * 2;
		e->c = (r << 16) + (g << 8) + b;
	}
}