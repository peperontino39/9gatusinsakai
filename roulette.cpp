

#include "roulette.h"
//#include "lib/framework.hpp"
#include <iostream>
#include  <string>
#include <ctime>

//using namespace std;



//�`�b�v��`��
void tip_draw(Vec2f pos, int bet_number, Texture tip, Font font){
	if (bet_number > 0){
		drawTextureBox(
			pos.x(), pos.y(),
			60, 60,
			0, 0,
			64, 64,
			tip, Color::white,
			0, Vec2f(1, 1), Vec2f(30, 30));
		font.size(30);
		font.draw(
			std::to_string(bet_number),
			pos - font.drawSize(std::to_string(bet_number)) / 2,
			Color::cyan);
	}
}

//���[���b�g�{��
void roulette(Player& player){



	Random rand;
	rand.setSeed(time(nullptr));
	Font font("res/meiryo.ttc");
	env.bgColor(color256(38, 85, 15));

	//�摜�̒�`
	Texture roulette("res/ru-retto.png");
	Texture table("res/table.png");
	Texture tip("res/tip.png");
	Texture win("res/win.png");
	Texture lose("res/lose.png");
	Texture zero("res/zero.png");
    Media bgm = Media("res/se/kajino.wav");
    Media ok = Media("res/se/kettei_.wav");
    bgm.looping(1);
	//���[���b�g�̕ϐ�
	Vec2f roulette_position = Vec2f(-800, 0);   //�ʒu
	int roulette_size = 512;                  //�傫��
	float roulette_angle = rand(0, 370);                  //�p�x 0~370
	float roulette_angle_vector = 0;           //��]�x�N�g��
    Media clear = Media("res/se/clear.wav");

  

	int number_call[37]{
		32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26, 0
	};
	Color r, b;
	r = Color::red;
	b = Color::black;
	Color color_call[37]{
		r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, r, b, Color::green
	};
	int number_fixed = 0;
	Color color_fixed;

	enum SCENE{
		BET,
		ROTATE,
		CHECKOUT,

	};
	Vec2f table_position = Vec2f(-590, -200);
	Vec2f table_size = Vec2f(1600, 700);

	int order_bet[138];
	for (int i = 0; i < 138; i++){ order_bet[i] = 0; }
	int special_bet[13];//0=0,1~3=�E,4~6=��,7~12=��2
	for (int i = 0; i < 13; i++){ special_bet[i] = 0; }
	//int input_bet = 1;

	int number_passing = 1;
	//Vec2f passing_pos;

	int have_tip = player.have_money/10000;
	int sum_bet;

	int roulette_scene = BET;
	int get_tip;
	bool is_rotate_one_times = false;

	int animation_counter = 0;

	int order_bet_memory[138];
	for (int i = 0; i < 138; i++){ order_bet_memory[i] = 0; }
	int special_bet_memory[13];
	for (int i = 0; i < 13; i++){ special_bet_memory[i] = 0; }

	int memory_sum;


    bgm.play();
	while (player.place == ROULETTE) {
		if (!env.isOpen()) exit(0);
		env.begin();
        env.mouseCursor(false);

		Vec2f mouse = env.mousePosition();

		/////��]�͂���
		if (hitting_square(mouse, Vec2f(700, -450), Vec2f(200, 200)) &&
			env.isPushButton(Mouse::LEFT) && roulette_scene == BET){
			roulette_scene = ROTATE;
			is_rotate_one_times = true;
			roulette_angle_vector = rand(3.0f, 5.0f);
            ok.play();
		}
        //��]�{�^���̕`��
		drawFillBox(700, -450, 200, 200, Color::cyan);
		font.size(100);
		font.draw("��]", Vec2f(800, -350) - font.drawSize("��]") / 2, Color::black);
		////��]���̏����@����
		if (roulette_angle_vector > 0){
			roulette_angle_vector -= 0.01f; //

		}
		////��]���~�܂������̏���
		if (roulette_angle_vector <= 0){
			if (is_rotate_one_times == true){
				roulette_scene = CHECKOUT;
			}

			roulette_angle_vector = 0;

			for (int i = 0; i < 37; i++){
				if (i * 10 + 5 <= roulette_angle  && roulette_angle < i * 10 + 15){
                    //�m�肵���ԍ�������[��
					number_fixed = number_call[i];
					color_fixed = color_call[i];

				}
			}


		}
		////��]�̂���h�~
		if (roulette_angle > 369){
			roulette_angle = 0;
		}




		//���Z�b�g

		if (hitting_square(mouse, Vec2f(0 - 300, -450), Vec2f(200, 100)) &&
			env.isPushButton(Mouse::LEFT) && roulette_scene == BET){
			for (int i = 0; i < 138; i++){ order_bet[i] = 0; }
			for (int i = 0; i < 13; i++){ special_bet[i] = 0; }
		}
        //���Z�b�g�{�^���̕`��
		drawFillBox(0 - 300, -450, 200, 100, Color::cyan);
		font.size(40);
		font.draw("���Z�b�g", Vec2f(-200, -400) - font.drawSize("���Z�b�g") / 2, Color::black);




		roulette_angle += roulette_angle_vector;
		//////�O�p�ƃ��[���b�g�̕`��
		drawFillTriangle(
			roulette_position.x(),
			(roulette_position.y() + roulette_size / 2) - 55,
			roulette_position.x() + 50,
			(roulette_position.y() + roulette_size / 2) + 100,
			roulette_position.x() - 50,
			(roulette_position.y() + roulette_size / 2) + 100,
			Color::cyan);
		drawTextureBox(
			roulette_position.x(), roulette_position.y(),
			roulette_size, roulette_size,
			0, 0,
			1024, 1024,
			roulette,
			Color::white,
			(roulette_angle - 0.5f) * 2 * M_PI / 370,
			Vec2f(1.0f, 1.0f),
			Vec2f(roulette_size / 2,
			roulette_size / 2));

        //�@��]���Ƃ܂����炻�̔ԍ����т傤��
		if (roulette_angle_vector == 0){
			font.size(100);
			drawFillCircle(roulette_position.x(), roulette_position.y(), 100, 50, 100, color_fixed);
			font.draw(std::to_string(number_fixed), roulette_position - font.drawSize(std::to_string(number_fixed)) / 2, Color::white);
		}

        //�e�[�u���̕`��
		drawTextureBox(
			table_position.x(),
			table_position.y(),
			//	mouse.x(), mouse.y(),

			table_size.x(),
			table_size.y(),
			336, 0,
			1367, 512,
			table,
			Color::white,
			0,
			Vec2f(1, 1),
			Vec2f(0, 0)  //table_size.x() / 2, table_size.y() / 2)
			);
        //�Ĕz�u�{�^���̕`��
		drawFillBox(550, -300, 130, 100, Color::cyan);
		font.size(40);
		font.draw("�Ĕz�u", Vec2f(550, -270), Color::black);
		//�Ĕz�u�̑��
        memory_sum = 0;
		for (int i = 0; i < 138; i++)
			memory_sum += order_bet_memory[i];
		for (int i = 0; i < 13; i++)
			memory_sum += special_bet_memory[i];


        //�Ĕz�u�̑����
        //�`��̌�ɂȂ��Ă��܂���
		if (hitting_square(mouse, Vec2f(550, -300), Vec2f(130, 100)) &&
			roulette_scene == BET &&
			env.isPushButton(Mouse::LEFT) && memory_sum <= have_tip){
			for (int i = 0; i < 138; i++){
				order_bet[i] = order_bet_memory[i];
			}
			for (int i = 0; i < 13; i++){
				special_bet[i] = special_bet_memory[i];
			}

		}

        //�O�ɏo��Ƃ��̏����ƕ`��

        drawFillBox(-1000, 370,  70, 60, Color::cyan);
        font.size(30);
        font.draw("�o��", Vec2f(-1000+35,370+30 )-font.drawSize("�o��")/2, Color::black);
        if (roulette_scene == BET&&
            hitting_square(mouse,Vec2f(-1000,370),Vec2f(70,60))&&
            env.isPushButton(Mouse::LEFT)){
            player.place = WORLD;
            player.have_money = ((have_tip * 10000) + (player.have_money % 10000));

        }


        
        //bat�̏������K�v
        //�ɗ�for���g���ĒZ�����Ă݂��


		//1~36
		for (int j = 0; j < 6; j++){
			for (int i = 0; i < 23; i++){

				if (hitting_square(
					mouse,
					Vec2f(table_position.x() + 200 + i * 55 - 30,
					table_position.y() + 640 - j * 67 - 30),
					Vec2f(55, 67)
					) &&
					env.isPushButton(Mouse::LEFT) && roulette_scene == BET && number_passing + sum_bet <= have_tip
					)
					order_bet[j * 23 + i] += number_passing;

				tip_draw(Vec2f(table_position.x() + 200 + i * 55,
					table_position.y() + 640 - j * 67),
					order_bet[j * 23 + i], tip, font);

			}
		}

		//�O
		if (hitting_square(
			mouse,
			Vec2f(table_position.x(), table_position.y() + 250),
			Vec2f(140, 390)) &&
			env.isPushButton(Mouse::LEFT) && roulette_scene == BET && number_passing + sum_bet <= have_tip
			)
			special_bet[0] += number_passing;

		tip_draw(Vec2f(table_position.x() + 140 / 2,
			table_position.y() + 250 + 390 / 2),
			special_bet[0], tip, font);


		//�E��3��
		for (int i = 0; i < 3; i++){
			if (hitting_square(
				mouse,
				Vec2f(table_position.x() + 1470, table_position.y() + 510 - i * 130),
				Vec2f(120, 130)) &&
				env.isPushButton(Mouse::LEFT) && roulette_scene == BET && number_passing + sum_bet <= have_tip
				)
				special_bet[i + 1] += number_passing;
			tip_draw(Vec2f(table_position.x() + 1470 + 120 / 2,
				table_position.y() + 510 - i * 130 + 130 / 2),
				special_bet[i + 1], tip, font);

			//����3��
			if (hitting_square(
				mouse,
				Vec2f(table_position.x() + 145 + i * 442, table_position.y() + 140),
				Vec2f(442, 105)) &&
				env.isPushButton(Mouse::LEFT) && roulette_scene == BET && number_passing + sum_bet <= have_tip
				)
				special_bet[i + 4] += number_passing;

			tip_draw(Vec2f(table_position.x() + 145 + i * 442 + 442 / 2,
				table_position.y() + 140 + 105 / 2),
				special_bet[i + 4], tip, font);

			for (int j = 0; j < 2; j++){
				//��ԉ�
				if (hitting_square(
					mouse,
					Vec2f(table_position.x() + 145 + i * 221 + j * 663, table_position.y() + 20),
					Vec2f(221, 120)) &&
					env.isPushButton(Mouse::LEFT) && roulette_scene == BET && number_passing + sum_bet <= have_tip
					)
					special_bet[j * 3 + i + 7] += number_passing;
				tip_draw(Vec2f(table_position.x() + 145 + i * 221 + j * 663 + 221 / 2,
					table_position.y() + 20 + 120 / 2),
					special_bet[j * 3 + i + 7], tip, font);

			}
		}
		//�n�����ݒ�
		for (int i = 0; i < 8; i++){
			tip_draw(Vec2f(i * 72, -400),
				((i % 2 == 1) * 4 + 1)*(pow(10, i / 2))  //pow�Ƃ́E�E�E�ݏ�v�Z�A�E���̈����͎w����\���Ă���
				, tip, font);
			if (hitting_square(mouse, Vec2f(i * 72 - 30, -400 - 30), Vec2f(60, 60)) &&
				env.isPushButton(Mouse::LEFT) && roulette_scene == BET){
				number_passing = ((i % 2 == 1) * 4 + 1)*(pow(10, i / 2));
			};
			if (number_passing == ((i % 2 == 1) * 4 + 1)*(pow(10, i / 2))){
				drawBox(i * 72 - 30 - 5, -400 - 30 - 5, 70, 70, 5, Color::cyan);
				drawFillBox(i * 72 - 30 - 5, -400 - 30 - 5 + 70, 70, 70 / 3, Color::cyan);
				font.size(70 / 3);
				font.draw("�q����", Vec2f(i * 72 - 30 - 5, -400 - 30 - 5 + 70), Color::black);
			}
		}
        //�S�z�̌v�Z
        //�����������牽����v�Z���Ă����ŏd���Ȃ邩������Ȃ�

		sum_bet = 0;
		for (int i = 0; i < 138; i++)
			sum_bet += order_bet[i];
		for (int i = 0; i < 13; i++)
			sum_bet += special_bet[i];
		font.size(100);
		font.draw("���z", Vec2f(-300, -300), Color::black);
		font.draw(std::to_string(sum_bet), Vec2f(500 - font.drawSize(std::to_string(sum_bet)).x(), -300), Color::black);
		font.size(50);
		font.draw("����", Vec2f(-1024, 450), Color::black);
		font.draw(std::to_string(have_tip), Vec2f(-600 - font.drawSize(std::to_string(have_tip)).x(), 450), Color::black);



        //�ق��`�`�`���ł���Ȃ��Ƃ�orz
		//	font.size(100);
		//	font.draw(std::to_string(number_fixed), Vec2f(-700, -200), color_fixed);
		/*font.draw(std::to_string(mouse.x()), Vec2f(-700, -200 + 100), color_fixed);
		font.draw(std::to_string(mouse.y()), Vec2f(-700, -200 + 200), color_fixed);
*/
		/*std::cout << roulette_scene << std::endl;
		std::cout << number_fixed << std::endl;
*/

        //���������bet�ɑ΂��Ă̔{���̍�ƂɂȂ邩������Ȃ�
        //for���ł��΂����I���̂ł͂�

		if (roulette_scene == CHECKOUT){
			get_tip = 0;
			if (number_fixed == 0){
				get_tip += special_bet[0] * 36;

			}





			for (int i = 1; i <= 36; i++){
				if (number_fixed == i){
					get_tip +=
						order_bet[(i + 1) / 3 * 2] * 12 +  //3�_�q��
						special_bet[((36 - i) % 3) + 1] * 3 + // ��s
						special_bet[((i - 1) / 12) + 4] * 3 + //�@�㒆��
						special_bet[(i >= 19) * 5 + 7] * 2 + //�@�㉺7,12
						special_bet[((i % 2) * 3 + 8)] * 2 //�@�����8,11
						;
				}
			}
			//6�_�q��
			for (int i = 0; i < 11; i++){
				if (number_fixed >= i * 3 + 1 &&
					number_fixed <= i * 3 + 6)
				{
					get_tip +=
						order_bet[i * 2 + 1] * 6;
				}
			}
            ///�����[
            //1�_2�_4�_��for���łł��Ȃ����Ȃ�
            //�l���Ă鎞�Ԃ����������Ȃ��̂łƂ肠������������Ă�����
            //���̂����K�����ɋC�Â��Ďv�������낤


			if (number_fixed == 1){
				get_tip +=

					order_bet[92] * 18 +
					order_bet[93] * 9 +
					order_bet[115] * 36 +
					order_bet[116] * 18
					;
			}
			if (number_fixed == 2){
				get_tip +=
					order_bet[46] * 18 +
					order_bet[47] * 9 +
					order_bet[69] * 36 +
					order_bet[70] * 18 +
					order_bet[92] * 18 +
					order_bet[93] * 9
					;
			}
			if (number_fixed == 3){
				get_tip +=

					order_bet[23] * 36 +
					order_bet[24] * 18 +
					order_bet[46] * 18 +
					order_bet[47] * 9
					;
			}
			if (number_fixed == 4){
				get_tip +=
					order_bet[93] * 9 +
					order_bet[94] * 18 +
					order_bet[95] * 9 +
					order_bet[116] * 18 +
					order_bet[117] * 36 +
					order_bet[118] * 18
					;
			}

			if (number_fixed == 5){
				get_tip +=
					order_bet[47] * 9 +
					order_bet[48] * 18 +
					order_bet[49] * 9 +
					order_bet[70] * 18 +
					order_bet[71] * 36 +
					order_bet[72] * 18 +
					order_bet[93] * 9 +
					order_bet[94] * 18 +
					order_bet[95] * 9
					;
			}

			if (number_fixed == 6){
				get_tip +=

					order_bet[24] * 18 +
					order_bet[25] * 36 +
					order_bet[26] * 18 +
					order_bet[47] * 9 +
					order_bet[48] * 18 +
					order_bet[49] * 9
					;
			}
			if (number_fixed == 7){
				get_tip +=
					order_bet[95] * 9 +
					order_bet[96] * 18 +
					order_bet[97] * 9 +
					order_bet[118] * 18 +
					order_bet[119] * 36 +
					order_bet[120] * 18
					;
			}


			if (number_fixed == 8){
				get_tip +=
					order_bet[49] * 9 +
					order_bet[50] * 18 +
					order_bet[51] * 9 +
					order_bet[72] * 18 +
					order_bet[73] * 36 +
					order_bet[74] * 18 +
					order_bet[95] * 9 +
					order_bet[96] * 18 +
					order_bet[97] * 9
					;
			}

			if (number_fixed == 9){
				get_tip +=

					order_bet[26] * 18 +
					order_bet[27] * 36 +
					order_bet[28] * 18 +
					order_bet[49] * 9 +
					order_bet[50] * 18 +
					order_bet[51] * 9
					;
			}
			if (number_fixed == 10){
				get_tip +=
					order_bet[97] * 9 +
					order_bet[98] * 18 +
					order_bet[99] * 9 +
					order_bet[120] * 18 +
					order_bet[121] * 36 +
					order_bet[122] * 18
					;
			}


			if (number_fixed == 11){
				get_tip +=
					order_bet[51] * 9 +
					order_bet[52] * 18 +
					order_bet[53] * 9 +
					order_bet[74] * 18 +
					order_bet[75] * 36 +
					order_bet[76] * 18 +
					order_bet[97] * 9 +
					order_bet[98] * 18 +
					order_bet[99] * 9
					;
			}

			if (number_fixed == 12){
				get_tip +=

					order_bet[28] * 18 +
					order_bet[29] * 36 +
					order_bet[30] * 18 +
					order_bet[51] * 9 +
					order_bet[52] * 18 +
					order_bet[53] * 9
					;
			}
			if (number_fixed == 13){
				get_tip +=
					order_bet[99] * 9 +
					order_bet[100] * 18 +
					order_bet[101] * 9 +
					order_bet[122] * 18 +
					order_bet[123] * 36 +
					order_bet[124] * 18
					;
			}


			if (number_fixed == 14){
				get_tip +=
					order_bet[53] * 9 +
					order_bet[54] * 18 +
					order_bet[55] * 9 +
					order_bet[76] * 18 +
					order_bet[77] * 36 +
					order_bet[78] * 18 +
					order_bet[99] * 9 +
					order_bet[100] * 18 +
					order_bet[101] * 9
					;
			}

			if (number_fixed == 15){
				get_tip +=

					order_bet[30] * 18 +
					order_bet[31] * 36 +
					order_bet[32] * 18 +
					order_bet[53] * 9 +
					order_bet[54] * 18 +
					order_bet[55] * 9
					;
			}
			if (number_fixed == 16){
				get_tip +=
					order_bet[101] * 9 +
					order_bet[102] * 18 +
					order_bet[103] * 9 +
					order_bet[124] * 18 +
					order_bet[125] * 36 +
					order_bet[126] * 18
					;
			}


			if (number_fixed == 17){
				get_tip +=
					order_bet[55] * 9 +
					order_bet[56] * 18 +
					order_bet[57] * 9 +
					order_bet[78] * 18 +
					order_bet[79] * 36 +
					order_bet[80] * 18 +
					order_bet[101] * 9 +
					order_bet[102] * 18 +
					order_bet[103] * 9
					;
			}

			if (number_fixed == 18){
				get_tip +=

					order_bet[32] * 18 +
					order_bet[33] * 36 +
					order_bet[34] * 18 +
					order_bet[55] * 9 +
					order_bet[56] * 18 +
					order_bet[57] * 9
					;
			}
			if (number_fixed == 19){
				get_tip +=
					order_bet[103] * 9 +
					order_bet[104] * 18 +
					order_bet[105] * 9 +
					order_bet[126] * 18 +
					order_bet[127] * 36 +
					order_bet[128] * 18
					;
			}


			if (number_fixed == 20){
				get_tip +=
					order_bet[57] * 9 +
					order_bet[58] * 18 +
					order_bet[59] * 9 +
					order_bet[80] * 18 +
					order_bet[81] * 36 +
					order_bet[82] * 18 +
					order_bet[103] * 9 +
					order_bet[104] * 18 +
					order_bet[105] * 9
					;
			}

			if (number_fixed == 21){
				get_tip +=

					order_bet[34] * 18 +
					order_bet[35] * 36 +
					order_bet[36] * 18 +
					order_bet[57] * 9 +
					order_bet[58] * 18 +
					order_bet[59] * 9
					;
			}
			if (number_fixed == 22){
				get_tip +=
					order_bet[105] * 9 +
					order_bet[106] * 18 +
					order_bet[107] * 9 +
					order_bet[128] * 18 +
					order_bet[129] * 36 +
					order_bet[130] * 18
					;
			}


			if (number_fixed == 23){
				get_tip +=
					order_bet[59] * 9 +
					order_bet[60] * 18 +
					order_bet[61] * 9 +
					order_bet[82] * 18 +
					order_bet[83] * 36 +
					order_bet[84] * 18 +
					order_bet[105] * 9 +
					order_bet[106] * 18 +
					order_bet[107] * 9
					;
			}

			if (number_fixed == 24){
				get_tip +=

					order_bet[36] * 18 +
					order_bet[37] * 36 +
					order_bet[38] * 18 +
					order_bet[59] * 9 +
					order_bet[60] * 18 +
					order_bet[61] * 9
					;
			}
			if (number_fixed == 25){
				get_tip +=
					order_bet[107] * 9 +
					order_bet[108] * 18 +
					order_bet[109] * 9 +
					order_bet[130] * 18 +
					order_bet[131] * 36 +
					order_bet[132] * 18
					;
			}


			if (number_fixed == 26){
				get_tip +=
					order_bet[61] * 9 +
					order_bet[62] * 18 +
					order_bet[63] * 9 +
					order_bet[84] * 18 +
					order_bet[85] * 36 +
					order_bet[86] * 18 +
					order_bet[107] * 9 +
					order_bet[108] * 18 +
					order_bet[109] * 9
					;
			}

			if (number_fixed == 27){
				get_tip +=

					order_bet[38] * 18 +
					order_bet[39] * 36 +
					order_bet[40] * 18 +
					order_bet[61] * 9 +
					order_bet[62] * 18 +
					order_bet[63] * 9
					;
			}
			if (number_fixed == 28){
				get_tip +=
					order_bet[109] * 9 +
					order_bet[110] * 18 +
					order_bet[111] * 9 +
					order_bet[132] * 18 +
					order_bet[133] * 36 +
					order_bet[134] * 18
					;
			}


			if (number_fixed == 29){
				get_tip +=
					order_bet[63] * 9 +
					order_bet[64] * 18 +
					order_bet[65] * 9 +
					order_bet[86] * 18 +
					order_bet[87] * 36 +
					order_bet[88] * 18 +
					order_bet[109] * 9 +
					order_bet[110] * 18 +
					order_bet[111] * 9
					;
			}

			if (number_fixed == 30){
				get_tip +=

					order_bet[40] * 18 +
					order_bet[41] * 36 +
					order_bet[42] * 18 +
					order_bet[63] * 9 +
					order_bet[64] * 18 +
					order_bet[65] * 9
					;
			}
			if (number_fixed == 31){
				get_tip +=
					order_bet[111] * 9 +
					order_bet[112] * 18 +
					order_bet[113] * 9 +
					order_bet[134] * 18 +
					order_bet[135] * 36 +
					order_bet[136] * 18
					;
			}


			if (number_fixed == 32){
				get_tip +=
					order_bet[65] * 9 +
					order_bet[66] * 18 +
					order_bet[67] * 9 +
					order_bet[88] * 18 +
					order_bet[89] * 36 +
					order_bet[90] * 18 +
					order_bet[111] * 9 +
					order_bet[112] * 18 +
					order_bet[113] * 9
					;
			}

			if (number_fixed == 33){
				get_tip +=

					order_bet[42] * 18 +
					order_bet[43] * 36 +
					order_bet[44] * 18 +
					order_bet[65] * 9 +
					order_bet[66] * 18 +
					order_bet[67] * 9
					;
			}
			if (number_fixed == 34){
				get_tip +=

					order_bet[113] * 9 +
					order_bet[114] * 18 +
					order_bet[136] * 18 +
					order_bet[137] * 36
					;
			}
			if (number_fixed == 35){
				get_tip +=
					order_bet[67] * 9 +
					order_bet[68] * 18 +
					order_bet[90] * 18 +
					order_bet[91] * 36 +
					order_bet[113] * 9 +
					order_bet[114] * 18
					;
			}
			if (number_fixed == 36){
				get_tip +=

					order_bet[44] * 18 +
					order_bet[45] * 36 +
					order_bet[67] * 9 +
					order_bet[68] * 18
					;
			}
            //�Ō�܂Ŏv�����Ȃ�����
            //�v���͂ǂ�����Ă邩���ׂ����ǋL�ڂ��ĂȂ�����


            //�F�̏��������g���Ȃ���������ԍ��ɂ���Ă��߂悤
			if (number_fixed == 1 ||
				number_fixed == 3 ||
				number_fixed == 5 ||
				number_fixed == 7 ||
				number_fixed == 9 ||
				number_fixed == 12 ||
				number_fixed == 14 ||
				number_fixed == 16 ||
				number_fixed == 18 ||
				number_fixed == 19 ||
				number_fixed == 23 ||
				number_fixed == 25 ||
				number_fixed == 27 ||
				number_fixed == 30 ||
				number_fixed == 32 ||
				number_fixed == 34 ||
				number_fixed == 36
				)
				get_tip += special_bet[9] * 2;
			//�Ԃ���Ȃ�����0����Ȃ������獕�����܂��܂���
            else if (number_fixed != 0)
			{
				get_tip += special_bet[10] * 2;
			}

			/*font.draw(
			std::to_string(get_tip),
			roulette_position - font.drawSize(std::to_string(get_tip)) / 2,
			Color::cyan);*/
            
            //���s���o��
			roulette_scene = 3;
			is_rotate_one_times = false;


		}
        drawFillCircle(mouse.x(), mouse.y(), 10, 10, 100, Color::blue);

		if (roulette_scene == 3){
			animation_counter++;

			if (animation_counter >= 60){

				//�l���\��
				font.size(100);
				font.draw(
					"�l�� " + std::to_string((get_tip)),
					Vec2f(-1024,
					-300), Color::black);
			}
			if (animation_counter >= 120){
                //���v�\��
				font.draw(
					"���v " + std::to_string((get_tip - sum_bet)),
					Vec2f(-1024,
					-400), Color::black);
			}

            //���s���o
			if (animation_counter >= 200){
				if (get_tip > sum_bet){
                    if (animation_counter == 200)
                        clear.play();
					drawTextureBox(
						0, 0,
						2048, 1024,
						0,
						(animation_counter / 7) % 2 * 256,
						512, 256,
						win, Color::white,
						0,
						Vec2f(1, 1),
						Vec2f(1048, 512)
						);
				}
				if (get_tip < sum_bet){
					drawTextureBox(
						0, 0,
						2048, 1024,
						0,
						(animation_counter / 7) % 2 * 256,
						512, 256,
						lose, Color::white,
						0,
						Vec2f(1, 1),
						Vec2f(1048, 512)
						);

				}
				if (get_tip == sum_bet){
					drawTextureBox(
						0, 0,
						2048, 1024,
						0,
						0,
						512, 256,
						zero, Color::white,
						0,
						Vec2f(1, 1),
						Vec2f(1048, 512)
						);
				}

			}

            //bet�ɖ߂�Ƃ��ɂ�邱��
			if (animation_counter >= 300){
				for (int i = 0; i < 138; i++){
					order_bet_memory[i] = order_bet[i];
				}
				for (int i = 0; i < 13; i++){
					special_bet_memory[i] = special_bet[i];
				}
				for (int i = 0; i < 138; i++){ order_bet[i] = 0; }
				for (int i = 0; i < 13; i++){ special_bet[i] = 0; }



				animation_counter = 0;
				have_tip += (get_tip - sum_bet);
				get_tip = 0;
				roulette_scene = BET;
                player.day++;
                if (player.day >(player.boss_flag + 1) * 10 * 12 * 30){
                    player.place = BOSS_;
                }
			}
		}
        		
		env.end();
	}
}
//����͕`��Ə����ƃV�[���Ǘ��������፬���ɂȂ��Ă��܂���
//�ƂĂ����ɂ��������ƂȂ��Ă��܂���