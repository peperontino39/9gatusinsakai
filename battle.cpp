#include "battle.h"




bool BATTLE::Probability(float probability){
    
    int a = rand(0.0f, 100.0f);
    //std::cout << a << std::endl;
    if (a<= probability){
        return 1;
    }
    else
    {
        return 0;
    }

}


void Battle(Player& player){

    BATTLE b(player);
    
    b.Battle_Game(player);

}

//Player BATTLE::player(Player& player){
//    return player;
//}

void BATTLE::Battle_Game(Player& player){
    bgm.looping(1);
    bgm.play();
    while (player.place== Place::BATTLE_)
    {
        if (!env.isOpen()) exit(0);
        env.begin();
        switch (sceen)
        {
        case 0:
            Update(player);
            Draw(player);
            break;
        case 1:
            Update2(player);
            Draw2(player);
            break;
        }
        
        env.end();

    }


}

void BATTLE::Init(){




}
void BATTLE::Update(Player& player){
    for (int i = 0; i < 4; i++){
        font_color[i] = Color::white;
        
    }
    for (int i = 0; i < 3; i++)
    {
        st_color[i] = Color::white;
        sk_color[i] = Color::white;
    }
    
    


        if (env.isPushKey('W')){
            if (is_select_up == 0 && is_select_skill == 0)
                select--;
            if (is_select_up == true)
                select_up--;
            if (is_select_skill == true)
                select_skill--;
            ok.play();
        }
        if (env.isPushKey('S')){
            if (is_select_up == 0 && is_select_skill == 0)
            select++;
            if (is_select_up == true)
                select_up++;
            if (is_select_skill == true)
                select_skill++;
            ok.play();

        }
        
        if (env.isPushKey(GLFW_KEY_ENTER)||env.isPushKey('D')){
           
           
            if (is_select_up == true){

                switch (select_up)
                {
                case 0:
                    if (player.have_money >= player.hp * 50){
                        player.have_money -= (player.hp * 50);
                        get.play();
                        player.hp += 10;
                    }
                    break;
                case 1:
                    if (player.have_money >= player.attack * 500){
                        player.have_money -= player.attack * 500;
                        get.play();
                        player.attack += 1;
                    }
                    break;
                case 2:
                    if (player.have_money >= player.defense * 500){
                        player.have_money -= player.defense * 500;
                        get.play();
                        player.defense += 1;
                    }
                    break;

                }
            }
                if (is_select_skill == true){

                    switch (select_skill)
                    {
                    case 0:
                        if (player.have_money >= player.skill[Skill::heel] * 10000 + 10000){
                            player.have_money -= (player.skill[Skill::heel] * 10000 + 10000);
                            player.skill[Skill::heel] += 1;
                            get.play();
                        }
                        break;
                    case 1:
                        if (player.have_money >= player.skill[Skill::strong] * 10000 + 10000){
                            player.have_money -= player.skill[Skill::strong] * 10000 + 10000;
                            player.skill[Skill::strong] += 1;
                            get.play();
                        }
                        break;
                    case 2:
                        if (player.have_money >= player.skill[Skill::death] * 10000 + 10000){
                            player.have_money -= player.skill[Skill::death] * 10000 + 10000;

                            player.skill[Skill::death] += 1;
                            get.play();
                        }
                        break;

                    }

            }
            switch (select)
            {
            case 0:
                sceen = 1;//戦闘に入るよ　Update2へ
                
                /////////////////////////////////////////////
                ////////////////////////////////////////////
                /////////////////////////////////////////////
                ////////////////////////////////////////////

                enemy =
                { player.battle_reaching,
                player.battle_reaching * 102,//hp
                player.battle_reaching * 25//攻撃力

                };
                is_win = false;
                is_lose = false;
                
                remaining_hp = player.hp;
                playerb = player;
                text = "  ";
                text2 = "  ";
                break;
            case 1:
                is_select_up = true;
                break;
            case 2:
                is_select_skill = true;
                break;
            case 3:
                player.place = WORLD;
                ///出るよｗ
              
                break;
            }

        }
    
    if (env.isPushKey('A')){
        is_select_up = 0;
        is_select_skill = 0;
    }



    if (select < 0)select = 0;
    if (select > 3)select = 3;
    if (select_up < 0)select_up = 0;
    if (select_up > 2)select_up = 2;
    if (select_skill < 0) select_skill = 0;
    if (select_skill > 2) select_skill = 2;
    //-------------------------------色変え
        switch (select)
        {
        case 0:
            font_color[0] = Color::red;
            break;
        case 1:
            font_color[1] = Color::red;
            break;
        case 2:
            font_color[2] = Color::red;
            break;
        case 3:
            font_color[3] = Color::red;
            break;

        }

        switch (select_up)
        {
        case 0:
            st_color[0] = Color::red;
            break;
        case 1:
            st_color[1] = Color::red;

            break;
        case 2:
            st_color[2] = Color::red;

            break;
        }
        switch (select_skill)
        {
        case 0 :
            sk_color[0] = Color::red;
            break; 
        case 1:
            sk_color[1] = Color::red;
            break; 
        case 2:
            sk_color[2] = Color::red;
                break;

        }
    
}
void BATTLE::Draw(Player player){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 2048, 1024, bg,Color::white);
    
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2 - 30, 700, 450, 0, 0, 2048, 512, message2);

    font.size(70);
    font.draw("たたかう", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 300) , font_color[0]);
    font.draw("ステータスを買う▹", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 200), font_color[1]);
    font.draw("技を買う▹", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 100), font_color[2]);
    font.draw("出る", Vec2f(-WIDTH / 2, -HEIGHT / 2), font_color[3]);

    font.draw("ｶﾈｰ     " + std::to_string(player.have_money), Vec2f(-WIDTH / 2, HEIGHT / 2 - 100), Color::black);
    font.draw("HP      " + std::to_string(player.hp), Vec2f(-WIDTH / 2, HEIGHT / 2 - 200), Color::black);
    font.draw("攻撃力 " + std::to_string(player.attack), Vec2f(-WIDTH / 2, HEIGHT / 2 - 300), Color::black);
    font.draw("防御力 " + std::to_string(player.defense), Vec2f(-WIDTH / 2, HEIGHT / 2 - 400), Color::black);
    if (is_select_up == true){
        drawTextureBox(-300, HEIGHT / 2 - 600, 800, 550, 0, 0, 2048, 512, message2);

        font.draw("ＨＰ    UP   ￥" + std::to_string(player.hp * 50), Vec2f(-200, HEIGHT / 2 - 200), st_color[0]);
        font.draw("攻撃力 UP   ￥" + std::to_string(player.attack * 500), Vec2f(-200, HEIGHT / 2 - 300), st_color[1]);
        font.draw("防御力 UP   ￥" + std::to_string(player.defense * 500), Vec2f(-200, HEIGHT / 2 - 400), st_color[2]);
    }
    if (is_select_skill == true){
        drawTextureBox(-500, HEIGHT / 2 - 600, 900, 550, 0, 0, 2048, 512, message2);

        font.draw("技名  使用回数  値段" , Vec2f(-400, HEIGHT / 2 - 200), Color::cyan);
        font.draw("強攻撃　　 " + std::to_string(player.skill[Skill::heel]) + 
            "       " + std::to_string(player.skill[Skill::heel] * 10000+10000),
            Vec2f(-400, HEIGHT / 2 - 300), sk_color[0]);
        font.draw("回復　 　 " + std::to_string(player.skill[Skill::strong]) +
            "       " + std::to_string(player.skill[Skill::strong] * 10000 + 10000),
            Vec2f(-400, HEIGHT / 2 - 400), sk_color[1]);
        font.draw("低確率キル" + std::to_string(player.skill[Skill::death]) +
            "       " + std::to_string(player.skill[Skill::death] * 10000 + 10000),
            Vec2f(-400, HEIGHT / 2 - 500), sk_color[2]);

    }
    if (select == 0){
        drawTextureBox(-300-30, HEIGHT / 2 - 300-30, 700, 120, 0, 0, 2048, 512, message2);

        font.draw("到達敵レベル  "+std::to_string(player.battle_reaching), Vec2f(-300, HEIGHT / 2 - 300), Color::cyan);

    }
}


void BATTLE::Update2(Player& player){
    if (is_win == false && is_lose == false){
        for (int i = 0; i < 5; i++)
        {
            battle_select_color[i] = Color::white;
        }




        if (env.isPushKey('W')){
            battle_select--;
            sele.play();
        }
        if (env.isPushKey('S')){
            battle_select++;
            sele.play();

        }
        if (env.isPushKey(GLFW_KEY_ENTER)){
            if (my_turn == true){
                switch (battle_select)
                {
                case 0:
                    atk = rand(playerb.attack - 4, playerb.attack + 50);
                    enemy.hp -= atk;
                    text = "金山は" + std::to_string(atk) + "のダメージを与えた";
                    my_turn = false;
                    cra.play();
                    break;
                case 1:
                    if (playerb.skill[0] > 0){
                        atk = rand(playerb.attack*3 - 4, playerb.attack * 3 + 50);
                        enemy.hp -= atk;
                        text = "金山は" + std::to_string(atk) + "のダメージを与えた";
                        my_turn = false;
                        playerb.skill[0]--;
                        cra.play();

                    }

                    break;
                case 2:
                    if (playerb.skill[1] > 0){

                        remaining_hp += playerb.hp / 2;
                        text = "金山は" + std::to_string(playerb.hp / 2) + "の回復した";
                        my_turn = false;
                        playerb.skill[1]--;
                        cra.play();

                    }
                    break;
                case 3:
                    if (playerb.skill[2] > 0){

                        if (Probability(10)){
                            enemy.hp = 0;
                            text = "金山は低確率キルに成功した";
                            my_turn = false;
                            playerb.skill[2]--;
                            cra.play();


                        }
                    
                    else
                    {


                        text = "金山は低確率キルに失敗した";
                        my_turn = false;
                        playerb.skill[2]--;
                        cra.play();


                    }
                }
                    break;
                case 4:
                    if (Probability(50)){
                        sceen = 0;

                    }
                    else
                    {
                        text = "逃げるのに失敗した";
                        my_turn = false;

                    }
                    break;

                }
            }
        }


        if (remaining_hp > playerb.hp)
            remaining_hp = playerb.hp;
        


        

        if (enemy.hp < 0)
            enemy.hp = 0;
            
        if (remaining_hp < 0)
            remaining_hp = 0;
       
        if (enemy.hp>0)
            Enemy_turn(playerb);
      
        
        
        if (battle_select < 0)battle_select = 0;
        if (battle_select > 4)battle_select = 4;

        switch (battle_select)
        {
        case 0:

            battle_select_color[0] = Color::red;
            break;
        case 1:
            battle_select_color[1] = Color::red;

            break;
        case 2:
            battle_select_color[2] = Color::red;

            break;
        case 3:
            battle_select_color[3] = Color::red;

            break;
        case 4:
            battle_select_color[4] = Color::red;

            break;
        }



        if (enemy.hp == 0){
            is_win = 1; timer = 0;
            player.day += 30;
            
        }
        if (remaining_hp == 0){
            is_lose = 1; timer = 0;
            player.day += 30;
        }
    }
    timer++;
    if (is_lose == 1 || is_win == 1)
    {
        if (timer == 100){
            sceen = 0;
            if (player.day > (player.boss_flag+1) * 10*12*30){
                player.place = BOSS_;
            }
            my_turn = true;
            if (is_win == 1)
                player.battle_reaching++;
        }
    }
}

void BATTLE::Draw2(Player player){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 2048, 1024, bg, Color::white);
    font.draw("HP      " + std::to_string(remaining_hp) + " / " + std::to_string(player.hp), Vec2f(-WIDTH / 2, HEIGHT / 2 - 100), Color::black);
    font.draw("攻撃力 " + std::to_string(player.attack), Vec2f(-WIDTH / 2, HEIGHT / 2 - 200), Color::black);
    font.draw("防御力 " + std::to_string(player.defense), Vec2f(-WIDTH / 2, HEIGHT / 2 - 300), Color::black);

    drawTextureBox(-WIDTH / 2, -HEIGHT / 2 - 30, 700, 550, 0, 0, 2048, 512, message2);
    drawTextureBox(-200, HEIGHT / 2 - 300, 700, 300, 0, 0, 2048, 512, message2);
    drawTextureBox(-350, -500, 1300, 300, 0, 0, 2048, 512, message2);

    font.draw("通常攻撃", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 400), battle_select_color[0]);
    font.draw("強攻撃     [" + std::to_string(playerb.skill[0])+"]", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 300), battle_select_color[1]);
    font.draw("回復       [" + std::to_string(playerb.skill[1]) + "]", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 200), battle_select_color[2]);
    font.draw("低確率キル  [" + std::to_string(playerb.skill[2]) + "]", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 100), battle_select_color[3]);
    font.draw("逃げる", Vec2f(-WIDTH / 2, -HEIGHT / 2), battle_select_color[4]);
    font.draw("敵　レベル" + std::to_string(enemy.lv), Vec2f(0, HEIGHT / 2 - 100), Color::yellow);
    font.draw("敵　HP" + std::to_string(enemy.hp), Vec2f(0, HEIGHT / 2 - 200), Color::yellow);
    drawTextureBox(200, -200, 500, 500, 0, 0, 256, 256, ene01);
    font.draw(text, Vec2f(-300, -300), Color::yellow);
    font.draw(text2, Vec2f(-300, -400), Color::yellow);
    if (is_win == true){
        drawTextureBox(
            0, 0,
            2048, 1024,
            0,
            (timer / 7) % 2 * 256,
            512, 256,
            win, Color::white,
            0,
            Vec2f(1, 1),
            Vec2f(1048, 512)
            );
    }
    if (is_lose == true){

        drawTextureBox(
            0, 0,
            2048, 1024,
            0,
            (timer / 7) % 2 * 256,
            512, 256,
            lose, Color::white,
            0,
            Vec2f(1, 1),
            Vec2f(1048, 512)
            );
    }
}



void BATTLE::Enemy_turn(Player& player){
    if (enemy.hp > 0){
        if (my_turn == false){
            int dame = rand(enemy.attack, enemy.attack + 50) - playerb.defense * 2;
            if (dame <= 0) dame = 1;
            remaining_hp -= dame;
            text2 = "金山は" + std::to_string(dame ) + "のダメージを受けた";
            cra.play();

        }
        my_turn = true;
    }
    else
    {
        
        text2 = "  ";
    }
}