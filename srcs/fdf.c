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

int		main(int ac, char **av)
{
	t_coef	*scoef;
	
	if (ac != 2 || ((ft_strcmp(av[1], "mandelbrot") != 0) && (ft_strcmp(av[1], "burningship") != 0) && (ft_strcmp(av[1], "julia") != 0)))
	{
		ft_putendl("Usage : ../fractol [mandelbrot/burningship/julia]");
		return (-1);
	}
	scoef = (t_coef*)malloc(sizeof(t_coef));
	scoef->av = stock_av(av[1]);
	init_struct(scoef);
	new_image(scoef);
	mlx_hook(scoef->win, 2, 3, ft_keyhook, scoef);
	mlx_hook(scoef->win, MOTION_NOTIFY, PTR_MOTION_MASK, fluide,  scoef);
	mlx_mouse_hook(scoef->win, ft_mousehook, scoef);
	if (scoef->av == 1 || scoef->av == 2)
		mandelbrot_init(scoef);
	else
		julia_init(scoef);
	mlx_loop(scoef->mlx);
	free(scoef);
	return (0);
}

int 	fluide(int x, int y, t_coef *f)
{
	f->paramx = x;
	f->paramy = y;

	mlx_destroy_image(f->mlx, f->img);
	new_image(f);
	ft_fractal(f);
	return (0);



}

int		stock_av(char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0) 
		return (1);
	else if (ft_strcmp(av, "burningship") == 0)
		return (2);
	else 
		return (3);
}

void	mandelbrot_init(t_coef *e)
{
	e->x1 = -2.1;
	e->y1 = -1.2;
	e->zoom = 100;
	e->imax = 100;
	e->imx = -50;
	e->imy = -150;
	ft_fractal(e);
}


void	julia_init(t_coef *e)
{
	e->x1 = -1;
	e->y1 = -1.2;
	e->zoom = 100;
	e->imax = 100;
	e->imx = -50;
	e->imy = -150;
	e->paramx = VERTI / 2;
	e->paramy = HORI / 2;
	e->jul = 1;
	e->stop = 0;
	ft_fractal(e);
}

void	def_mand_burn(t_coef *e, int x, int y)
{
	e->cr = x / e->zoom + e->x1;
	e->ci = y / e->zoom + e->y1;
	e->zr = 0;
	e->zi = 0;
}

void	def_jul(t_coef *e, int x, int y)
{
	e->cr = 0.285;
	e->ci = 0.01;
	e->zr = x / e->zoom + e->x1;
	e->zi = y / e->zoom + e->y1;
}

void	ft_fractal(t_coef *e)
{
	int x;
	int y;

	x = e->imx - 1;
	while (++x < VERTI + e->imx)
	{
		y = e->imy - 1;
		while (++y < HORI + e->imy)
		{
			if (e->av == 1 || e->av == 2)
				def_mand_burn(e, x, y);
			else
				def_jul(e, x, y);
			if (e->av == 1)
				mandelbrot(e, x, y);
			else if (e->av == 2)
				burningship(e, x, y);
			else
				julia(e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	julia(t_coef *e, int x, int y)
{
	int		i;

	i = -1;
	while (++i < e->imax && e->zr * e->zr + e->zi * e->zi < 4)
	{
		e->tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi - 0.8 + (0.6 / ((double)e->paramx / (double)VERTI));
		e->zi = 2 * e->zi * e->tmp + 0.27015 / ((double)e->paramy / (double)VERTI);
	}
	color(i, e);
	put_pixel(e, x - e->imx, y - e->imy, e->c);
}

void	mandelbrot(t_coef *e, int x, int y)
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

void	burningship(t_coef *e, int x, int y)
{
	int i;

	i = -1;
	while (++i< e->imax && e->zr * e->zr + e->zi * e->zi < 4)
	{
		e->tmp = e->zr;
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = 2 * fabsl(e->zi * e->tmp) + e->ci;
	}
	color(i, e);
	put_pixel(e, x - e->imx, y - e->imy, e->c);
}
