#pragma once
#include "lib/framework.hpp"
#define env App::get()

#define WIN_WIDTH (2048)
#define WIN_HEIGHT (1024)
#define MAP_WIDTH (256)
#define MAP_HEIGHT (256)

class App
{
private:

	App(){}

public:

	static AppEnv& get()
	{
		static AppEnv s_env(WIN_WIDTH, WIN_HEIGHT,0,1);

		return s_env;
	}
};