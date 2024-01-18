#ifndef PILLAR_HPP
#define PILLAR_HPP

#include <cstdint>
#include <iostream>
#include <string>
#include "../include/raylib.h"
#include "raywrapper.hpp"

class Pillar{
public:
    rl::vector2d pos;

    uint16_t width;
    uint16_t height;
    Pillar* pair;
    const Texture pillar_texture;

    Pillar(const uint16_t& x_, const uint16_t& y_, const uint16_t& width_, const uint16_t& height_,std::string texture_) : 
        pos(static_cast<float>(x_), static_cast<float>(y_)), width(width_), height(height_), pair(nullptr),
        pillar_texture(LoadTexture(texture_.c_str())){}

    void setPair(Pillar* pair_){
        pair = pair_;
    }

    /*void reset(){
        pos.x() = GetScreenWidth();
        if(pair != nullptr){
            pos.y() = pair->pos.y() + 100;
        }
    }*/

    rl::vector2d get_pos() const{
        return pos;
    }

    void draw(){

        DrawRectangle(static_cast<int>(pos.x()), static_cast<int>(pos.y()), width, height, RED);

        if(static_cast<int>(pos.y()) != 0){
            DrawTexture(pillar_texture, static_cast<int>(pos.x()), static_cast<int>(pos.y()), WHITE);
        }
        else{
            DrawTexture(pillar_texture, static_cast<int>(pos.x()), static_cast<int>(pos.y())+height-213, WHITE);
        }

    }

    /*~Pillar(){
        UnloadTexture(pillar_texture);
    }*/
};

#endif