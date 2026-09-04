#include "inventory.h"
#include <string>
int Inventory::get_qty(){
    return i_qty;
}
void Inventory::i_increment(){
    i_qty+=1;
}
void Inventory::i_decrement(){
    i_qty-=1;
}
std::string Inventory::drop(std::string _name){
    for (size_t i = 0; i < obj_arr.size(); i ++){
        if (obj_arr[i]->get_name() == _name){
            obj_arr[i]->decrement();
            i_decrement();
            if (obj_arr[i]->get_qty() < 1){
                delete obj_arr[i];
                obj_arr.erase(obj_arr.begin()+ i);
            }
            return "1 " + _name + " was dropped!";
        }
    }
    return "1 " + _name + " was dropped!";
}

std::string Inventory::grab(Object* obj){
    if (i_qty < 5){
    i_increment();
    for (size_t i = 0; i < obj_arr.size(); i ++){
        if (obj_arr[i]->get_name() == obj->get_name()){
            obj_arr[i]->increment();

            return "1 " + obj->get_name() + " was grabbed";
        }
    }
    obj_arr.push_back(obj);
    return "1 " + obj->get_name() + " was grabbed!\n" + obj->get_description();
}
    return "No more than 5 objects can be handled";
}
std::string Inventory::useItem(std::string _name){
    for (size_t i = 0; i < obj_arr.size(); i++){
        if (obj_arr[i]->get_name() == _name){
            std::string result = obj_arr[i]->use();
            i_decrement();
            if (obj_arr[i]->get_qty() < 1){
                delete obj_arr[i];
                obj_arr.erase(obj_arr.begin() + i);
            }
            return result;
        }
    }
    return _name + " not found in inventory.";
}

