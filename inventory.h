#pragma once
#include "types.h"
#include "objects.h"
#include <vector>


class Inventory{
    std::vector<Object*> obj_arr;
    int i_qty = 0;//Limit : 5

    public:
    int get_qty();
    void i_increment();
    void i_decrement();
    std::string drop(std::string);
    std::string grab(Object* obj);
    std::string useItem(std::string _name);
};