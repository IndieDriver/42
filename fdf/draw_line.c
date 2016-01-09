#include "fdf.h"

void	convert_octan(int *dx, int *dy, int *sx, int *sy)
{
	*sx = *dx > 0 ? 1 : -1;
	*sy = *dy > 0 ? 1 : -1;
	*dx = *dx > 0 ? -(*dx) : *dx;
	*dy = *dy > 0 ? -(*dy) : *dy;
}

void	bresenham(t_env env, t_point from, t_point to, t_line value)
{
	while (to.x <= from.x)
	{
		mlx_pixel_put(env.mlx, env.win, from.x + (WIDTH / 2),
		from.y + (HEIGHT / 2), 0x0000FF);
		if (value.err >= 0)
		{
			from.y += value.sy;
			value.err += 2 * (value.dy - value.dx);
		}
		else
			value.err += 2 * value.dy;
	}
}

void	bresenham_inverse(t_env env, t_point from, t_point to, t_line value)
{
	while (to.y <= from.y)
	{
		mlx_pixel_put(env.mlx, env.win, from.x + (WIDTH/2),
		from.y + (HEIGHT/2), 0x0000FF);
		if (value.err >= 0)
		{
			from.x += value.sx;
			value.err += 2 * (value.dy - value.dx);
		}
		else
			value.err += 2 * value.dy;
	}
}
void	draw_line(t_env env, t_point from, t_point to)
{
	t_line value;

	value.dx = to.x - from.x;
	value.dy = to.y - from.y;
	convert_octan(&value.dx, &value.dy, &value.sx, &value.sy);
	value.err = 2 * value.dy - value.dx;
	if (value.dx > value.dy)
		bresenham(env, from, to, value);
	else
		bresenham_inverse(env, from, to, value);
}
