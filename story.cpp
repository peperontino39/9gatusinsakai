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
            text1 = "こんばんは";
            text2 = "わしはこの村の村長じゃ";
            break;
        case 2: 
            text1 = "すまないこの村は今";
            text2 = "何もないのじゃ";
            break;
        case 3:
            text1 = "この村は前まではいろんな建物が";
            text2 = "あって栄えていたんじゃが";
            break;
        case 4:
            text1 = "数日前にワニに襲われて";
            text2 = "村は一気に崩壊してもうたのじゃ";
            break;
        case 5:
            text1 = "えっこの村を救ってくれるのか";
            text2 = "本当にありがたいのぉー";
            break;
        case 6:
            text1 = "おぬし名はなんと申す？";
            text2 = "   ";
            break;
        case 7:
            text1 = "そうか金山かぁ";
            text2 = "";
            break;
        case 8:
            text1 = "基本的にWASDとENTERキー";
            text2 = "を使用するのじゃ";
            break;
        case 9:
            text1 = "お金を効率的に稼ぐとステータスを";
            text2 = "上げることができるじゃ";
            break;
        case 10:
            text1 = "10年ごと40年間、強い敵が来るで";
            text2 = "それまでに備えて強くなっておくのじゃ";
            break;
        case 11:
            text1 = "最初はまずわしの家に来て";
            text2 = "お金稼ぎじゃ";
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
    std::string text1 = "いい人生じゃった最後までやってくれて";
    std::string text2 = "本当にありがとうございました";
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