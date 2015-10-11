#include "hit.h"





//�_�Ǝl�p�̓����蔻��
bool hitting_square(Vec2f pos, Vec2f box_pos, Vec2f box_size) {
	
	return (pos.x() >= box_pos.x())
		&& (pos.x() <= (box_pos.x() + box_size.x()))
		&& (pos.y() >= box_pos.y())
		&& (pos.y() <= (box_pos.y() + box_size.y()));
}







/////////////////////////////�u���b�N
//���P�@�߂荞�񂾂����߂�
//�߂������͕ʁX
//
//�C���[�W�́��Ɂ~
//�@�@



bool hit_block1(
	Vec2f& pos,
	Vec2f& block,
	Vec2f pos_size,
	Vec2f block_size)

{

	Vec2f pos_center = pos + pos_size / 2;
	Vec2f block_center = block + block_size / 2;
	Vec2f range = pos_size + block_size;
	if (hitting_square(pos_center, block - pos_size / 2, range)){


		if (
			((range.y() / 2 - std::abs(pos_center.y() - block_center.y()))*
			((block_center.y() <= pos_center.y()) * 2 - 1)*
			(std::abs((pos_center.y() - block_center.y()) / range.y()) >= std::abs((pos_center.x() - block_center.x()) / range.x()))) >= 0
			)return 1;

	}

		pos.x() +=
			(range.x() / 2 - std::abs(pos_center.x() - block_center.x()))*
			((block_center.x() <= pos_center.x()) * 2 - 1)*
			(std::abs((pos_center.y() - block_center.y()) / range.y()) <= std::abs((pos_center.x() - block_center.x()) / range.x()));
		pos.y() +=
			(range.y() / 2 - std::abs(pos_center.y() - block_center.y()))*
			((block_center.y() <= pos_center.y()) * 2 - 1)*
			(std::abs((pos_center.y() - block_center.y()) / range.y()) >= std::abs((pos_center.x() - block_center.x()) / range.x()));
        		
	return 0;
	
}

////�A�N�V�����Q�[������Ȃ���΂�����������Ȃ�
///��편�s
//�߂����ɂ͖߂����񂾂���
//



//���Q�@4�����̏ꏊ���擾���Ă݂�

bool hit_block2(Vec2f& pos, Vec2f& block, Vec2f pos_size, Vec2f block_size)
	{
		Vec2f p1 = Vec2f(pos.x(), pos.y());
		Vec2f p2 = Vec2f(pos.x(), pos.y()+pos_size.y());
		Vec2f p3 = Vec2f(pos.x() + pos_size.x(), pos.y() + pos_size.y());
		Vec2f p4 = Vec2f(pos.x() + pos_size.x(), pos.y());

		if (hitting_square(p1, Vec2f(block.x() - pos.x(), block.y()), pos_size) ||
			hitting_square(p2, Vec2f(block.x() - pos.x(), block.y()), pos_size)
			){
			pos.x() = block.x() + pos_size.x();
		}
	/*	if (hitting_square(p3, Vec2f(block.x(), block.y()+block.size.y()), pos_size) ||
			hitting_square(p2, Vec2f(block.x() - pos.x(), block.y()), pos_size)
			){
			pos.x() = block.x() + pos_size.x();
		}*/
		if (hitting_square(p1, Vec2f(block.x() - pos.x(), block.y()), pos_size) ||
			hitting_square(p2, Vec2f(block.x() - pos.x(), block.y()), pos_size)
			){
			pos.x() = block.x() + pos_size.x();
		}
		if (hitting_square(p1, Vec2f(block.x() - pos.x(), block.y()), pos_size) ||
			hitting_square(p2, Vec2f(block.x() - pos.x(), block.y()), pos_size)
			){
			pos.x() = block.x() + pos_size.x();
		}
        return 0;

	}
/////���s�Ł[��
//���ł�˂�
//pos��������̂���



///���R
//4�_�Ƃ��Ă݂邗
//bool hit_block3(Vec2f& pos, Vec2f& block, Vec2f pos_size, Vec2f block_size){
//
//    Vec2f& p1 = Vec2f(pos.x(), pos.y());
//    Vec2f& p2 = Vec2f(pos.x(), pos.y()+pos_size.y());
//    Vec2f& p3 = Vec2f(pos.x() + pos_size.x(), pos.y() + pos_size.y());
//    Vec2f& p4 = Vec2f(pos.x() + pos_size.x(), pos.y());
//
//    if (hitting_square(p1, block, block_size)){
//        pos.y() = block.y() + block_size.y();
//        
//    }
//
//
//
//
//
//    return hitting_square(p1, block, block_size);
//}

//��߂��悭�l�����炳��������Ă邱�Ƃƈꏏ��������


//���4������x�^�񒆂��Ƃ��Ă݂�

bool hit_block4(Vec2f& pos, Vec2f& block ,Vec2f pos_size, Vec2f block_size){
    
    Vec2f a = pos - block;

    if (hitting_square(pos, block - pos_size, block_size + pos_size)){

        
        if (std::abs(a.x()) <= std::abs(a.y())){
            if (a.y() > 0){
                pos.y() = block.y() + block_size.y();
                return 1;
            }
            if (a.y() < 0){
                pos.y() = block.y() - pos_size.y()-1;
            }
        }
        if (std::abs(a.x()) > std::abs(a.y()))
        {
            if (a.x() > 0){
                pos.x() = block.x() + block_size.x()+1;
                
            }
            if (a.x() < 0){
                pos.x() = block.x() - pos_size.x()-1;
            }



        }
        
        return 0;
    }
}
///���s
///����͉��Ŏ��s�������킩��Ȃ�



/////���T
///�C���^�[�l�b�g�ɏ����Ă������@�������Ă݂�


bool hit_block5(Vec2f& pos, Vec2f& block, Vec2f vec, Vec2f pos_size, Vec2f block_size){



    

     int MAX_LENGTH = 10;    // �߂荞�݋��e�͈�

    //// �v���C���[�̋�`
    //var my_min.x() = pos_size.x() + pos.x();      // x�ŏ�
    //var my_min.y() = pos_size.y() + pos.y();      // y�ŏ�
    //var my_max.x() = my_min.x() + my_rect_w;  // x�ő�
    //var my_max.y() = my_min.y() + my_rect_h;  // y�ő�

    //// �u���b�N�̋�`
    //var bl_min.x() = bl_rect_x;             // x�ŏ�
    //var bl_min.y() = bl_rect_y;             // y�ŏ�
    //var bl_max.x() = bl_min.x() + bl_rect_w;  // x�ő�
    //var bl_max.y() = bl_min.y() + bl_rect_h;  // y�ő�



        Vec2f my_min = pos;
        Vec2f my_max = pos + pos_size;
        Vec2f bl_min = block;
        Vec2f bl_max = block + block_size;


    if (my_max.x() < bl_min.x()){
    }
    else if (my_max.y() < bl_min.y()){
    }
    else if (my_min.x() > bl_max.x()){
    }
    else if (my_min.y() > bl_max.y()){
    }
    else{
        // ���Ɉړ���
        if (vec.y() > 0){
            // �u���b�N�̏�[
            if (my_max.y() - bl_min.y() < MAX_LENGTH){
                pos.y() = bl_min.y() - pos_size.y();//- my_rect_h;  // ��ɕ␳
                
            }

            // ��Ɉړ���
        }
        else{
            // �u���b�N�̉��[
            if (bl_max.y() - my_min.y() < MAX_LENGTH){
                pos.y() = bl_max.y() - pos_size.y();              // ���ɕ␳
            }
        }

        // �E�Ɉړ���
        if (vec.x()> 0){
            // �u���b�N�̍��[
            if (my_max.x() - bl_min.x() < MAX_LENGTH){
                pos.x() = bl_min.x() - pos_size.x();// -my_rect_w;  // ���ɕ␳
            }

            // ���Ɉړ���
        }
        else{
            // �u���b�N�̉E�[
            if (bl_max.x() - my_min.x() < MAX_LENGTH){
                pos.x() = bl_max.x() - pos_size.x();              // �E�ɕ␳
            }
        }

    }

    return 0;
    
}



    
//���6
/////�l�b�g�̗����𗝉��������

void hit_block6(Vec2f& pos, Vec2f& block, Vec2f& vec, Vec2f pos_size, Vec2f block_size){
   
    int atumi = 20;
    Vec2f a = pos - block;

    vec.y() < -20 ? vec.y() = -20 : 0;

    if (hitting_square(pos, block - pos_size, pos_size + block_size)){
       if (pos.y() >= (block.y() + block_size.y() - atumi)){
           if (vec.y() < 0){
               pos.y() = block.y() + block_size.y();
               vec.y() = 0;
           }


        }
        
       if (pos.y() <= (block.y() + atumi)){
           if (vec.y() > 0){
               pos.y() = block.y() - pos_size.y() - 1;
               vec.y() = 0;
           }
       }
        
       if (hitting_square(pos,Vec2f(block.x()-pos_size.x(),block.y()-pos_size.y()+atumi),
           Vec2f(pos_size.x() + block_size.x(), pos_size.y() + block_size.y()-atumi*2))){

           if (pos.x() <= block.x()){
               if (vec.x() > 0){

                   pos.x() = block.x() - block_size.x()*1.5f - 5;
               }

           }
           if (pos.x() >= block.x()){
               if (vec.x() < 0){
                   pos.x() = block.x() + block_size.x() + 5;

               }
           }

           
       }
     
    }
        
}
///���6���s��
///�����Ō�


///////���V
///�P�t���[����̈ʒu�̎擾
bool tugi(Vec2f pos, Vec2f block, Vec2f vec, Vec2f pos_size, Vec2f block_size){
    Vec2f tugipos = pos + vec;
    

    return hitting_square(tugipos, block-pos_size, block_size +pos_size );



}

//���̃t���[���œ����Ă������vector���O�ɂ����Ⴄ

void hit_block7(Vec2f& pos, Vec2f& block, Vec2f& vec, Vec2f pos_size, Vec2f block_size){

    if (tugi(pos, block, vec, pos_size, block_size)){
        vec = Vec2f::Zero();
    }
}
    
/////�܂����s���Ă��܂���
//////�������߂悤�Ǝv��




////���͂��̕��@�ł΂�Ȃ��悤�ɂ��߂���
bool hit_floor(Vec2f& pos, Vec2f& block, Vec2f& vec, Vec2f pos_size, Vec2f block_size){
    if (hitting_square(pos, block - pos_size, block_size + pos_size) &&
        vec.y() < 0)
    {
        pos.y() = block.y() + block_size.y();
        vec.y() = 0;
    }
    return pos.y() == block.y() + block_size.y();
}

void not_floor(Player& player,Vec2f& block, Vec2f block_size){
    if (hitting_square(player.pos, block - player.size, block_size + player.size) &&
        player.vec.y() < 0 &&
        player.floor_count == 0)
    {
        player.pos.y() = block.y() + block_size.y();
        player.vec.y() = 0;
        player.is_jump = true;
    }
   
}

//�ō��̓����蔻����v��������������Ȃ�
//�܂��v���[���[���ƃu���b�N���Ə�Ƀu���b�N�����邩��������bool��
//����bool��p�ӂ����

struct Object{
    Vec2f pos;
    Vec2f size;
    Vec2f vecter;
    float gravity;
    bool is_jump;
    int speed;
    int jump_powor;
};
bool collision(Vec2f pos, Vec2f floor_pos, Vec2f floor_size){
    return (
        pos.x() > floor_pos.x() &&
        pos.x() < floor_pos.x() + floor_size.x() &&
        pos.y() >= floor_pos.y() &&
        pos.y() <= floor_pos.y() + floor_size.y());

}
enum{
    G_MAX = -30,
    BLOCK_SIZE = 100

};
void Block(Object& p, Vec2f b_pos, Vec2f b_size, bool up, bool down){
    //���������Ă��邩
    Vec2f range = p.size + b_size;
    if (collision(p.pos, b_pos - p.size, range)){
        if (p.pos.y() > b_pos.y() + b_size.y() + G_MAX*!up){
            if (p.vecter.y() < 0){
                p.pos.y() = b_pos.y() + b_size.y();
                p.is_jump = true;
                p.vecter.y() = 0;
            }
        }
        if (p.pos.y() < b_pos.y() - p.size.y() - G_MAX *!down){
            if (p.vecter.y() > 0){
                p.pos.y() = b_pos.y() - p.size.y();
                p.vecter.y() = 0;
            }
        }
        if (p.pos.y() <= b_pos.y() + b_size.y() + G_MAX *!up&&
            p.pos.y() >= b_pos.y() - p.size.y() - G_MAX *!down
            ){
            if (p.pos.x() <= b_pos.x() - p.size.x() + range.x() / 2){
                p.pos.x() = b_pos.x() - p.size.x();
            }
            if (p.pos.x() >= b_pos.x() + b_size.x() - range.x() / 2){
                p.pos.x() = b_pos.x() + b_size.x();
            }
        }
    }
}

//������[�[�[�[�I�I�I�I�I
//����������
//���̃}�b�v�`�b�v�ɑg�ݍ��񂾂��قƂ�ǂ΂�Ȃ�

//�g���Ƃ��͂���Ȋ����ɂȂ�
//Block(player, map_pos, Vec2f(BLOCK_SIZE, BLOCK_SIZE),
//map[y - 1][x] == 1, map[y + 1][x] == 1);



