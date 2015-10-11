#include "world.h"

#include <iostream>



map_chip world
{
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 8, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0 },
        { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }

	}
};










//////初期化
void init(Player& player,Tx& tx){
	 
    
    player.pos = Vec2f(-900, -400);
    player.size = Vec2f(100, 100);
    player.vec = Vec2f(0, 0);
    player.is_jump = false;
    player.place = 0;// Place::BATTLE_;
    player.speed = 20;
    player.gravity = 1;
    player.floor_count = 0;
    player.day = 0;
    player.have_money = 200000;
    player.flag = 0;
    player.boss_flag = 0;

    player.tx = Texture("res/hito.png");
    for (int i = 0; i < 3; i++)player.skill[i] = 0;
    
    tx.block = Texture("res/block.png");
    
    tx.spring = Texture("res/haru.png"); 
    tx.summer = Texture("res/natu.png");
    tx.fall = Texture("res/aki.png");
    tx.winter = Texture("res/fuyu.png");
    tx.rt = Texture("res/rt.png");
    tx.Sign = Texture("res/battle.png");
    tx.Village = Texture("res/wark.png");
    tx.bank = Texture("res/bank.png");
    tx.keep_out = Texture("res/keepout.png");
    tx.Shop = Texture("res/shop.png");
    //tx.font = Font("res/meiryo.ttc");
}
/////更新

void ani(Player& player){
    //std::cout << player.ani_count << std::endl;
    drawTextureBox(player.pos.x(), player.pos.y(), player.size.x(), player.size.y(), ((player.ani_count / 6) % 4)*256, 0, 256, 256, player.tx);
}

void update(Player& player, medias& me){

    player.month = ((player.day / 30 + 3)) % 12 + 1;
    player.age = (player.day / 360) + 20;

    if (env.isPressKey('B')){
        player.day++;
        player.have_money+=10000;
    }
    ///チートです
    if (env.isPushKey(GLFW_KEY_1)){
        player.day = 12 * 9 * 30;
        player.have_money = 1000000;
        player.attack = 50;
        player.defense = 100;
        player.hp = 700;
        player.flag = 4;
        player.battle_reaching = 5;
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
    if (env.isPushKey(GLFW_KEY_3)){
        player.day = 39 * 12 * 30;
        player.have_money = 100000000;
        //player.attack = 200;
        player.defense = 200;
        player.hp = 2000;
        player.flag = 5;
        player.battle_reaching = 10;
        player.boss_flag = 3;
        player.attack = 1000;
    }


    if (env.isPushKey('N')){
        player.place = Place::BOSS_;
    }
    //プレイヤーの処理
    if (env.isPressKey('D')){
        player.vec.x() = player.speed;
        player.ani_count++;
    }
    if (env.isPullKey('D')){
        player.vec.x() = 0;
    }
    if (env.isPressKey('A')){
        player.vec.x() = -player.speed;
        player.ani_count++;

    }
    if (env.isPullKey('A')){
        player.vec.x() = 0;
    }

    if (env.isPushKey('W') && player.is_jump == true){
		player.vec.y() = 30;
        player.is_jump = false;
	}
    if (env.isPushKey('S') && player.is_jump == true){
        player.floor_count++;
        player.is_jump = false;
    }
    if (player.floor_count > 0)
        player.floor_count++;
    if (player.floor_count == 20)
        player.floor_count = 0;

    player.pos += player.vec;
    player.vec.y() -= player.gravity;

    if (player.pos.x() < -WIDTH / 2)
        player.pos.x() = -WIDTH / 2;
    if (player.pos.x() > WIDTH / 2 - player.size.x())
        player.pos.x() = WIDTH / 2 - player.size.x();



	for (int  y = 0; y < 16; y++){
		for (int x = 0; x < 32; x++){
			Vec2f block_pos = Vec2f(-1024 + x * 64, 512 -64 - y * 64);

			switch (world.map[y][x])
			{
			case 0:
				break;
			case 1:
                if (hit_floor(player.pos, block_pos, player.vec, player.size, Vec2f(64, 64)))
                    player.is_jump = true;
            case 2:
                not_floor(player, block_pos, Vec2f(64, 64));
				break;
            case 3:
                if (hitting_square(player.pos, block_pos, Vec2f(256, 256)) &&
                    env.isPushKey(GLFW_KEY_ENTER)){
                    if ((player.boss_flag >= 1)){
                        me.bgm.stop();
                        player.place = ROULETTE;
                    }
                }
                break;
            case 4:
                if (hitting_square(player.pos, block_pos, Vec2f(256, 256)) &&
                    env.isPushKey(GLFW_KEY_ENTER)){
                    if ((player.flag >= 2)){
                        player.place = BATTLE_;
                        me.bgm.stop();
                    }
                    //戦闘
                }
                break;
            case 5:
                if (hitting_square(player.pos, block_pos, Vec2f(256, 256)) &&
                    env.isPushKey(GLFW_KEY_ENTER)){
                    if ((player.flag >= 0)){

                        me.bgm.stop();
                        player.place = COMPANY_;
                    }
                    //村長家
                }
                break;
            case 6:
                if (hitting_square(player.pos, block_pos, Vec2f(256, 256)) &&
                    env.isPushKey(GLFW_KEY_ENTER)){
                    
                    if (((player.battle_reaching * 2 - 2) >= 10)){
                        me.bgm.stop();
                        player.place = BANK_;
                    }
                    //銀行
                }
                break;
            case 7:
                if (hitting_square(player.pos, block_pos, Vec2f(256, 256)) &&
                    env.isPushKey(GLFW_KEY_ENTER)){
                    if ((player.flag >= 1)){

                        me.bgm.stop();
                        player.place = STATUS_;
                    }
                    //ステータスショップ
                }

                break;
			}            
		}
	}	
}
///////描画
void draw(Player& player, Tx& tx){
    Texture season;

    if (player.month >= 3 && player.month <= 5)
        season = tx.spring;
    if (player.month >= 6 && player.month <= 8)
        season = tx.summer;
    if (player.month >= 9 && player.month <= 11)
        season = tx.fall;
    if (player.month >= 12 || player.month <= 2)
        season = tx.winter;

    
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 2048, 1024, season);


    for (int y = 0; y < 16; y++){
        for (int x = 0; x < 32; x++){
            Vec2f block_pos = Vec2f(-1024 + x * 64, 512 - 64 - y * 64);

            switch (world.map[y][x])
            {
            case 0:
                break;
            case 1:

               // drawFillBox(block_pos.x(), block_pos.y(), 64, 64, Color::blue);
                drawTextureBox(block_pos.x(), block_pos.y(), 64, 64, 0, 0, 256, 256, tx.block);
                break;
            case 2:

                //drawFillBox(block_pos.x(), block_pos.y(), 64, 64, Color::blue);
                drawTextureBox(block_pos.x(), block_pos.y(), 64, 64, 0, 0, 256, 256, tx.block);
                break;
            case 3:
                //るーーれっとの建物
                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.rt);
                if (!(player.boss_flag >= 1))

                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.keep_out);

                break;
            case 4:
                //ばとるの建物
                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.Sign);
                if(!(player.flag >= 2))
                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.keep_out);

                break;
            case 5:
                //会社の建物(村長宅)
                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.Village);
                if (!(player.flag >= 0))
                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.keep_out);

                break;                
            case 6:
                // 銀行
                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.bank);
                if (!((player.battle_reaching * 2 - 2) >= 10))

                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.keep_out);
                break;
            case 7:
                // 店
                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.Shop);
                if (!(player.flag >= 1))

                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.keep_out);

                break;
            case 8:
                drawTextureBox(block_pos.x(), block_pos.y(), 256, 256, 0, 0, 256, 256, tx.keep_out);

                break;



            }

        }
    }
	////////自機
   /* drawFillBox(player.pos.x(), player.pos.y(),
        player.size.x(), player.size.y(), Color::cyan);*/
    ani(player);

    tx.font.size(70);
    tx.font.draw("　　歳　　月　　日", Vec2f(-WIDTH / 2, HEIGHT / 2 - 100), Color::green);

    tx.font.draw(std::to_string(player.age) + "　　" +
        std::to_string(player.month) + "　　" +
        std::to_string(player.day%30+1), Vec2f(-WIDTH / 2, HEIGHT / 2 - 100), Color::green);
    tx.font.draw("村の発展度　　"+std::to_string(player.battle_reaching*2-2) + '%', Vec2f(-WIDTH / 2, HEIGHT / 2 - 200), Color::green);
    std::string money = std::to_string(player.have_money);
    tx.font.draw(
        "ｶﾈｰ"+
        std::to_string(player.have_money / 1000000000000 %10000) + "兆" +
        std::to_string(player.have_money / 100000000 %10000)+"億"+ 
        std::to_string(player.have_money / 10000 %10000) + "万" + 
        std::to_string(player.have_money % 10000),
        Vec2f(WIDTH / 2-100 - tx.font.drawSize(
        "ｶﾈｰ" +
        std::to_string(player.have_money / 1000000000000 % 10000) + "兆" +
        std::to_string(player.have_money / 100000000 % 10000) + "億" +
        std::to_string(player.have_money / 10000 % 10000) + "万" +
        std::to_string(player.have_money % 10000)
        ).x(),
        HEIGHT / 2 - 100),
        Color::green);
}


void World(int& sceen){
	
	//World world;
	Player player;
    Tx tx;

	init(player, tx);
    medias me;
    me.bgm = Media("res/se/mura.wav");
    me.ok = Media("res/se/kettei_.wav");
    me.bgm.looping(1);
    me.bgm.play();
    while (sceen == 2)
    {
        
        if (!env.isOpen()) exit(0);
        env.begin();

        switch (player.place)
        {
        case WORLD:
            if (!me.bgm.isPlaying())me.bgm.play();
            update(player,me);
            draw(player, tx);
            
            break;
        case ROULETTE:            
            roulette(player);
            break;
        case BATTLE_:
            Battle(player);
            break;
        case COMPANY_:
            Company(player);
            break;
        case BANK_:
            Bank(player);
            break;
        case Place::STATUS_:
            StatusShop(player);
            break;
        case Place::BOSS_ :
            Boss(player,sceen);
            break;
        }        



        env.end();
        
    }
    
}
