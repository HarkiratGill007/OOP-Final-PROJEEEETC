#pragma once
#include "types.h"
#include "objects.h"//nholman json included
#include <vector>


class Inventory{
    protected:
    std::vector<Object*> obj_arr;
    int i_qty = 0;//Limit : 5

    public:
    int get_qty();
    
    void i_increment();
    void i_decrement();
    std::string drop(std::string);
    std::string grab(Object* obj);
    std::string useItem(std::string _name);
    friend void to_json(json& j , const Inventory& inv);
    friend void from_json(const json& j ,  Inventory& inv);
};

