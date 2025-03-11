/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:37:42 by pschmunk          #+#    #+#             */
/*   Updated: 2025/03/11 23:40:50 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	calc_dist(t_data *data, double x0, double y0, double x1, double y1)
{
	double	delta_x;
	double	delta_y;
	double	angle;

	delta_x = x1 - x0;
	delta_y = y1 - y0;
	angle = atan2(delta_y, delta_x) - data->playerA;
	return ((sqrt(delta_x * delta_x + delta_y * delta_y)) * cos(angle));
}

double	get_dist(t_data *data, int end, double *x, double *y)
{
	int	i;

	i = 0;
	while (i < end)
	{
		data->mapX = (int)data->rayX / TILE;
		data->mapY = (int)data->rayY / TILE;
		if (data->mapX >= 0 && data->mapY >= 0
			&& data->mapX <= TILES_X && data->mapY <= TILES_Y
			&& data->map[data->mapX][data->mapY] == '1')
		{
			*x = data->rayX;
			*y = data->rayY;
			return (calc_dist(data, data->playerX, data->playerY, *x, *y));
		}
		else
		{
			data->rayX += data->offsetX;
			data->rayY += data->offsetY;
			i++;
		}
	}
	return (1000000);
}

void	set_horizontal(t_data *data, double tan)
{
	if (data->rayA > PI)
	{
		data->rayY = ((int)data->playerY / TILE) * TILE - 0.0001;
		data->rayX = ((int)data->playerY - data->rayY)
			* tan + (int)data->playerX;
		data->offsetY = -TILE;
		data->offsetX = TILE * tan;
	}
	if (data->rayA < PI)
	{
		data->rayY = ((int)data->playerY / TILE) * TILE + TILE;
		data->rayX = ((int)data->playerY - data->rayY)
			* tan + (int)data->playerX;
		data->offsetY = TILE;
		data->offsetX = -TILE * tan;
	}
}

void	set_vertical(t_data *data, double tan)
{
	if (data->rayA > (PI / 2) && data->rayA < ((3 * PI) / 2))
	{
		data->rayX = ((int)data->playerX / TILE) * TILE - 0.0001;
		data->rayY = ((int)data->playerX - data->rayX)
			* tan + (int)data->playerY;
		data->offsetX = -TILE;
		data->offsetY = TILE * tan;
	}
	if (data->rayA < (PI / 2) || data->rayA > ((3 * PI) / 2))
	{
		data->rayX = ((int)data->playerX / TILE) * TILE + TILE;
		data->rayY = ((int)data->playerX - data->rayX)
			* tan + (int)data->playerY;
		data->offsetX = TILE;
		data->offsetY = -TILE * tan;
	}
}

int	draw_3d(t_data *data, int x, double dis, int color)
{
	double	wall_height;
	double	offset;

	wall_height = (TILE * HEIGHT) / dis;
	offset = (HEIGHT / 2) - (wall_height / 2);
	render_line(data, x + (WIDTH / 2), offset, x + (WIDTH / 2), wall_height + offset, color);
	x++;
	while (x % ((WIDTH / 2) / FOV) != 0)
	{
		render_line(data, x + (WIDTH / 2), offset, x + (WIDTH / 2), wall_height + offset, color);
		x++;
	}
	return (x);
}

void	draw_rays(t_data *data)
{
	int		x;
	int		i;
	int 	color;
	double	dis_h;
	double	dis_v;
	double	dis;

	data->rayA = get_angle(data->playerA - (DEGREE * (FOV / 2)));
	i = 0;
	x = 0;
	while (i < FOV)
	{
		data->horizontalX = data->playerX;
		data->horizontalY = data->playerY;
		set_horizontal(data, -1 / tan(data->rayA));
		dis_h = get_dist(data, TILES_Y, &data->horizontalX, &data->horizontalY);
		data->verticalX = data->playerX;
		data->verticalY = data->playerY;
		set_vertical(data, -tan(data->rayA));
		dis_v = get_dist(data, TILES_X, &data->verticalX, &data->verticalY);
		if (dis_v < dis_h)
		{
			data->rayX = data->verticalX;
			data->rayY = data->verticalY;
			dis = dis_v;
			color = 0x73504A;
		}
		else if (dis_h < dis_v)
		{
			data->rayX = data->horizontalX;
			data->rayY = data->horizontalY;
			dis = dis_h;
			color = 0x44393C;
		}
		render_line(data, (int)data->playerX, (int)data->playerY,
			(int)data->rayX, (int)data->rayY, color);
		x = draw_3d(data, x, dis, color);
		data->rayA = get_angle(data->rayA + DEGREE);
		i++;
	}
}
