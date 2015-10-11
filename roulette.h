#pragma once
#include "lib/framework.hpp"
#include "struct.h"
#include "hit.h"
#include "screen.h"

void tip_draw(Vec2f pos, int bet_number, Texture tip, Font font);
void roulette(Player& player);
