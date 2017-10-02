//
//  main.cpp
//  Labyrinthe_Cpp
//
//  Created by Alex on 01/10/2017.
//  Copyright © 2017 Alex. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Lb_Map.hpp"
#include <vector>

#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 801
#define WINDOW_HEIGHT 601

void set_map_position(Lb_Map *map, Vector2 current_position){
    Lb_Point point = map->get_point_at(current_position.get_x(), current_position.get_y());
    point.set_visibility(true);
    map->set_point_at(current_position.get_x(), current_position.get_y(), point);
}

Lb_Map init_Map(){
    int const t_size = 4;
    int const map_width     = WINDOW_WIDTH;
    int const map_height    = WINDOW_HEIGHT;
    Vector2 t_arr[t_size];
    t_arr[0] = Vector2( 0,  1); // up
    t_arr[1] = Vector2( 1,  0); // right
    t_arr[2] = Vector2( 0, -1); // down
    t_arr[3] = Vector2(-1,  0); // left
    
    Lb_Map map(map_width, map_height);   // la Map.
    //int arr_count = (((map_width + 1) / 2) * ((map_height + 1) / 2)) - 1;
    Vector2 current_position(0, 0); // La position actuel.
    
    std::vector<Vector2> cache_position;
    unsigned int c_lenght = 0;
    cache_position.push_back(current_position);
    
    set_map_position(&map, current_position);
    
    srand(time(NULL));
    
    do {
        int position_random = rand() % t_size;
        int position_count = 0;
        bool asWall = true;
        Vector2 next_position;
        do {
            next_position = (current_position + (t_arr[position_random] * 8) );
            if(next_position.get_x() < map.get_width()  && next_position.get_x() >= 0 && next_position.get_y() < map.get_height() && next_position.get_y() >= 0){
                if(!map.get_point_at(next_position.get_x(), next_position.get_y()).get_visibility()){
                    asWall = false;
                }else{
                    position_random = (position_random + 1) % t_size;
                    position_count++;
                }
            }else{
                position_random = (position_random + 1) % t_size;
                position_count++;
            }
            
        } while (asWall && position_count < 5);
        
        if(position_count >= 4){
            cache_position.pop_back();
            current_position = cache_position[cache_position.size()];
        }else{
            current_position = next_position;
            set_map_position(&map, current_position);
            for(int i = 1; i < 8; i++){
                set_map_position(&map, current_position - t_arr[position_random] * i);
            }
            cache_position.push_back(current_position);
            c_lenght++;
        }
        position_count = 0;
        asWall = true;
    } while (current_position != cache_position[0]);
    return map;
}

int main(int argc, const char * argv[]) {
    
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;
    int i;
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
    
    
    /*for (i = 0; i < WINDOW_WIDTH; ++i)
        SDL_RenderDrawPoint(renderer, i, i);*/
    while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            break;
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym){
                case SDLK_SPACE:
                    //std::cout<<"Pressed key"<<std::endl;
                    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                    SDL_RenderClear(renderer);
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    Lb_Map map = init_Map();
                    for (int y = map.get_height() - 1; y >= 0; y--) {
                        for (int x = 0; x < map.get_width(); x++) {
                            if(map.get_point_at(x, y).get_visibility() == true){
                                SDL_RenderDrawPoint(renderer, x, y);
                            }
                        }
                    }
                    SDL_RenderPresent(renderer);
                    break;
            }
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
