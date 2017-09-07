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

void				put_pixel(t_coef *scoef, int x, int y, int color)
{
	int	i;

	if (x >= HORI || x < 0 || y >= VERTI || y < 0)
		return ;
	i = x * 4 + y * scoef->sl;
	scoef->data[i] = (color & 0xff) + scoef->col;
	scoef->data[++i] = ((color >> 8) & 0xff) + scoef->col;
	scoef->data[++i] = (color >> 16) + scoef->col;
	scoef->data[++i] = (color >> 24) + scoef->t;
}

void				color(int i, t_coef *e)
{
	int r;
	int g;
	int b;

	if (i == e->imax)
		e->c = 0x00000000;
	else
	{
		r = (i * 10) * 2 + e->r;
		g = (i * 5) * 2 + e->g;
		b = (i * 1) * 2 + e->b;
		e->c = (r << 16) + (g << 8) + b;
	}
}

void	menu(t_coef *m)
{
	mlx_string_put(m->mlx, m->win, 10, 30, 0xFFFFFF,
			"[1/2/3] : Choix Mandelbrot/Burningship/julia");
	mlx_string_put(m->mlx, m->win, 10, 50, 0xFFFFFF,
			"[r/g/b/c/v] : rouge/vert/bleu/color+/color-");
	mlx_string_put(m->mlx, m->win, 10, 90, 0xFFFFFF,
			"[fleche] : Deplacement");
	mlx_string_put(m->mlx, m->win, 10, 70, 0xFFFFFF,
			"[click/molette] : Zoom avant, Zoom arriere");
	mlx_string_put(m->mlx, m->win, 10, 110, 0xFFFFFF,
			"[t] : Transparence :");
	mlx_string_put(m->mlx, m->win, 220, 110, 0xFFFFFF,
			ft_itoa(m->t/10));
	mlx_string_put(m->mlx, m->win, 10, 150, 0xFFFFFF,
			"[p] : Pause");
	mlx_string_put(m->mlx, m->win, 10, 130, 0xFFFFFF,
			"[+/-] : Iteration :");
	mlx_string_put(m->mlx, m->win, 220, 130, 0xFFFFFF,
			ft_itoa(m->imax));
}
