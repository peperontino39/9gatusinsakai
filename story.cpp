#include "story.h"

void Story(int& sceen){


    Texture message = Texture("res/mese-ji.png");
    Texture jijii = Texture("res/jijii.png");
    Font font = ("res/meiryo.ttc");
    std::string text1 = "  ";
    std::string text2 = "  ";
    Media ok = Media("res/se/kettei_.wav");
    Media bgm = Media("res/se/sontyou.wav");
    int count = 0;

    bgm.looping(1);
    bgm.play();

    ok.play();
    while (sceen == 1)
    {
        if (!env.isOpen()) exit(0);
        env.begin();

        env.bgColor(Color::black);


        if (env.isPushKey(GLFW_KEY_ENTER)){
            count++;
            ok.play();
            if (count == 12){
                sceen = 2;
            }
        }

        switch (count)
        {
        case 0:
            break;
        case 1:
            text1 = "����΂��";
            text2 = "�킵�͂��̑��̑�������";
            break;
        case 2: 
            text1 = "���܂Ȃ����̑��͍�";
            text2 = "�����Ȃ��̂���";
            break;
        case 3:
            text1 = "���̑��͑O�܂ł͂����Ȍ�����";
            text2 = "�����ĉh���Ă����񂶂Ⴊ";
            break;
        case 4:
            text1 = "�����O�Ƀ��j�ɏP����";
            text2 = "���͈�C�ɕ��󂵂Ă������̂���";
            break;
        case 5:
            text1 = "�������̑����~���Ă����̂�";
            text2 = "�{���ɂ��肪�����̂��[";
            break;
        case 6:
            text1 = "���ʂ����͂Ȃ�Ɛ\���H";
            text2 = "   ";
            break;
        case 7:
            text1 = "���������R����";
            text2 = "";
            break;
        case 8:
            text1 = "��{�I��WASD��ENTER�L�[";
            text2 = "���g�p����̂���";
            break;
        case 9:
            text1 = "�����������I�ɉ҂��ƃX�e�[�^�X��";
            text2 = "�グ�邱�Ƃ��ł��邶��";
            break;
        case 10:
            text1 = "10�N����40�N�ԁA�����G�������";
            text2 = "����܂łɔ����ċ����Ȃ��Ă����̂���";
            break;
        case 11:
            text1 = "�ŏ��͂܂��킵�̉Ƃɗ���";
            text2 = "�����҂�����";
            break;
        

 
        }




        drawTextureBox(-1024, -312, 2048, 1024, 0, 0, 2048, 1024, jijii);
        drawTextureBox(-1024, -512, 2048, 1024, 0, 0, 2048, 1024, message);
        font.size(100);
        font.draw(text1, Vec2f(-900, -300), Color::white);
        font.draw(text2, Vec2f(-900, -400), Color::white);
        font.size(30);
        
        font.draw("PUSH ENTER", Vec2f(WIDTH / 2, -HEIGHT / 2+30) - font.drawSize("PSHU ENTER"), Color::white);



        env.end();
    }
}


void ending(int& sceen){
    
    Texture message = Texture("res/mese-ji.png");
    Texture jijii = Texture("res/jijii.png");
    Texture con = Texture("res/kongura.png");
    Font font = ("res/meiryo.ttc");
    std::string text1 = "�����l����������Ō�܂ł���Ă����";
    std::string text2 = "�{���ɂ��肪�Ƃ��������܂���";
    Media clear = Media ("res/se/clear.wav");
    
    clear.play();
    while (sceen == 3)
    {
    if (!env.isOpen()) exit(0);
        env.begin();
        env.bgColor(Color::black);

        if (env.isPushKey(GLFW_KEY_ENTER)){
            sceen = 0;
        }
        drawTextureBox(-1024, -312, 2048, 1024, 0, 0, 2048, 1024, jijii);
        drawTextureBox(-1024, -512, 2048, 1024, 0, 0, 2048, 1024, message);
        drawTextureBox(-1024, 0, 2048-400, 256-50, 0, 0, 2048, 256, con);
        font.size(100);
        font.draw(text1, Vec2f(-900, -300), Color::white);
        font.draw(text2, Vec2f(-900, -400), Color::white);
        font.size(30);
        

    env.end();
    }
}