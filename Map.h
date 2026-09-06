#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "objects.h"

enum class Direction{N,S,E,W};
enum class CellType{Tile , Room};

class Cell{
     public:
     std::string cellid , name;//cellid is coordinates as string , name shall be name , like ordinary tile
     std::string description;
     std::unordered_map <Direction , Cell*> connections;
     std::unordered_map <Direction , std::string> lockedBy;//if locked 
     Object* itemHere = nullptr;
};