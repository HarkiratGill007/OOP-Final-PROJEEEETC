#pragma once
#include "types.h"
#include <string>
// enum class Category{
//     consumable,
//     applyable,
//     usable,
//     lendable,

// };
class Object{

    public:
    Object(Category _category , std::string _name ,std::string _description, Region _origin , int _qty=0) :category(_category), name(_name) ,description(_description), origin(_origin) , qty(_qty) {}
    const Category category;
    virtual std::string use() = 0;

    protected:
    const std::string name;
    const std::string description;
    const Region origin ;
    int qty = 0;
   // objetcs only nned a point of respawn if dropped , 

    
    
    // drop(); shall be a method of inventory which shall be a collection of objects
    //applicablility and interactables shall be  of map points 
    
};  //includes all interactables(objetcs that are used at interactable places)

class ConsumableObj : public Object{
    public:
    ConsumableObj(std::string _name ,std::string _description, const Region& _origin, int _qty = 0 ) : Object(Category::consumable,_name ,_description,  _origin ,  _qty){}
    std::string use() override;
};

class ApplyableObj : public Object{
    public:
    ApplyableObj(std::string _name ,std::string _description, const Region& _origin, int _qty = 0 ) : Object(Category::applyable,_name ,_description,  _origin ,  _qty){}
    std::string use() override;
};
class UsableObj : public Object{
    public:
    UsableObj(std::string _name ,std::string _description, const Region& _origin, int _qty = 0 ) : Object(Category::usable, _name ,_description,  _origin , _qty){}
    std::string use() override;
};
class LendableObj : public Object{
    public:
    LendableObj(std::string _name ,std::string _description, const Region& _origin, int _qty = 0 ) : Object(Category::lendable,_name ,_description,  _origin ,  _qty){}
    std::string use() override;
};