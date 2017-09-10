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

void				put_pixel(t_coef *s, int x, int y, int color)
{
	int	i;

	if (x >= HORI || x < 0 || y >= VERTI || y < 0)
		return ;
	i = x * 4 + y * s->sl;
	if (s->av == 4)
	{
		s->data[i] = (color & 0xff) + s->paramx;
		s->data[++i] = ((color >> 8) & 0xff) + s->paramx + s->paramy;
		s->data[++i] = (color >> 16) + s->paramy;
		s->data[++i] = (color >> 24) + s->t;
	}
	else
	{
		s->data[i] = (color & 0xff) + s->col;
		s->data[++i] = ((color >> 8) & 0xff) + s->col;
		s->data[++i] = (color >> 16) + s->col;
		s->data[++i] = (color >> 24) + s->t;
	}
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
		r = (255 - (i * 5)) * 2 + e->r;
		g = (255 - (i * 10)) * 2 + e->g;
		b = (255 - (i * 2)) * 2 + e->b;
		e->c = (r << 16) + (g << 8) + b;
	}
}

void				menu(t_coef *m)
{
	mlx_string_put(m->mlx, m->win, 10, 30, 0x000000,
			"[0/1/2/3/4/5/6/7/8/9] : Choix Fractale");
	mlx_string_put(m->mlx, m->win, 10, 50, 0x000000,
			"[r/g/b/c/v] : rouge/vert/bleu/color+/color-");
	mlx_string_put(m->mlx, m->win, 10, 90, 0x000000,
			"[fleche] : Deplacement");
	mlx_string_put(m->mlx, m->win, 10, 70, 0x000000,
			"[click/molette] : Zoom avant, Zoom arriere");
	mlx_string_put(m->mlx, m->win, 10, 110, 0x000000,
			"[t] : WTF ");
	mlx_string_put(m->mlx, m->win, 220, 110, 0x000000,
			ft_itoa(m->t / 10));
	mlx_string_put(m->mlx, m->win, 10, 150, 0x000000,
			"[p] : Pause");
	mlx_string_put(m->mlx, m->win, 10, 130, 0x000000,
			"[+/-] : Iteration :");
	mlx_string_put(m->mlx, m->win, 220, 130, 0x000000,
			ft_itoa(m->imax));
}
