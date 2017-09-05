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
