#include <iostream>
#include "display.h"
#include "inventory.h"
#include "objects.h"

//ConsumableObj(std::string _name, std::string _description, const Region &_origin, int _qty = 0)
int main(){
    ConsumableObj potion  = ConsumableObj("Potion" , "Heals Your Ch" , Region::dungeon1, 5);
    UsableObj key = UsableObj("Key", "Unlocks door", Region::dungeon3 , 3);
    Inventory mainInv;
    std::cout<<mainInv.grab(&potion)<<"\n" ;
    std::cout<<mainInv.grab(&key)<<"\n" ;
    std::cout<<mainInv.drop("Key")<<"\n" ;
    std::cout<<mainInv.grab(&potion)<<"\n" ;
}