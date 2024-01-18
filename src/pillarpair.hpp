#ifndef PILLARPAIR_HPP
#define PILLARPAIR_HPP

#include "pillar.hpp"
#include "raywrapper.hpp"
#include <array>
#include <cstdint>

class Pillarpair{
public:
    Pillar& upper;
    Pillar& lower;
    uint16_t distance;

    Pillarpair(Pillar& upper_, Pillar& lower_, uint16_t distance_) : upper(upper_), lower(lower_), distance(distance_){}

    void draw(){
        
        if(upper.pos.x() <= -upper.width) {
            upper.pos.x() = static_cast<float>(GetScreenWidth() + upper.width);
            upper.height = static_cast<uint16_t>(GetRandomValue(20, 213));

            lower.height = 450 - upper.height - distance;
            lower.pos.y() = 450-lower.height;
        }
        upper.pos.x() -= 5;
        lower.pos.x() = upper.pos.x();
        

        upper.draw();
        lower.draw();
    }

};

#endif