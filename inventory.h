#pragma once
#include "types.h"
#include <memory>
#include "objects.h"//nholman json included
#include <vector>

//inventory : inv.grab(std::make_unique<ConsumableObj>("apple","fruit",Region::hall1,3));yy
class Inventory{
    protected:
    std::vector<std::unique_ptr<Object>> obj_arr;
    int i_qty = 0;//Limit : 5

    public:
    int get_qty();
    
    void i_increment();
    void i_decrement();
    std::string drop(std::string);
    std::string grab(std::unique_ptr<Object> obj);
    std::string useItem(std::string _name);
    friend void to_json(json& j , const Inventory& inv);
    friend void from_json(const json& j ,  Inventory& inv);
};

