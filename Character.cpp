#include "Character.h"

// std::string change_details(std::string new_name = '\0', char new_gender = '\0');
// std::string add_energy_signed(int amount) override;

std ::string MainChar::add_energy_signed(int amt){
    if ((100 >= amt) &&  (amt > 0)){
        energy += amt;
        if (energy > 100) energy = 100;
        return "Your energy increased";
    }
    else if ((amt >= -100) && (amt < 0)){
        energy += amt;
        if (energy < 0) energy = 0;
        return "Your energy decreased";
    }
    else return "DevError : Invalid Amount Probably" ;
     
}

std ::string SideChar::add_energy_signed(int amt){
    if ((100 >= amt) &&  (amt > 0)){
        energy += amt;
        if (energy > 100) energy = 100;
        return name + "'s energy increased";
    }
    else if ((amt >= -100) && (amt < 0)){
        energy += amt;
        if (energy < 0) energy = 0;
        return name + "'s energy decreased";
    }
    else return "DevError : Invalid Amount Probably" ;
}

std::string MainChar::change_details(std::string new_name , char new_gender  ){
    bool any_change = 0;
    if (new_name[0] != '\0'){
        name = new_name;
        any_change = 1;
    }
    if (new_gender != '\0'){
        gender = new_gender;
        any_change = 1;
    }
    if (any_change) return "Changes made";
    else return "No changes were made";
}


