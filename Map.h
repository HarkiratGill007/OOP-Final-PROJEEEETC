#pragma once
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include "objects.h"

enum class Direction{N,S,E,W};
enum class CellType{Tile , Room};

inline Direction opposite(Direction d){
    switch(d){
        case Direction::N: return Direction::S;
        case Direction::S: return Direction::N;
        case Direction::E: return Direction::W;
        case Direction::W: return Direction::E;
    }
    return d;
}

class Cell{
     public:
     std::string cellid , name;//cellid is coordinates as string , name shall be name , like ordinary tile
     std::string north , south , east , west;//what the player sees looking each way (free-form description)
     std::unordered_map <Direction , Cell*> connections;
     std::unordered_map <Direction , std::string> lockedBy;//if locked 
     std::unique_ptr<Object> itemHere = nullptr;

     Cell(std::string _cellid , std::string _name )
          : cellid(_cellid), name(_name){} 

     void connect(Direction dir, Cell* other, const std::string& key = ""){
     if (!other) return;

     connections[dir] = other;
     if (!key.empty()) lockedBy[dir] = key;

     Direction back = opposite(dir);
     other->connections[back] = this;
     if (!key.empty()) other->lockedBy[back] = key;
     }
};