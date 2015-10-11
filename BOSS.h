#pragma once
#include "lib/framework.hpp"
#include "screen.h"
#include "struct.h" 

void Boss(Player& player,int& sceen);



class BOSS
{
public:
    void main(Player& player, int& sceen);


private:

    void init(Player& player);
    void Update(Player& player, int& sceen);
    void Draw(Player& player);

    Random rand;

    bool Probability(float probability);
    void Enemy_turn(Player& player);

    Texture bg = Texture("res/Battle_bg.png");
    Texture ene01 = Texture("res/monstr01.png");
    Texture win = Texture("res/win.png");
    Texture lose = Texture("res/lose.png");
    Texture message = Texture("res/mese-ji.png");
    Texture jijii = Texture("res/jijii.png");
    Texture message2 = Texture("res/mese-ji2.png");


    Media bgm = Media("res/se/sentou.wav");
    Media ok = Media("res/se/kettei_.wav");
    Media sele = Media("res/se/sentaku.wav");
    Media get = Media("res/se/okane_kakutoku.wav");
    Media cra = Media("res/se/crash.wav");
    Media bgm2 = Media("res/se/sontyou.wav");


    Font font = ("res/meiryo.ttc");
    std::string text = "  ";
    std::string text2 = "  ";

    Player playera;
    int remaining_hp;   //écÇËÇàÇê
    
    int battle_select = 0;
    Color battle_select_color[5];

    bool is_win =false;
    bool is_lose =false;
    bool my_turn = true;
    int atk;
    int timer = 0;

    Enemy boss;

    std::string stext1 = "  ";
    std::string stext2 = "  ";

    int count = 0;
    int scene = 0;
    void story();
    void end(Player& player);


};

