#include "StatusShop.h"

void StatusShop(Player& player){
    STATUS c;
    c.StatusShop_main(player);
}



void STATUS::StatusShop_main(Player& player){
    bgm.play();
    while (player.place == Place::STATUS_)
    {
        if (!env.isOpen()) exit(0);
        env.begin();

        Update(player);
        Draw(player);
        env.end();
    }

}



void STATUS::Key(){

    if (is_select_up == 0 && is_select_skill == 0){
        if (env.isPushKey('W')){
            text = ' ';
            text2 = ' ';
            select--;
            sele.play();
        }
        if (env.isPushKey('S')){
            text = ' ';
            text2 = ' ';

            select++;
            sele.play();

        }
    }
    if (is_select_up == 1){
        if (env.isPushKey('W')){

            sele.play();
            select_st--;
        }
        if (env.isPushKey('S')){
            sele.play();

            select_st++;
        }
        if (env.isPushKey('A')){
            sele.play();
            is_select_up = 0;
        }
    }
    if (is_select_skill == 1){
        if (env.isPushKey('W')){
            sele.play();

            select_sk--;
        }
        if (env.isPushKey('S')){
            sele.play();

            select_sk++;
        }
        if (env.isPushKey('A')){
            sele.play();
            is_select_skill = 0;
        }
    }



}



void STATUS::Enter(Player& player){
    if (env.isPushKey(GLFW_KEY_ENTER)){
        if (is_select_up == 0 && is_select_skill == 0){

            ok.play();
            switch (select)
            {
            case 0:
                is_select_up = 1;
                break;
            case 1:
                is_select_skill = 1;
                break;
            case 2:
                player.place = WORLD;
                break;
            }
        }
    }
    env.flushInput();
    if (env.isPressKey(GLFW_KEY_ENTER)){
        ++count;
        
        if ((count%7) == 0){
           
            if (is_select_up == 1){

                switch (select_st)
                {
                case 0:
                    if (player.have_money >= player.hp * 50){
                        player.have_money -= (player.hp * 50);
                        player.hp += 10; 
                        get.play();
                        if (player.flag < 2)
                            
                        player.flag = 2;
                    }
                    break;
                case 1:
                    if (player.have_money >= player.attack * 500){
                        player.have_money -= player.attack * 500;
                        player.attack += 1;
                        get.play();
                        if (player.flag < 2)

                        player.flag = 2;
                    }
                    break;
                case 2:
                    if (player.have_money >= player.defense * 500){
                        player.have_money -= player.defense * 500;
                        player.defense += 1;
                        get.play();
                        if (player.flag < 2)

                        player.flag = 2;
                    }
                    break;
                }
            }
            if (is_select_skill == 1){

                switch (select_sk)
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


        }

    }

    if (env.isPullKey(GLFW_KEY_ENTER)){
        count = 0;
    }

}


void STATUS::Font_Color(){
    for (int i = 0; i < 3; i++)
    {
        st_color[i] = Color::white;
        sk_color[i] = Color::white;
        font_color[i] = Color::white;

    }
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
    }
    switch (select_st)
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
    switch (select_sk)
    {
    case 0:
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


void STATUS::Stop(){
    if (select < 0)select = 0;
    if (select > 2)select = 2;
    if (select_st < 0)select_st = 0;
    if (select_st > 2)select_st = 2;
    if (select_sk < 0) select_sk = 0;
    if (select_sk > 2) select_sk = 2;

}


void STATUS::Update(Player& player){

    Key();
    Enter(player);

    Stop();

    Font_Color();


}


void STATUS::Draw(Player& player){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 2048, 1024, bg, Color::white);
    font.size(70);
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2 - 30, 700, 350, 0, 0, 2048, 512, message2);

    font.draw("ステータスを買う▹", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 200), font_color[0]);
    font.draw("技を買う▹", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 100), font_color[1]);
    font.draw("出る", Vec2f(-WIDTH / 2, -HEIGHT / 2), font_color[2]);

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

        font.draw("技名  使用回数  値段", Vec2f(-400, HEIGHT / 2 - 200), Color::cyan);
        font.draw("強攻撃　　 " + std::to_string(player.skill[Skill::heel]) +
            "       " + std::to_string(player.skill[Skill::heel] * 10000 + 10000),
            Vec2f(-400, HEIGHT / 2 - 300), sk_color[0]);
        font.draw("回復　 　 " + std::to_string(player.skill[Skill::strong]) +
            "       " + std::to_string(player.skill[Skill::strong] * 10000 + 10000),
            Vec2f(-400, HEIGHT / 2 - 400), sk_color[1]);
        font.draw("低確率キル" + std::to_string(player.skill[Skill::death]) +
            "       " + std::to_string(player.skill[Skill::death] * 10000 + 10000),
            Vec2f(-400, HEIGHT / 2 - 500), sk_color[2]);

    }
   

}

