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

int					ft_mousehook(int key, int x, int y, t_coef *e)
{
	if (key == 1 || key == 4)
		ft_zoom(e, x, y);
	else if (key == 2 || key == 5)
		ft_dezoom(e, x, y);
	else
		return (0);
	ft_fractal(e);
	return (0);
}

int					fluide(int x, int y, t_coef *f)
{
	if (f->stop == 0 && (f->av == 3 || f->av == 4))
	{
		f->paramx = x;
		f->paramy = y;
	}
	ft_fractal(f);
	return (0);
}

int					ft_keyhook(int key, t_coef *e)
{
	if (key == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		free(e);
		exit(EXIT_SUCCESS);
	}
	else if (key == 69 || key == 78 || key == 124 || key == 123 ||
		key == 125 || key == 126 || key == 8 || key == 11 || key == 5)
		ft_keyhook4(key, e);
	else if (key == 9 || key == 15 || key == 5 || key == 11 ||
		key == 17 || key == 46 || key == 35)
		ft_keyhook1(key, e);
	else if (key == 82 || key == 83 || key == 84 || key == 85 || key == 86)
		ft_keyhook2(key, e);
	else if (key == 87 || key == 88 || key == 89 || key == 91 || key == 92)
		ft_keyhook3(key, e);
	else
		return (0);
	ft_fractal(e);
	return (0);
}
