#include <stdlib.h>
#include "cgl.h"

int			game_run(t_cgl_engine *engine)
{
	return (0);
}

int			main(int ac, char **av)
{
	int ret = 0;
	ret = cgl_engine_system_init("Game", 800, 600);
	if (ret < 0)
	{
		cgl_engine_system_deinit();
		return (ret);
	}
	ret = cgl_engine_system_run(game_run);
	cgl_engine_system_deinit();
	return (ret);
}