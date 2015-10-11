#pragma once
#include "lib/framework.hpp"
#include "struct.h"
#include "hit.h"
#include "screen.h" 
#include <ctime>
#include "string"
#include <iostream>

void StatusShop(Player& player);

class STATUS
{
public:

    void StatusShop_main(Player& player);
private:

    void Update(Player& player);
    void Draw(Player& player);

    void Key();
    void Enter(Player& player);
    void Font_Color();
    void Stop();

    enum Skill{
        heel,
        strong,
        death
    };
    Random rand;
    Texture bg = Texture("res/shop_bg.png");
    Texture message2 = Texture("res/mese-ji2.png");

    Media ok = Media("res/se/kettei_.wav");
    Media bgm = Media("res/se/mise.wav");
    Media sele = Media("res/se/sentaku.wav");
    Media get = Media("res/se/okane_kakutoku.wav");
    
    Font font = ("res/meiryo.ttc");
    //std::to_string
    std::string text = "  ";
    std::string text2 = "  ";
    int count = 0;

    int select = 0;
    int select_st = 0;
    int select_sk = 0;

    bool is_select_up = false;
    bool is_select_skill = false;

    Color font_color[3];
    Color st_color[3];
    Color sk_color[3];






};

