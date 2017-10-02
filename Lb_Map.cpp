//
//  Lb_Map.cpp
//  Labyrinthe_Cpp
//
//  Created by Alex on 01/10/2017.
//  Copyright © 2017 Alex. All rights reserved.
//

#include "Lb_Map.hpp"

Lb_Map::Lb_Map(int const& width, int const& height){
    this->height = height;
    this->width = width;
    for (int x = 0; x < width; x++) {
        std::vector<Lb_Point> arr;
        for(int y = 0; y < height; y++){
            Lb_Point a(Vector2(x, y));
            arr.push_back(a);
        }
        points.push_back(arr);
    }
}

Lb_Point Lb_Map::get_point_at(int const& x, int const& y){
    return points[x][y];
}

void Lb_Map::set_point_at(int const& x, int const& y, Lb_Point point){
    this->points[x][y] = point;
}

int Lb_Map::get_width() const{
    return this->width;
}

int Lb_Map::get_height() const{
    return this->height;
}

Lb_Map::~Lb_Map(){
    this->points.clear();
}
