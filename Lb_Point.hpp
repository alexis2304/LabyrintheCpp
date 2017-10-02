//
//  Lb_Point.hpp
//  Labyrinthe_Cpp
//
//  Created by Alex on 02/10/2017.
//  Copyright © 2017 Alex. All rights reserved.
//

#ifndef Lb_Point_hpp
#define Lb_Point_hpp

#include "Vector2.hpp"

class Lb_Point {
private:
    Vector2 position;
    bool isVisible;
public:
    Lb_Point();
    Lb_Point(Vector2 const& position);
    void set_visibility(bool state);
    Vector2 get_position() const;
    bool get_visibility() const;
};

#endif /* Lb_Point_hpp */
