/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:27:17 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/09 19:01:46 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	while (r > 255 && g > 255 && b > 255)
	{
		if (r > 255)
			r = r - 255;
		else if (g > 255)
			g = g - 255;
		else if (b > 255)
			b = b - 255;
	}
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ocolor(t_struct *t)
{
	if (t->color == 0)
		return (create_trgb(0, t->i, t->i * 5, t->i));
	else if (t->color == 1)
		return (create_trgb(0, t->i * 5, t->i, t->i));
	else if (t->color == 2)
		return (create_trgb(0, t->i, t->i, t->i * 5));
	else if (t->color == 3)
		return (create_trgb(0, t->i * 34, t->i * 55, t->i * 89));
	else if (t->color == 4)
		return (create_trgb(0, t->i * 55, t->i * 89, t->i * 34));
	else if (t->color == 5)
		return (create_trgb(0, t->i * 89, t->i * 34, t->i * 55));
	return (0);
}

int	color(t_struct *t)
{
	if (t->color < 3)
		return (create_trgb(0, 0, 0, 0));
	else if (t->color == 3)
		return (create_trgb(0, 0, 255, 255));
	else if (t->color == 4)
		return (create_trgb(0, 255, 0, 255));
	else if (t->color == 5)
		return (create_trgb(0, 255, 255, 0));
	return (0);
}

void	my_mlx_pixel_put(t_window_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_window(t_struct *t)
{
	t->data.mlx = mlx_init();
	t->data.win = mlx_new_window(t->data.mlx, t->scrn.x, t->scrn.y,
			t->data.name);
	t->data.img = mlx_new_image(t->data.mlx, t->scrn.x, t->scrn.y);
	t->data.addr = mlx_get_data_addr(t->data.img, &t->data.bits_per_pixel,
			&t->data.line_lenght, &t->data.endian);
	mlx_key_hook(t->data.win, key_hook, t);
	mlx_hook(t->data.win, 17, 1L << 0, close_window, t);
	mlx_hook(t->data.win, 6, 0, change_julia, t);
	mlx_mouse_hook(t->data.win, mouse_hook, t);
	parse_fractal(t);
	mlx_loop(t->data.mlx);
}
