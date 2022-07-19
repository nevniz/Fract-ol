/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:40:05 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/09 18:49:41 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_res
{
	double	x;
	double	y;
	double	a;
	double	b;
	double	px;
	double	py;
	double	p;
	double	pc;
}	t_res;

typedef struct s_window_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*name;
	int		endian;
	int		line_lenght;
	int		bits_per_pixel;
}	t_window_data;

typedef struct s_struct
{
	int				i;
	int				arg;
	int				scl;
	int				iter;
	int				color;
	t_res			mdl;
	t_res			res;
	t_res			jul;
	t_res			zoom;
	t_res			move;
	t_window_data	data;
	t_res			scrn;
	t_res			start;
}	t_struct;

int		ft_strcmp(char *str1, char *str2);
void	init_window(t_struct *t);
int		key_hook(int key, t_struct *t);
int		close_window(t_struct *t);
int		mouse_hook(int key, int x, int y, t_struct *t);
void	parse_fractal(t_struct *t);
void	my_mlx_pixel_put(t_window_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		color(t_struct *t);
int		ocolor(t_struct *t);
int		change_julia(int x, int y, t_struct *t);

#endif