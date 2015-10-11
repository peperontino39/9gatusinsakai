#pragma once
#include "lib/framework.hpp"
enum Place
{
    WORLD,
    ROULETTE,
    BATTLE_,
    COMPANY_,
    BANK_,
    STATUS_,
    BOSS_
};


enum Window {
    WIDTH = 2048,
    HEIGHT = 1024
};
struct Player{
    Vec2f pos;
    Vec2f size;
    Vec2f vec;
    bool is_jump;
    int place;
    int speed;
    float gravity;
    int floor_count;
    int day;
    int month ;
    int age ;
    __int64 have_money;

    int hp = 100;
    int attack = 5;
    int defense = 5;

    int skill[3];
    int battle_reaching = 1;
    int ani_count = 0;
    Texture tx;
    __int64 deposit = 0;//óaã‡
    int deposit_day ;
    int flag;
    int boss_flag;
};

struct Tx {
    Texture bg;
    Texture block;
    
    Texture spring;//èt
    Texture summer;// âƒ
    Texture fall;  //èH
    Texture winter;//ì~

    Texture rt;
    Texture Sign;
    Texture Village;
    Texture bank;
    Texture keep_out;
    Texture Shop;


    Font font = Font("res/meiryo.ttc");
};

struct map_chip{
    char map[16][32];

};
struct Enemy{
    int lv;
    int hp;
    int attack;


    Texture tx;
};

struct medias
{
    Media bgm;
    Media ok;
    


}; 

