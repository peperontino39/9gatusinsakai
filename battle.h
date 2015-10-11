#pragma once
#include "lib/framework.hpp"
#include "struct.h"
#include "hit.h"
#include "screen.h" 
#include <ctime>
#include "string"
#include <iostream>

void Battle(Player& player);

class BATTLE
{

public:

    BATTLE(Player& player){
     
    }
    void Battle_Game(Player& player);

private:

    enum Skill{
        heel,
        strong,
        death
    };
    Random rand;
    //rand.setSeed(time(nullptr));
    Texture ene01= Texture("res/monstr01.png");
    Texture win = Texture("res/win.png");
    Texture lose = Texture("res/lose.png");
    Texture bg = Texture("res/Battle_bg.png");
    Texture message2 = Texture("res/mese-ji2.png");

    Font font = ("res/meiryo.ttc");

    Media bgm = Media("res/se/sentou.wav");
    Media ok = Media("res/se/kettei_.wav");
    Media sele = Media("res/se/sentaku.wav");
    Media get = Media("res/se/okane_kakutoku.wav");
    Media cra = Media("res/se/crash.wav");

    void Init();
    void Draw(Player player);
    void Update(Player& player);
    void Update2(Player& player);
    void Draw2(Player player);
    bool Probability(float probability);
    void Enemy_turn(Player& player);

    Color font_color[4];
    Color st_color[3];
    Color sk_color[3];

    
    Color battle_select_color[5];
    int battle_select=0;

    int sceen = 0;
    int select = 0;
    int select_up = 0;
    bool is_select_up = false;

    int select_skill = 0;
    bool is_select_skill = false;
    bool my_turn = true;
    
    int remaining_hp;   //écÇËÇàÇê
    Enemy enemy;
    Player playerb;
    std::string text = "  ";
    std::string text2 = "  ";
    int atk;
    bool is_win;
    bool is_lose;

    int timer = 0;
    // int status_dispatching = 0;
    
};

