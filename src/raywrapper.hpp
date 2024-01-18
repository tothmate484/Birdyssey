#ifndef RAYWRAPPER_HPP
#define RAYWRAPPER_HPP

#include "../include/raylib.h"
#include <string>

namespace rl{

class window{
public:
    window(int width, int height, std::string title){
        InitWindow(width, height, title.c_str());
    }

    window(int width, int height, std::string title, int target_fps){
        InitWindow(width, height, title.c_str());
        SetTargetFPS(target_fps);
    }

    ~window(){
        CloseWindow();
    }

    void begin_drawing(){
        BeginDrawing();
    }

    void end_drawing(){
        EndDrawing();
    }

    bool should_close(){
        return static_cast<bool>(WindowShouldClose());
    }

    void clear_background(Color colour){
        ClearBackground(colour);
    }

    void set_target_fps(int fps){
        SetTargetFPS(fps);
    }

    void set_config_flags(unsigned int flags){
        SetConfigFlags(flags);
    }

    void draw_fps(int x, int y){
        DrawFPS(x, y);
    }
};

class vector2d{
private:
    Vector2 data;

public:

    float& x(){
        return data.x;
    }

    float& y(){
        return data.y;
    }

    vector2d(float x, float y){
        data.x = x;
        data.y = y;
    }

    vector2d& operator+=(vector2d& other){
        this->data.x += other.data.x;
        this->data.y += other.data.y;

        return *this;
    }

    vector2d operator+(vector2d& other){
    return vector2d(this->data.x + other.data.x, this->data.y + other.data.y);
    }  
};

}

#endif