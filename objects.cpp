#include "objects.h"

void Object::decrement(){
    qty-=1;
}
int Object::get_qty(){
    return qty;
}
std::string Object::get_name(){
    return name;
}
void Object::increment(){
    qty+=1;
}
std::string Object::get_description(){
    return description;
}
std::string ConsumableObj::use(){
    if (qty > 0) qty -= 1;
    return name + " was consumed.";
}

std::string ApplyableObj ::use(){
    if (qty > 0) qty -= 1;
    return name + " was applied.";
}

std::string UsableObj  ::use(){
    if (qty > 0) qty -= 1;
    return name + " was used.";
}

std::string LendableObj::use(){
    if (qty > 0) qty -= 1;
    return name + " was lent.";
}
// ConsumableObj apple

