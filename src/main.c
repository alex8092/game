#include <stdlib.h>
#include "cgl.h"
#include "graphics/shader.h"
#include "graphics/cgprogram.h"
#include "graphics/scene.h"

t_cgl_cgprogram	*p = 0;

int			game_run(t_cgl_engine *engine)
{
	printf("in\n");
	cgl_tmp_draw(p);
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
	t_cgl_shader	*v = cgl_graphics_shader_create("Shaders/couleur2D.vert", CGL_SHADER_VERTEX);
	if (!v)
		return (-1);
	t_cgl_shader	*f = cgl_graphics_shader_create("Shaders/couleur2D.frag", CGL_SHADER_FRAGMENT);
	if (!f)
		return (-1);
	p = cgl_graphics_cgprogram_create(v, f);
	if (!p)
		return (-1);
	cgl_graphics_cgprogram_bind_location(p, 0, "in_Vertex");
	cgl_graphics_cgprogram_bind_location(p, 1, "in_Color");
	cgl_graphics_cgprogram_bind_location(p, 2, "in_TexCoord0");
	if (cgl_graphics_cgprogram_load(p) == -1)
		return (-1);
	ret = cgl_engine_system_run(game_run);
	cgl_engine_system_deinit();
	return (ret);
}