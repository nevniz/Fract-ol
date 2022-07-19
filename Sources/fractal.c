/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:17:45 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/09 18:09:03 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	draw_rest(t_struct *t)
{
	t->i = -1;
	while (++t->i < t->iter && (t->res.x * t->res.x + t->res.y * t->res.y) < 4)
	{
		t->res.a = (t->res.x * t->res.x) - (t->res.y * t->res.y) + t->res.px;
		if (t->arg != 3)
			t->res.b = 2 * t->res.x * t->res.y + t->res.py;
		else
			t->res.b = 2 * fabs(t->res.x) * fabs(t->res.y) + t->res.py;
		t->res.x = t->res.a;
		t->res.y = t->res.b;
	}
	if (t->i == t->iter)
		my_mlx_pixel_put(&t->data, t->start.x, t->start.y, color(t));
	else if (t->i >= 0 && t->i < t->iter)
		my_mlx_pixel_put(&t->data, t->start.x, t->start.y, ocolor(t));
}

static void	burning_ship(t_struct *t)
{
	while (++t->start.x < t->scrn.x)
	{
		t->start.y = -1;
		while (++t->start.y < t->scrn.y)
		{
			t->res.x = (t->start.x - t->mdl.x) / t->scl + t->move.x;
			t->res.y = (t->start.y - t->mdl.y) / t->scl + t->move.y;
			t->res.px = t->res.x;
			t->res.py = t->res.y;
			draw_rest(t);
		}
	}
	mlx_put_image_to_window(t->data.mlx, t->data.win, t->data.img, 0, 0);
}

static void	julia(t_struct *t)
{
	while (++t->start.x < t->scrn.x)
	{
		t->start.y = -1;
		while (++t->start.y < t->scrn.y)
		{
			t->res.x = (t->start.x - t->mdl.x) / t->scl + t->move.x;
			t->res.y = (t->start.y - t->mdl.y) / t->scl + t->move.y;
			t->res.px = t->jul.x;
			t->res.py = t->jul.y;
			draw_rest(t);
		}
	}
	mlx_put_image_to_window(t->data.mlx, t->data.win, t->data.img, 0, 0);
}

static void	mandelbrot(t_struct *t)
{
	while (++t->start.x < t->scrn.x)
	{
		t->start.y = -1;
		while (++t->start.y < t->scrn.y)
		{
			t->res.x = (t->start.x - t->mdl.x) / t->scl + t->move.x;
			t->res.y = (t->start.y - t->mdl.y) / t->scl + t->move.y;
			t->res.px = t->res.x;
			t->res.py = t->res.y;
			t->res.p = sqrt((t->res.x - 0.25) * (t->res.x - 0.25)
					+ t->res.y * t->res.y);
			t->res.pc = 0.5 - (cos(atan2(t->res.y, t->res.x - 0.25)) / 2);
			if (t->res.p <= t->res.pc)
				my_mlx_pixel_put(&t->data, t->start.x, t->start.y,
					color(t));
			else
				draw_rest(t);
		}
	}
	mlx_put_image_to_window(t->data.mlx, t->data.win, t->data.img, 0, 0);
}

void	parse_fractal(t_struct *t)
{
	if (t->arg == 1)
		mandelbrot(t);
	else if (t->arg == 2)
		julia(t);
	else if (t->arg == 3)
		burning_ship(t);
}
