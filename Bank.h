#pragma once
#include "lib/framework.hpp"
#include "struct.h"
#include "hit.h"
#include "screen.h" 
#include <ctime>
#include "string"
#include <iostream>

void Bank(Player& player);

class BANK
{
public:

    void Bank_main(Player& player);
private:

    void Update(Player& player);
    void Draw(Player& player);

    void Key();
    void Enter(Player& player);
    void Font_Color();
    void Stop(Player& player);

    Random rand;

    Font font = ("res/meiryo.ttc");
    Texture bg = Texture("res/Bank_bg.png");
    Texture message2 = Texture("res/mese-ji2.png");
    Media ok = Media("res/se/kettei_.wav");
    Media bgm = Media("res/se/ginkou.wav");
    
    Media sele = Media("res/se/sentaku.wav");
    Media kane = Media("res/se/okane_kakutoku.wav");


    //std::to_string
    std::string text = "  ";
    std::string text2 = "  ";

    int select = 0;
    bool is_select1 = 0;
    bool is_select2 = 0;

    Color select_color[3];
    
    __int64 how=0;

    int increment_amount = 0;


};

