/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <llawrenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:23:49 by llawrenc          #+#    #+#             */
/*   Updated: 2022/03/09 19:02:21 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	zoom_window(t_struct *t, int x, int y, double zoom)
{
	t->start.x = -1;
	t->scl *= zoom;
	t->zoom.x = ((double)x - t->mdl.x) - ((double)x - t->mdl.x) * zoom;
	t->zoom.y = ((double)y - t->mdl.y) - ((double)y - t->mdl.y) * zoom;
	t->mdl.x += t->zoom.x;
	t->mdl.y += t->zoom.y;
}

int	change_julia(int x, int y, t_struct *t)
{
	t->start.x = -1;
	t->jul.x = (x - t->mdl.x) / t->scl;
	t->jul.y = (y - t->mdl.y) / t->scl;
	parse_fractal(t);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_struct *t)
{
	if (key == 4)
		zoom_window(t, x, y, 1.1);
	else if (key == 5)
		zoom_window(t, x, y, 0.9);
	parse_fractal(t);
	return (0);
}
