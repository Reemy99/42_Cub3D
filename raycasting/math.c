#include "../include/include.h"

int	is_up(double ang)
{
	if (ang >= M_PI && ang <= (2 * M_PI)) // 180 and 360 degrees.
		return (1);
	return (0);
}
//__________________________________________
int	is_left(double ang)
{
	if (ang >= (M_PI / 2) && ang <= ((3 * M_PI) / 2)) //between 90 degrees and 270 
		return (1);
	return (0);
}
//__________________________________________
unsigned int	floor_color(t_all *data)
{
	unsigned int red = data->valid.floor[0];
	unsigned int green = data->valid.floor[1];
	unsigned int blue = data->valid.floor[2];
	
	unsigned int colorValue = (red << 16) + (green << 8) + blue;
	
	return colorValue;
}
//__________________________________________
// Pythagorean theorem "fethagorse"
double	calculate_distance(t_all *data, double y, double x)
{
	return (sqrt(pow(x - data->x_player, 2) + pow(y - data->y_player, 2)));
}
//__________________________________________
unsigned int	ceiling_color(t_all *data)
{
	unsigned int red = data->valid.ceiling[0];
	unsigned int green = data->valid.ceiling[1];
	unsigned int blue = data->valid.ceiling[2];
	
	unsigned int colorValue = (red << 16) + (green << 8) + blue;
	
	return colorValue;
}

