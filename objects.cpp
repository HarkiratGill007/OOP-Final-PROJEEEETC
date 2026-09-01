#include "objects.h"

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

