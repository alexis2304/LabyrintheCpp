//
//  Lb_Map.hpp
//  Labyrinthe_Cpp
//
//  Created by Alex on 01/10/2017.
//  Copyright © 2017 Alex. All rights reserved.
//

#ifndef Lb_Map_hpp
#define Lb_Map_hpp

#include <vector>
#include "Lb_Point.hpp"

class Lb_Map {
private:
    std::vector<std::vector<Lb_Point> > points;
    int height;
    int width;
public:
    Lb_Map(int const& width, int const& height);
    Lb_Point get_point_at(int const& x, int const& y);
    void set_point_at(int const& x, int const& y, Lb_Point point);
    int get_width() const;
    int get_height() const;
    ~Lb_Map();
};

#endif /* Lb_Map_hpp */
