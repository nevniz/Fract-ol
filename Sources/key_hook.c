/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:34:16 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/08 13:52:32 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	close_window(t_struct *t)
{
	mlx_destroy_image(t->data.mlx, t->data.img);
	mlx_destroy_window(t->data.mlx, t->data.win);
	exit (0);
}

void	move(t_struct *t, double x, double y)
{
	t->start.x = -1;
	if (x)
		t->move.x += (x / t->scl);
	else if (y)
		t->move.y += (y / t->scl);
}

void	iter(t_struct *t, int index)
{
	t->start.x = -1;
	if (index == 1)
		t->iter++;
	else if (index == 2)
		t->iter--;
}

void	change_color(t_struct *t)
{
	t->start.x = -1;
	t->color += 1;
	if (t->color == 6)
		t->color = 0;
}

int	key_hook(int key, t_struct *t)
{
	if (key == 53)
		close_window(t);
	else if (key == 123)
		move(t, -20, 0);
	else if (key == 124)
		move(t, 20, 0);
	else if (key == 125)
		move(t, 0, 20);
	else if (key == 126)
		move(t, 0, -20);
	else if (key == 24)
		iter(t, 1);
	else if (key == 27)
		iter(t, 2);
	else if (key == 49)
		change_color(t);
	parse_fractal(t);
	return (0);
}
