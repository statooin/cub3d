#include "cub3d.h"

void	ft_fps(int itime)
{
	printf("%f\n", (float)itime / ((clock() - fps) / CLOCKS_PER_SEC));
}
