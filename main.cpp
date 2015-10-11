//#include "lib/framework.hpp"
#include <iostream>
//#include "screen.h"

#include "world.h"
#include "Title.h" 
#include "story.h"

  
//メインで大きいシーン管理にしようかな
//大体がwhileの条件式による疑似break

int main() {
	
    env;
    int sceen = 0;
    while (true)
    {
        Title(sceen);
        Story(sceen);
        World(sceen);
        ending(sceen);
    }
}
