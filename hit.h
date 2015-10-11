#pragma once
#include "lib/framework.hpp"
#include "struct.h"


bool hitting_square(Vec2f pos, Vec2f box_pos, Vec2f box_size);
bool hit_block1(Vec2f& pos,Vec2f& block,Vec2f pos_size,Vec2f block_size);
bool hit_block2(Vec2f& pos, Vec2f& block, Vec2f pos_size, Vec2f block_size);
bool hit_block3(Vec2f& pos, Vec2f& block, Vec2f pos_size, Vec2f block_size);
bool hit_block4(Vec2f& pos, Vec2f& block, Vec2f pos_size, Vec2f block_size);
bool hit_block5(Vec2f& pos, Vec2f& block, Vec2f vec, Vec2f pos_size, Vec2f block_size);
void hit_block6(Vec2f& pos, Vec2f& block, Vec2f& vec, Vec2f pos_size, Vec2f block_size);
void hit_block7(Vec2f& pos, Vec2f& block, Vec2f& vec, Vec2f pos_size, Vec2f block_size);
bool hit_floor(Vec2f& pos, Vec2f& block, Vec2f& vec, Vec2f pos_size, Vec2f block_size);
void not_floor(Player& player, Vec2f& block, Vec2f block_size);

