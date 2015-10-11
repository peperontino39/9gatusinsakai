#include "Bank.h"




//メインで使う関数
void Bank(Player& player){
    BANK b;
    b.Bank_main(player);
}



void BANK::Bank_main(Player& player){
    
    player.deposit *= (player.day - player.deposit_day)*0.001 + 1;
    bgm.looping(1);
    bgm.play();
    while (player.place == Place::BANK_)
    {
        if (!env.isOpen()) exit(0);
        env.begin();

        Update(player);
        Draw(player);
        env.end();
    }

}



void BANK::Key(){
    //std::cout << (is_select2 == 0 && is_select2 == 0) << std::endl;
    if (is_select2 == 0 && is_select1 == 0){
        if (env.isPushKey('W')){
            text = ' ';
            text2 = ' ';
            select--;
            sele.play();

        }
        if (env.isPushKey('S')){
            text = ' ';
            text2 = ' ';
            sele.play();

            select++;
        }
    }
   // env.flushInput();
    if (is_select2 == 1 || is_select1 == 1){
        //std::cin >> how;
        if (env.isPressKey('W')){
            sele.play();
            increment_amount++;
            if (increment_amount < 50)
                how++;
            else if (increment_amount < 100)
                how+=100;
            else if (increment_amount < 150)
                how += 10000;
            else if (increment_amount < 200)
                how += 1000000;



        }
        if (env.isPressKey('S')){
            increment_amount++;
            sele.play();

            if (increment_amount < 50)
                how--;
            else if (increment_amount < 100)
                how -= 100;
            else if (increment_amount < 150)
                how -= 10000;
            else if (increment_amount < 200)
                how -= 1000000;
        }
        if (env.isPullKey('W') || env.isPullKey('S')){

            increment_amount = 0;
        }
        if (env.isPushKey('A')){
            is_select1 = 0;
            is_select2 = 0;
            how = 0;
        }
    }


}



void BANK::Enter(Player& player){

    if (env.isPushKey(GLFW_KEY_ENTER)){

        if (is_select2 == 0 && is_select1 == 0)
        {
            //std::cout << select << std::endl;
            switch (select)
            {
            case 0:
                ok.play();

                is_select2 = 1;
                break;
            case 1:
                ok.play();

                is_select1 = 1;
                break;
            case 2:
                player.place = Place::WORLD;
                player.deposit_day = player.day;
                ok.play();
                break;
            }
        }
        else if (is_select2 == 1){
            player.have_money -= how;
            player.deposit += how;
            is_select2 = 0;
            how = 0;
            kane.play();
        }
        else if (is_select1 == 1){
            player.have_money += how;
            player.deposit -= how;
            is_select1 = 0;
            how = 0;
            kane.play();
        }
    }

}


void BANK::Font_Color(){
    for (int i = 0; i < 3; i++)
    {
        select_color[i] = Color::white;
        

    }
    switch (select)
    {
    case 0:
        select_color[0] = Color::red;
        break;
    case 1:
        select_color[1] = Color::red;

        break;
    case 2:
        select_color[2] = Color::red;

        break;
    }
    




}


void BANK::Stop(Player& player){
    if (select > 2)select = 2;
    if (select < 0)select = 0;
    if (is_select2 == 1){
        if (how > player.have_money)how = player.have_money;
        if (how < 0)how = 0;
    }
    if (is_select1 == 1){
        if (how > player.deposit)how = player.deposit;
        if (how < 0)how = 0;
    }

}

//処理多数
void BANK::Update(Player& player){

    Key();
    Enter(player);

    Stop(player);

    Font_Color();


}

//描画
void BANK::Draw(Player& player){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 2048, 1024, bg, Color::white);

    font.size(70);
    font.draw("　　歳　　月　　日", Vec2f(-WIDTH / 2, HEIGHT / 2 - 100), Color::black);

    font.draw(std::to_string(player.age = (player.day / 360) + 20
        ) + "　　" +
        std::to_string(player.month = ((player.day / 30 + 3)) % 12 + 1
        ) + "　　" +
        std::to_string(player.day % 30 + 1), Vec2f(-WIDTH / 2, HEIGHT / 2 - 100), Color::white);
    font.draw("村の発展度　　" + std::to_string(player.battle_reaching * 2 - 2) + '%', Vec2f(-WIDTH / 2, HEIGHT / 2 - 200), Color::black);
    font.draw("ｶﾈｰ     " + std::to_string(player.have_money), Vec2f(-WIDTH / 2, HEIGHT / 2 - 300), Color::black);
    font.draw("現在の預金額 " + std::to_string(player.deposit), Vec2f(-WIDTH / 2, HEIGHT / 2 - 400), Color::black);
    

    drawTextureBox(-WIDTH / 2, -HEIGHT / 2 - 30, 500, 350, 0, 0, 2048, 512, message2);

    font.draw("預金する", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 200), select_color[0]);
    font.draw("引き出す", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 100), select_color[1]);
    font.draw("出る", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 000), select_color[2]);

    if (is_select2 == 1){
        drawTextureBox(-100, HEIGHT / 2 - 600, 800, 550, 0, 0, 2048, 512, message2);

        font.draw("いくら預ける？", Vec2f(00, HEIGHT / 2 - 200), Color::cyan);
        font.draw("ｶﾈｰ     " + std::to_string(how), Vec2f(00, HEIGHT / 2 - 300), Color::red);

    }
    if (is_select1 == 1){
        drawTextureBox(-100, HEIGHT / 2 - 600, 800, 550, 0, 0, 2048, 512, message2);

        font.draw("いくら引き出す？", Vec2f(00, HEIGHT / 2 - 200), Color::cyan);
        font.draw("ｶﾈｰ     " + std::to_string(how), Vec2f(00, HEIGHT / 2 - 300), Color::red);

    }
    font.draw(text, Vec2f(-500, -300), Color::cyan);
    font.draw(text2, Vec2f(-500, -200), Color::cyan);



}

