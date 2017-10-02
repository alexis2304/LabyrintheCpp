//
//  Vector2.cpp
//  Labyrinthe_Cpp
//
//  Created by Alex on 01/10/2017.
//  Copyright © 2017 Alex. All rights reserved.
//

#include "Vector2.hpp"

Vector2::Vector2(){
    this->x = 0;
    this->y = 0;
}

Vector2::Vector2(int const& x, int const& y){
    this->x = x;
    this->y = y;
}

int Vector2::get_x()const{
    return x;
}

int Vector2::get_y()const{
    return y;
}

void Vector2::set_x(int const& x){
    this->x = x;
}

void Vector2::set_y(int const& y){
    this->y = y;
}

bool operator==(Vector2 const& a, Vector2 const& b){
    if(a.get_x() == b.get_x() && a.get_y() == b.get_y()){
        return true;
    }else{
        return false;
    }
}

bool operator!=(Vector2 const& a, Vector2 const& b){
    return !(a == b);
}

Vector2 operator+(Vector2 const& a, Vector2 const& b){
    return Vector2(a.get_x() + b.get_x(), a.get_y() + b.get_y());
}

Vector2 operator-(Vector2 const& a, Vector2 const& b){
    return Vector2(a.get_x() - b.get_x(), a.get_y() - b.get_y());
}

Vector2 operator*(Vector2 const& a, Vector2 const& b){
    return Vector2(a.get_x() * b.get_x(), a.get_y() * b.get_y());
}

Vector2 operator*(Vector2 const& a, int const& b){
    return Vector2(a.get_x() * b, a.get_y() * b);
}
