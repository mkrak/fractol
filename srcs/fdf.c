/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:31:47 by mkrakows          #+#    #+#             */
/*   Updated: 2017/09/07 17:14:07 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_coef	*scoef;

	if (ac != 2 || ((ft_strcmp(av[1], "mandelbrot") != 0) &&
	(ft_strcmp(av[1], "burningship") != 0) && (ft_strcmp(av[1], "julia") != 0)))
	{
		ft_putendl("Usage : ../fractol [mandelbrot/burningship/julia]");
		return (-1);
	}
	scoef = (t_coef*)malloc(sizeof(t_coef));
	scoef->av = stock_av(av[1]);
	init_struct(scoef);
	new_image(scoef);
	mlx_hook(scoef->win, 2, 3, ft_keyhook, scoef);
	if (scoef->av == 3 || scoef->av == 4)
		mlx_hook(scoef->win, MOTION_NOTIFY, PTR_MOTION_MASK, fluide, scoef);
	mlx_mouse_hook(scoef->win, ft_mousehook, scoef);
	init_fract(scoef);
	mlx_loop(scoef->mlx);
	return (0);
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
			if (e->av == 1 || e->av == 2 || e->av == 10)
				def_mand_burn(e, x, y);
			else
				def_jul(e, x, y);
			magie(e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 10, 0x000000,
			"Menu  :  Press M");
	if (e->m == 1)
		menu(e);
}

void	magie(t_coef *e, int x, int y)
{
	int i;

	i = -1;
	while (++i < e->imax && e->zr * e->zr + e->zi * e->zi < 4)
	{
		e->tmp = e->zr;
		if (e->av == 3)
		{
			e->zr = e->zr * e->zr - e->zi * e->zi - 0.8 +
			(0.6 / (e->paramx / VERTI));
			e->zi = 2 * e->zi * e->tmp + 0.27015 / (e->paramy / VERTI);
		}
		else if (e->av == 1 || e->av == 2)
		{
			e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
			if (e->av == 1)
				e->zi = 2 * e->zi * e->tmp + e->ci;
			else
				e->zi = 2 * fabsl(e->zi * e->tmp) + e->ci;
		}
		else
			magie_bonus(e);
	}
	color(i, e);
	put_pixel(e, x - e->imx, y - e->imy, e->c);
}

void	magie_bonus(t_coef *e)
{
	if (e->av == 4)
	{
		e->zr = e->zr * e->zr - e->zi * e->zi - 0.8 +
		(0.6 / (e->paramx / VERTI));
		e->zi = -2 * e->zi * e->tmp + 0.27015 / (e->paramy / VERTI);
	}
	else if (e->av == 5)
	{
		e->zr = e->zr * e->zr - e->zi * e->zi - 1.417022285618;
		e->zi = 2 * e->zi * e->tmp;
	}
	else if (e->av == 6)
	{
		e->zr = e->zr * e->zr - e->zi * e->zi - 1.8;
		e->zi = 2 * e->zi * e->tmp + 0.06;
	}
	else
		magie_suite(e);
}

void	magie_suite(t_coef *e)
{
	if (e->av == 7)
	{
		e->zr = e->zr * e->zr - e->zi * e->zi * e->zi;
		e->zi = 2 * e->zi * e->tmp - 2;
	}
	else if (e->av == 8)
	{
		e->zr = e->zr * e->zr - e->zi * e->zi - 0.76;
		e->zi = 2 * e->zi * e->tmp + 0.12;
	}
	else if (e->av == 9)
	{
		e->zr = e->zr * e->zr - e->zi * e->zi - 2;
		e->zi = 2 * e->zi * e->tmp;
	}
	else
	{
		e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
		e->zi = -2 * e->zi * e->tmp + e->ci;
	}
}
