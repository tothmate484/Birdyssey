#include "../include/raylib.h"
#include "pillar.hpp"
#include "raywrapper.hpp"
#include "bird.hpp"
#include "pillarpair.hpp"
#include <vector>


void scene_gameplay(rl::window& window){
    std::vector<Pillarpair> pillars;
    Pillar p1(Pillar(400-20, 0, 40, 100, "resources/pillar2.png"));
    Pillar p2(Pillar(400-20, 450-100, 40, 100, "resources/pillar1.png"));
    pillars.push_back(Pillarpair(p1,p2, 150));

    Bird bird(static_cast<float>(400-20), static_cast<float>(225-20), 40, 40, pillars);

    window.clear_background((Color){173,216,230,127});
    WaitTime(0.5f); //get some time for the player to start

    while(!window.should_close()){ //main loop
        
        window.begin_drawing(); //begin

        window.clear_background((Color){5,122,235,0});

        for(long unsigned int i = 0; i < pillars.size(); i++){
            pillars[i].draw();
        }

        bool status = bird.operate();
        if(!status) return;

        bird.draw();

        window.draw_fps(0, 0);

        window.end_drawing(); //end
    }                               //main loop end
}

void scene_menu(rl::window& window){
    while(!window.should_close()){
        
        window.begin_drawing();

        window.clear_background((Color){5,122,235,0});

        DrawText("Press SPACE to start!", 50 , 200, 50, WHITE);

        if(IsKeyPressed(KEY_SPACE)){
            scene_gameplay(window);
        }

        window.end_drawing();
    }
}

int main(int argc, char* argv[])
{

    rl::window window(800,450, "rl::flappy_bird", 60);

    scene_menu(window);

    return 0;
}
