/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2017/04/13 22:00:46 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HORI 600
# define VERTI 600
# define MOTION_NOTIFY 6
# define PTR_MOTION_MASK (1L<<6)

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct		s_coef
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			sl;
	int			av;
	int			imax;
	int			imx;
	int			imy;
	int			c;
	int			col;
	int 		r;
	int 		g;
	int 		b;
	int 		t;
	int 		m;
	int			stop;
	long double tmp;
	long double	zoom;
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
	long double paramx;
	long double paramy;
}					t_coef;

void				new_image(t_coef *scoef);
void				init_struct(t_coef *scoef);
int					ft_keyhook(int key, t_coef *param);
void				put_pixel(t_coef *scoef, int x, int y, int color);
void				color(int i, t_coef *e);
void				magie(t_coef *e, int x, int y);
void				ft_fractal(t_coef *e);
void				init_fract(t_coef *e);
int					ft_mousehook(int key, int x, int y, t_coef *param);
void				ft_zoom(t_coef *e, int x, int y);
void				ft_dezoom(t_coef *e, int x, int y);
int					stock_av(char *av);
void				def_mand_burn(t_coef *e, int x, int y);
void				def_jul(t_coef *e, int x, int y);
int					fluide(int x, int y, t_coef *f);
void				menu(t_coef *axes);
#endif
