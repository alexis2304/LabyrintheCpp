//
//  Vector2.h
//  Labyrinthe_Cpp
//
//  Created by Alex on 01/10/2017.
//  Copyright © 2017 Alex. All rights reserved.
//

#ifndef Vector2_h
#define Vector2_h
#include <iostream>
class Vector2 {
private:
    int x;
    int y;
public:
    Vector2();
    Vector2(int const& x, int const& y);
    int get_x()const;
    int get_y()const;
    void set_x(int const& x);
    void set_y(int const& y);
};

bool operator!=(Vector2 const& a, Vector2 const& b);
bool operator==(Vector2 const& a, Vector2 const& b);
Vector2 operator+(Vector2 const& a, Vector2 const& b);
Vector2 operator-(Vector2 const& a, Vector2 const& b);
Vector2 operator*(Vector2 const& a, Vector2 const& b);
Vector2 operator*(Vector2 const& a, int const& b);

#endif /* Vector2_h */
