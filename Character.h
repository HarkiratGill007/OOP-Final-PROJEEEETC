#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include "inventory.h"
using json = nlohmann::json;
//well character has a name (that side chracter may refer or some interactive things (which i should define in Map) ) , Gender , rest age shall be predefined an
class Mortal{
    public:
    std::string name;
    int age ;
    int energy ;
    char gender ;
    Mortal(std::string _name , int _age , int _ene , char _gen): name(_name) , age(_age) ,energy(_ene), gender(_gen){};
    virtual ~Mortal(){}
    virtual std::string add_energy_signed(int amount) = 0;//used for decreasing too
};

class MainChar : public Mortal{
    public:
    MainChar(std::string _name , int _age ,int _ene  , char _gen , Inventory _inv): Mortal(_name, _age, _ene ,  _gen){mc_inventory = _inv;}
    Inventory mc_inventory;
    std::string change_details(std::string new_name = "", char new_gender = '\0');
    std::string add_energy_signed(int amount) override;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MainChar , name , age , energy , gender , mc_inventory );
class SideChar : public Mortal{
    public:
    SideChar(std::string _name , int _age ,char _gen , Inventory _inv , int _ene): Mortal(_name, _age, _ene,  _gen){sc_inventory = _inv;}
    Inventory sc_inventory;
    std::string add_energy_signed(int amount) override;

};//if needed change_details can be added later
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(SideChar , name , age , energy , gender , sc_inventory );