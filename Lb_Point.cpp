//
//  Lb_Point.cpp
//  Labyrinthe_Cpp
//
//  Created by Alex on 02/10/2017.
//  Copyright © 2017 Alex. All rights reserved.
//

#include "Lb_Point.hpp"

Lb_Point::Lb_Point(){
    this->position = Vector2();
    this->isVisible = false;
}

Lb_Point::Lb_Point(Vector2 const& position){
    this->position = position;
    this->isVisible = false;
}

void Lb_Point::set_visibility(bool state){
    this->isVisible = state;
}

Vector2 Lb_Point::get_position() const{
    return this->position;
}

bool Lb_Point::get_visibility() const{
    return this->isVisible;
}
