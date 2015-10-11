#pragma once
#include "lib/framework.hpp"
#include "struct.h"
#include "hit.h"
#include "screen.h" 
#include <ctime>
#include "string"
#include <iostream>

void Company(Player& player);

class COMPANY
{
public:

    void Company_main(Player& player);
private:

    void Update(Player& player);
    void Draw(Player& player);

    void Key();
    void Enter(Player& player);
    void Font_Color();
    void Stop();

    Random rand;
    Texture bg = Texture("res/sontyou_ie.png");
    Texture message = Texture("res/mese-ji.png");
    Texture message2 = Texture("res/mese-ji2.png");

    Texture jijii = Texture("res/jijii.png");

    Media ok = Media("res/se/kettei_.wav");
    Media bgm = Media("res/se/sontyou.wav");
    Media sele = Media("res/se/sentaku.wav");
    Media get = Media("res/se/okane_kakutoku.wav");

    Font font = ("res/meiryo.ttc");
    //std::to_string
    std::string text = "  ";
    std::string text2 = "  ";

    int select = 0;
    int select2 = 0;
    int is_select2 = 0;

    Color select_color[3];
    Color select2_color[3];






};

