#pragma once
#include <string>
#include "inventory.h"
//well Chracter has a name (that side chracter may refer or some interactive things (which i should define in Map) ) , Gender , rest age shall be predefined an
class Mortal{
    public:
    std::string name;
    int age ;
    int energy ;
    char gender ;
    Mortal(std::string _name , int _age , int _ene , char _gen): name(_name) , age(_age) ,energy(_ene), gender(_gen){};
    virtual std::string add_energy_signed(int amount) = 0;//used for decraeasing too
};

class MainChar : public Mortal{
    public:
    MainChar(std::string _name , int _age ,int _ene , char _gen , Inventory _inv): Mortal(_name, _age, _ene = 100,  _gen){mc_inventory = _inv;}
    Inventory mc_inventory;
    std::string change_details(std::string new_name = '\0', char new_gender = '\0');
    std::string add_energy_signed(int amount) override;
};

class SideChar : public Mortal{
    public:
    SideChar(std::string _name , int _age ,char _gen , Inventory _inv , int _ene = 15): Mortal(_name, _age, _ene = 15,  _gen){sc_inventory = _inv;}
    Inventory sc_inventory;
    std::string add_energy_signed(int amount) override;

};//if needed change_details can be added later
