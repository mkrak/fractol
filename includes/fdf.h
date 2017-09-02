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

# include "mlx.h"
# include <stdio.h>
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

	int			imax;
	int			imx;
	int			imy;
	int			c;
	int 		col;
	long double tmp;
	long double	x1;
	long double	y1;
	long double	zoom;
	long double	cr;
	long double	ci;
	long double	zr;
	long double	zi;
}					t_coef;

void				ft_line(t_coef *s, int x_a, int y_a, int x_b, int y_b);
void				reset_v(int *i, int *j, int *k, char **line);
void				init_map(t_coef *s, int x, int y);
void				new_image(t_coef *scoef);
void				init_struct(t_coef *scoef);
int					ft_keyhook(int key, t_coef *param);
int					ft_countword(char const *s);
int					ft_open(char *str);
int					*ft_read(char **av);
int					**ft_map(t_coef *param, int x, int y, char **av);
void				put_pixel(t_coef *scoef, int x, int y, int color);

void				color(int i, t_coef *e);
void				mandelbrot(t_coef *e, int x, int y);
void				mandelbrot_basic(t_coef *e);
void				mandelbrot_init(t_coef *e);
int					ft_mousehook(int key, int x, int y, t_coef *param);
void		        ft_zoom(t_coef *e, int x, int y);
void				ft_dezoom(t_coef *e, int x, int y);


#endif
