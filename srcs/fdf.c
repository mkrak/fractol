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
	init_fract(scoef);
	mlx_loop(scoef->mlx);
	free(scoef);
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
			magie(e, x, y);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	magie(t_coef *e, int x, int y)
{
	int i;

	i = -1;
	while (++i< e->imax && e->zr * e->zr + e->zi * e->zi < 4)
	{
		e->tmp = e->zr;
		if (e->av == 3)
		{
			e->zr = e->zr * e->zr - e->zi * e->zi - 0.8 + (0.6 / (e->paramx / VERTI));
			e->zi = 2 * e->zi * e->tmp + 0.27015 / (e->paramy / VERTI);
		}
		else
		{
				e->zr = e->zr * e->zr - e->zi * e->zi + e->cr;
			if (e->av == 1)
				e->zi = 2 * e->zi * e->tmp + e->ci;
			else
				e->zi = 2 * fabsl(e->zi * e->tmp) + e->ci;
		}
	}
	color(i, e);
	put_pixel(e, x - e->imx, y - e->imy, e->c);
}
