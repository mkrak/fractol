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

void				init_struct(t_coef *scoef)
{
	scoef->mlx = mlx_init();
	scoef->win = mlx_new_window(scoef->mlx, HORI, VERTI, "mlx 42");

}

void				new_image(t_coef *scoef)
{
	int		bpp;
	int		endian;

	scoef->img = mlx_new_image(scoef->mlx, HORI, VERTI);
	scoef->data = mlx_get_data_addr(scoef->img, &bpp, &scoef->sl, &endian);
}


int					ft_keyhook(int key, t_coef *e)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 69)
	{
		e->zoom *= 1.2;
		e->imx *= 1.2;
		e->imy *= 1.2;
	}
	else if (key == 124)
		e->imx -= 20;
	else if (key == 123)
		e->imx += 20;
	else if (key == 125)
		e->imy -= 20;
	else if (key == 126)
		e->imy += 20;
	else if (key == 8)
		e->col -= 1;
	else if (key == 9)
		e->col += 1;
//	else if (key != 53)
//		printf("key = %d\n", key);
	else if (key == 15)
		mandelbrot_init(e);
	else
		return (0);
	mlx_destroy_image(e->mlx, e->img);
	new_image(e);
	mandelbrot_basic(e);
	return (0);
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
	mandelbrot_basic(e);
	return (0);
}


void				put_pixel(t_coef *scoef, int x, int y, int color)
{
	int	i;

	if (x >= HORI || x < 0 || y >= VERTI || y < 0)
		return ;
	i = x * 4 + y * scoef->sl;
	scoef->data[i] = color & 0xff + scoef->col;
	scoef->data[++i] = (color >> 8) & 0xff + scoef->col;
	scoef->data[++i] = (color >> 16) + scoef->col;
}
