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

nlohmann::json ConsumableObj::toJson() const{
    return {{"category" , "ConsumableObj"}, {"name", name}, {"description", description}, {"origin", origin} , {"qty", qty}};
}
nlohmann::json ApplyableObj::toJson() const{
    return {{"category" , "ApplyableObj"}, {"name", name}, {"description", description}, {"origin", origin} , {"qty", qty}};
}
nlohmann::json UsableObj::toJson() const{
    return {{"category" , "UsableObj"}, {"name", name}, {"description", description}, {"origin", origin} , {"qty", qty}};
}
nlohmann::json LendableObj::toJson() const {
    return {{"category" , "LendableObj"}, {"name", name}, {"description", description}, {"origin", origin} , {"qty", qty}};
}


Object* makeObject(const json& j){

    if (j.contains("category")){
        if (j["category"] == "ConsumableObj"){
             return new ConsumableObj(j["name"].get<std::string>(), j["description"].get<std::string>(), j["origin"].get<Region>(), j["qty"].get<int>());
        }
        if (j["category"] == "UsableObj"){
             return new UsableObj(j["name"].get<std::string>(), j["description"].get<std::string>(), j["origin"].get<Region>(), j["qty"].get<int>()    );
        }
        if (j["category"] == "ApplyableObj"){
             return new ApplyableObj(j["name"].get<std::string>(), j["description"].get<std::string>(), j["origin"].get<Region>(), j["qty"].get<int>());
        }
        if (j["category"] == "LendableObj"){
             return new LendableObj(j["name"].get<std::string>(), j["description"].get<std::string>(), j["origin"].get<Region>(), j["qty"].get<int>());
        }
        return nullptr;
    }
    return nullptr;
}
// ConsumableObj apple

