#include "Title.h"

void Title(int& sceen){
    Texture bg = Texture("res/title_bg.png");
    Texture rogo = Texture("res/title_rogo.png");
    Media bgm = Media("res/se/title.wav");
    bgm.looping(1);
    float count = 0;

    bgm.play();
    while (sceen == 0)
    {
        if (!env.isOpen()) exit(0);
        env.begin();

        count += 0.05;
        //std::cout << (count) << std::endl;
        
        drawTextureBox(-1024, -512, 2048, 1024, 0, 0, 2048, 1024, bg);
        drawTextureBox(-1024, -512, 2048, 1024, 0, 0, 2048, 1024, rogo, Color(1, 1, 1, std::abs( sin(count))));
        if (env.isPushKey(GLFW_KEY_ENTER)){
            
            bgm.stop();
            sceen = 1;
            
        }



        env.end();
    }
}