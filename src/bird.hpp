#ifndef BIRD_HPP
#define BIRD_HPP

#include <cstdint>
#include <string>
#include <vector>
#include "pillar.hpp"
#include "raywrapper.hpp"
#include "pillarpair.hpp"

class Bird{
public:

    rl::vector2d pos;
    uint16_t width;
    uint16_t height;
    rl::vector2d uplift;
    rl::vector2d gravity;
    unsigned long long score;
    std::vector<Pillarpair>& pillars;
    Texture bird_texture;

    Bird(const float& x, const float& y, const uint16_t& width_, const uint16_t& height_, std::vector<Pillarpair>& pillars_)
    : pos(rl::vector2d(x, y)), width(width_), height(height_), 
        uplift(rl::vector2d(0.0f, -50.0f)), gravity(rl::vector2d(0.0f, 3.0f)), 
        score(0),pillars(pillars_){
            bird_texture = LoadTexture("resources/bird.png");
        }


    void draw(){
        DrawRectangle(static_cast<int>(pos.x()), static_cast<int>(pos.y()), width, height, GREEN);
        DrawTexture(bird_texture, pos.x(), pos.y(), WHITE);
        std::string scoretext = "Score: " + std::to_string(score);
        DrawText(scoretext.c_str(), 700, 10, 20, BLACK);
    }

    bool detect_death(){
        if(pos.y() < 0) return true;
        else if(pos.y() > 450 - height) return true;

        for(unsigned long int i = 0; i < pillars.size(); i++){
            if(detect_collision(pillars[i])) return true;
        }

        return false;
    }

    bool detect_collision(const Pillarpair& pillarpair){
        
        if ((pos.x() + width) < pillarpair.upper.get_pos().x() || (pillarpair.upper.get_pos().x() + pillarpair.upper.width) < pos.x()) {
        return false;
        }

        if ((pos.y() + height) < pillarpair.upper.get_pos().y() || (pillarpair.upper.get_pos().y() + pillarpair.upper.height) < pos.y()) {
        return false;
        }

        //lower***********************************************//
        if ((pos.x() + width) < pillarpair.lower.get_pos().x() || (pillarpair.lower.get_pos().x() + pillarpair.lower.width) < pos.x()) {
        return false;
        }

        if ((pos.y() + height) < pillarpair.lower.get_pos().y() || (pillarpair.lower.get_pos().y() + pillarpair.lower.height) < pos.y()) {
        return false;
        }

        return true;

    }

    void count_score(){
        for(unsigned long int i = 0; i < pillars.size(); i+=2){
            //if(pillars[i].get_pos().x() == pos.x()) score++;
        }
    }

    bool operate(){
        
        if(detect_death()) return false;

        pos += gravity;
        rl::vector2d acc(0.0f, 0.3f);
        gravity += acc;

        if(IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            pos += uplift;
            gravity = rl::vector2d(0.0f, -3.0f);
        }

        count_score();

        return true;
    }

    ~Bird(){
        UnloadTexture(bird_texture);
    }
};

#endif