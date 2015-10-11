#include "company.h"





void Company(Player& player){
    COMPANY c;
    c.Company_main(player);
}



void COMPANY::Company_main(Player& player){
    bgm.looping(1);
    bgm.play();
    while (player.place == Place::COMPANY_)
    {
        if (!env.isOpen()) exit(0);
        env.begin();

        Update(player);
        Draw(player);
        env.end();
    }

}



void COMPANY::Key(){

    if (is_select2 == 0){
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
    if (is_select2 == 1){
        if (env.isPushKey('W')){

            select2--;
            sele.play();
        }
        if (env.isPushKey('S')){
            sele.play();
            select2++;
        }
        if (env.isPushKey('A')){
            is_select2 = 0; 
            sele.play();
        }
    }

    
}



void COMPANY::Enter(Player& player){

    if (env.isPushKey(GLFW_KEY_ENTER)){
        if (is_select2 == 0){
            ok.play();
            //std::cout << select << std::endl;
            switch (select)
            {
            case 0:
                is_select2 = true;
                break;
            case 1:
                switch (rand(0,19))
                {
                case 0:
                    text = "100�ʍ���Ă�";
                    break;

                case 1:
                    text = "���E���o�O���Ă��ł�";

                    break;
                case 2:
                    text = "���w���Ȃ�Đl�Ԃ���Ȃ��ł���";
                    break;
                case 3:
                    text = "�������Ȃ��ł����������Ԃ̖��ʂł�";
                    break;
                case 4:
                    text = "���W�x��������Ɠ����̌����������ł���";

                    break;

                case 5:
                    text = "�X�̊O�Ń����X�^�[��|���Ɣ��W�x���オ���";

                    break;

                case 6:
                    text = "WASD��ENTER�̃L�[�����g����";

                    break;

                case 7:
                    text = "���̃Q�[�����X�}�E�X�g�����";

                    break;

                case 8:
                    text = "60�΂܂ł����Ƃ����Ԃ���";

                    break;

                case 9:
                    text = "���b�z�[�C";

                    break;

                case 10:
                    text = "�Ƃ肠�������W�x���グ�悤";

                    break;

                case 11:
                    text = "���܂����܂�������";

                    break;
                case 12:
                    text = "OS�͐_����Ȃ���Ȃ�Ȃ���ł�";

                    break;
                case 13:
                    text = "���W�x���P�O���ȏ�ɂ���ƁE�E�E";

                    break;
                case 14:
                    text = "��s�ŗa������Ɨ��q���t����";

                    break;

                case 15:
                    text = "���̑O���[���b�g�ō��Y�n�����Ă��܂���";

                    break;


                case 16:
                    text = "�퓬�Ŏ��ʂƈꂩ�������Ȃ��Ȃ邼";

                    break;

                case 17:
                    text = "���[���b�g��1������������Ȃ����";

                    break;

                case 18:
                    text = "�{�X�ŕ�����ƊX����ł��Ă��܂�";

                    break;

                case 19:
                    text = "�l�̓R�[�h�͑S���ǂ�ł��ݎ���Ă���";

                    break;








                }


                text2 = "����";




               
                break;
            case 2:
                player.place = Place::WORLD;
                
                break;
            }
        }
        else{
            
            switch (select2)
            {
            case 0:
                player.have_money += player.battle_reaching * 5000;
                player.day += 30;
                get.play();
                if (player.flag < 1)
                player.flag = 1;
                if (player.day >(player.boss_flag + 1) * 10 * 12 * 30){
                    player.place = BOSS_;
                    bgm.stop();
                }
                break;
            case 1:
                player.have_money += player.battle_reaching * 20000;
                player.day += 90;
                get.play();
                if (player.flag < 1)
                player.flag = 1;
                if (player.day >(player.boss_flag + 1) * 10 * 12 * 30){
                    player.place = BOSS_;
                    bgm.stop();
                }
                break;
            case 2:
                player.have_money += player.battle_reaching * 50000;
                player.day += 180;
                get.play();
                if (player.flag < 1)
                player.flag = 1;
                if (player.day >(player.boss_flag + 1) * 10 * 12 * 30){
                    player.place = BOSS_;
                    bgm.stop();
                }
                break;
            }


        }
    }

}


void COMPANY::Font_Color(){
    for (int i = 0; i < 3; i++)
    {
        select_color[i] = Color::white;
        select2_color[i] = Color::white;

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
    switch (select2)
    {
    case 0:
        select2_color[0] = Color::red;
        break;
    case 1:
        select2_color[1] = Color::red;

        break;
    case 2:
        select2_color[2] = Color::red;

        break;
    }




}


void COMPANY::Stop(){
    if (select > 2)select = 2;
    if (select < 0)select = 0;
    if (select2 > 2)select2 = 2;
    if (select2 <0)select2 = 0;

}


void COMPANY::Update(Player& player){

    Key();
    Enter(player);
   
    Stop();

    Font_Color();


}


void COMPANY::Draw(Player& player){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 2048, 1024, bg, Color::white);
    drawTextureBox(-1024, -312, 2048, 1024, 0, 0, 2048, 1024, jijii);
    drawTextureBox(-550, -550, 2000 - 400, 400, 0, 0, 2048, 512, message2);
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2 -30, 500, 350, 0, 0, 2048, 512, message2);

    
    font.size(70);
    font.draw("�@�@�΁@�@���@�@��", Vec2f(-WIDTH / 2, HEIGHT / 2 - 100), Color::black);

    font.draw(std::to_string(player.age = (player.day / 360) + 20
    ) + "�@�@" +
        std::to_string(player.month = ((player.day / 30 + 3)) % 12 + 1
    ) + "�@�@" +
        std::to_string(player.day % 30 + 1), Vec2f(-WIDTH / 2, HEIGHT / 2 - 100), Color::black);
    font.draw("���̔��W�x�@�@" + std::to_string(player.battle_reaching * 2 - 2) + '%', Vec2f(-WIDTH / 2, HEIGHT / 2 - 200), Color::black);
    font.draw("�Ȱ     " + std::to_string(player.have_money), Vec2f(-WIDTH / 2, HEIGHT / 2 - 300), Color::black);

    font.draw("����", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 200), select_color[0]);
    font.draw("�����Ƙb������", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 100), select_color[1]);
    font.draw("�o��", Vec2f(-WIDTH / 2, -HEIGHT / 2 + 000), select_color[2]);

    if (is_select2 == 1){
        drawTextureBox(-300, HEIGHT / 2 - 600, 800, 550, 0, 0, 2048, 512, message2);

        font.draw("����               �҂���Ȱ ", Vec2f(-300, HEIGHT / 2 - 200), Color::cyan);
        font.draw("�P��������     " +  std::to_string(player.battle_reaching * 5000 ), Vec2f(-300, HEIGHT / 2 - 300), select2_color[0]);
        font.draw("�R��������     " + std::to_string(player.battle_reaching * 20000), Vec2f(-300, HEIGHT / 2 - 400), select2_color[1]);
        font.draw("�U��������     " + std::to_string(player.battle_reaching * 50000), Vec2f(-300, HEIGHT / 2 - 500), select2_color[2]);

    }
    font.draw(text, Vec2f(-500, -300), Color::cyan);
    font.draw(text2, Vec2f(-500, -230), Color::cyan);
    


}

