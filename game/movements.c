#include "../so_long.h"

void	you_won()
{

}

bool	move_helper(t_map map, int x_dest, int y_dest)
{
	if (map.map[x_dest][y_dest] == '1')
		return (false);
	if (map.map[x_dest][y_dest] == 'C')
		
	if (map.map[x_dest][y_dest] == 'H')
	if (map.map[x_dest][y_dest] == 'E' && map.entities.c_cont == 0)
		you_won();
	else
		return (false);
}

void	p_moveup(t_map map)
{
	if (!move_helper(map, map.map_x, map.map_y+1))
		return ;

}

void	p_movedown(t_map map)
{
	if (!move_helper(map, map.map_x, map.map_y-1))
		return ;
}

void	p_moveleft(t_map map)
{
	if (!move_helper(map, map.map_x-1, map.map_y))
		return ;
}

void	p_moveright(t_map map)
{
	if (!move_helper(map, map.map_x+1, map.map_y))
		return ;
}
