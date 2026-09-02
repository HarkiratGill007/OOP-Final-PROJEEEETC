#pragma once
#include "types.h"
#include "objects.h"
#include <vector>


class Inventory{
    std::vector<Object*> obj_arr;
    public:

    std::string drop();
    std::string grab();
};
