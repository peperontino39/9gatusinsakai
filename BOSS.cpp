#include"BOSS.h"



void Boss(Player& player, int& sceen){
    BOSS b;
    b.main(player,sceen);
}


void BOSS::main(Player& player, int& sceen){
    init(player);
    
    while (player.place == Place::BOSS_&&
        scene == 0)
    {   if (!env.isOpen()) exit(0);
        env.begin();
        if (!bgm2.isPlaying())bgm2.play();
        story();
        env.end();
    }
    while (player.place == Place::BOSS_&&
        scene == 1)
    {       
        if (!env.isOpen()) exit(0);
        env.begin();
        if (!bgm2.isPlaying())bgm2.stop();
        if (!bgm.isPlaying())bgm.play();
        Update(player,sceen);
        Draw(player);
        env.end();
    }
    while (player.place == Place::BOSS_&&
        scene == 2)
    {
        if (!env.isOpen()) exit(0);
        env.begin();
        if (!bgm.isPlaying())bgm.stop();

        if (!bgm2.isPlaying())bgm2.play();

        end(player);
        
        env.end();
    }


}



void BOSS::init(Player& player){
    playera = player;
    remaining_hp = player.hp;   //残りｈｐ
    scene = 0;

    switch (player.boss_flag)
    {
    case 0:
        boss.attack = 100;
        boss.hp = 500;
        boss.tx = Texture("res/gaikotu.png");
        break;
    case 1:
        boss.attack = 100;
        boss.hp = 1000;

        boss.tx = Texture("res/akuma.png");
        break;
    case 2:
        boss.attack = 100;
        boss.hp = 2000;

        boss.tx = Texture("res/syuuketuki.png");
        break;
    case 3:
        boss.attack = 100;
        boss.hp = 3000;

        boss.tx = Texture("res/riza-do.png");
        break;
    }
        
}






void BOSS::Update(Player& player, int& sceen){

    if (is_win == false && is_lose == false){
        for (int i = 0; i < 5; i++)
        {
            battle_select_color[i] = Color::white;
        }


        if (env.isPushKey(GLFW_KEY_2)){
            player.day = 19 * 12 * 30;
            player.have_money = 1000000;
            player.place = Place::WORLD;
            player.attack = 200;
            player.defense = 200;
            player.hp = 2000;
            player.flag = 5;
            player.battle_reaching = 20;
            player.boss_flag = 1;
        }

        if (env.isPushKey('W')){
            battle_select--;
        }
        if (env.isPushKey('S')){
            battle_select++;


        }
        if (env.isPushKey(GLFW_KEY_ENTER)){
            if (my_turn == true){
                switch (battle_select)
                {
                case 0:
                    atk = rand(playera.attack - 4, playera.attack + 50);
                    boss.hp -= atk;
                    text = "金山は" + std::to_string(atk) + "のダメージを与えた";
                    my_turn = false;
                    cra.play();
                    break;
                case 1:
                    if (playera.skill[0] > 0){
                        atk = rand(playera.attack * 3 - 4, playera.attack * 3 + 50);
                        boss.hp -= atk;
                        text = "金山は" + std::to_string(atk) + "のダメージを与えた";
                        my_turn = false;
                        playera.skill[0]--;
                        cra.play();
                    }

                    break;
                case 2:
                    if (playera.skill[1] > 0){

                        remaining_hp += playera.hp / 2;
                        text = "金山は" + std::to_string(playera.hp / 2) + "の回復した";
                        my_turn = false;
                        playera.skill[1]--;
                        cra.play();
                    }
                    break;
                case 3:
                    if (playera.skill[2] > 0){

                        if (Probability(5)){
                            boss.hp = 0;
                            text = "金山は低確率キルに成功した";
                            my_turn = false;
                            playera.skill[2]--;
                            cra.play();

                        }

                        else
                        {


                            text = "金山は低確率キルに失敗した";
                            my_turn = false;
                            playera.skill[2]--;

                            cra.play();
                        }
                    }
                    break;
                case 4:
                   
                        text = "逃げれない";
                        text2 = ' ';

                    break;

                }
            }
        }


        if (remaining_hp > playera.hp)
            remaining_hp = playera.hp;





        if (boss.hp < 0)
            boss.hp = 0;

        if (remaining_hp < 0)
            remaining_hp = 0;

        if (boss.hp>0)
            Enemy_turn(playera);



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



        if (boss.hp == 0){
            is_win = 1; timer = 0;
            
        }
        if (remaining_hp == 0){
            is_lose = 1; timer = 0;
            
        }
    }
    timer++;
    if (is_lose == 1 || is_win == 1)
    {
        if (timer == 100){
            if (is_lose == 1){
                sceen = 0;

                player.place = Place::WORLD;
            }
            my_turn = true;
            if (is_win == 1){
                bgm.stop();
                scene = 2;
                count = 0;
                stext1 = "よくやった";
                stext2 = "また１０年後に備えて頑張るのじゃ";
                if (player.boss_flag == 3){
                    player.place = Place::WORLD;
                    sceen = 3;
                }
            }
        }
    }
}
void BOSS::Draw(Player& player){

    font.size(70);
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 2048, 1024, bg, Color::white);
    font.draw("HP      " + std::to_string(remaining_hp) + " / " + std::to_string(player.hp), Vec2f(-WIDTH / 2, HEIGHT / 2 - 100), Color::black);
    font.draw("攻撃力 " + std::to_string(player.attack), Vec2f(-WIDTH / 2, HEIGHT / 2 - 200), Color::black);
    font.draw("防御力 " + std::to_string(player.defense), Vec2f(-WIDTH / 2, HEIGHT / 2 - 300), Color::black);

    drawTextureBox(-WIDTH / 2, -HEIGHT / 2 - 30, 700, 550, 0, 0, 2048, 512, message2);
    drawTextureBox(-200, HEIGHT / 2 - 300, 700, 300, 0, 0, 2048, 512, message2);
    drawTextureBox(-350, -500, 1300, 300, 0, 0, 2048, 512, message2);

    font.draw("通常攻撃", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 400), battle_select_color[0]);
    font.draw("強攻撃     [" + std::to_string(playera.skill[0]) + "]", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 300), battle_select_color[1]);
    font.draw("回復       [" + std::to_string(playera.skill[1]) + "]", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 200), battle_select_color[2]);
    font.draw("低確率キル  [" + std::to_string(playera.skill[2]) + "]", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 100), battle_select_color[3]);
    font.draw("逃げる", Vec2f(-WIDTH / 2, -HEIGHT / 2), battle_select_color[4]);
    //font.draw("敵　レベル" + std::to_string(boss.lv), Vec2f(0, HEIGHT / 2 - 100), Color::yellow);
    font.draw("BOSS　HP" + std::to_string(boss.hp), Vec2f(-200, HEIGHT / 2 - 200), Color::yellow);
    drawTextureBox(200, -200, 500, 500, 0, 0, 1024, 1024, boss.tx);
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
bool BOSS::Probability(float probability){

    int a = rand(0.0f, 100.0f);
    
    if (a <= probability){
        return 1;
    }
    else
    {
        return 0;
    }

}
void BOSS::Enemy_turn(Player& player){
    if (boss.hp > 0){
        if (my_turn == false){
            int dame = rand(boss.attack, boss.attack + 50) - playera.defense * 5;
            if (dame <= 0) dame = 1;
            remaining_hp -= dame;
            text2 = "金山は" + std::to_string(dame) + "のダメージを受けた";
        }
        my_turn = true;
    }
    else
    {

        text2 = "  ";
    }
}



void BOSS::story(){
    if (env.isPushKey(GLFW_KEY_ENTER)){
        count++;



        switch (count)
        {
        case 0:
            break;
        case 1:
            stext1 = "あれから10年たったのぉ";
            stext2 = "ついに決戦じゃ";
            break;
        case 2:
            stext1 = "１０年の成果を出し切るのじゃ";
            stext2 = "ボスの戦闘は逃げられない";
            break;
        case 3:
            stext1 = "しかも低確率キルが効きにくい";
            stext2 = "もしこの戦いで負けると死んでしまうと";
            break;
        case 4:
            stext1 = "村ごとなくなってしまうのじゃ";
            stext2 = "気を付けるのじゃよ";
            break;

        case 5:
            scene = 1;
            bgm2.stop();
            break;


        }
    }
    drawTextureBox(-1024, -312, 2048, 1024, 0, 0, 2048, 1024, jijii);
    drawTextureBox(-1024, -512, 2048, 1024, 0, 0, 2048, 1024, message);
    font.size(100);
    font.draw(stext1, Vec2f(-900, -300), Color::white);
    font.draw(stext2, Vec2f(-900, -400), Color::white);
    font.size(30);

    font.draw("PSHU ENTER", Vec2f(WIDTH / 2, -HEIGHT / 2 + 30) - font.drawSize("PSHU ENTER"), Color::white);

}void BOSS::end(Player& player){
    if (env.isPushKey(GLFW_KEY_ENTER)){
        count++;
        player.boss_flag++;
        player.place = Place::WORLD;


        switch (count)
        {
        case 0:
            break;
        case 1:
            
            break;

        case 2:
            
            break;


        }
    }
    drawTextureBox(-1024, -312, 2048, 1024, 0, 0, 2048, 1024, jijii);
    drawTextureBox(-1024, -512, 2048, 1024, 0, 0, 2048, 1024, message);
    font.size(100);
    font.draw(stext1, Vec2f(-900, -300), Color::white);
    font.draw(stext2, Vec2f(-900, -400), Color::white);
    font.size(30);

    font.draw("PSHU ENTER", Vec2f(WIDTH / 2, -HEIGHT / 2 + 30) - font.drawSize("PSHU ENTER"), Color::white);

}