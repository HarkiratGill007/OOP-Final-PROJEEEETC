#include <nlohmann/json.hpp>
#include <iostream>

int main(){
nlohmann::json j = nlohmann::json::parse(R"({"ok":true})");
std::cout << j["ok"] << "\n";

}



/*
Shall include: 
1. a Current Gamestate 
*/