#include "Gamestate.h"
#include <algorithm>
#include <fstream>


// {
//   "saves": [
//     {"id": 1, "GameState" : gamestateobj},
//     {"id": 2, "GameState" : gamestateobj}
//   ]
// }
void GameState::completeCheckpoint(Checkpoint cp){
    completedCheckpoints.insert(cp);
}

bool GameState::hasCompletedCheckpoint(Checkpoint cp) const{
    return completedCheckpoints.count(cp) > 0;
}

std::string save_state(const GameState& gs){
    json root;
    std::ifstream in("gamestates.json");
    if (in && in.peek() != EOF) in >> root;

    if (!root.contains("saves") || !root["saves"].is_array()){
        root["saves"] = json::array();
    }

    int maxid = 0;
    for (const auto& x : root["saves"]){
        if (x.contains("id") && x["id"].is_number_integer()){
            maxid = std::max(maxid, x["id"].get<int>());
        }
    }
    
    json entry;
    entry["id"] = maxid+1;
    entry["GameState"] = gs;
    root["saves"].push_back(entry);

    std::ofstream out("gamestates.json");
    if (out) out << root.dump(4);

    return "Game state saved successfully with ID: " + std::to_string(maxid+1);
}

std::string load_state(int id, GameState &gs){
    json root;
    std::ifstream in("gamestates.json");
    if (in && in.peek() != EOF) in >> root;

    if (!root.contains("saves") || !root["saves"].is_array())
        return "Game state with ID: " + std::to_string(id) + " not found.";

    for (const auto& x : root["saves"]){
        if (x.contains("id") && x["id"].is_number_integer()
            && x["id"].get<int>() == id){
            x["GameState"].get_to(gs);
            return "Game state loaded successfully with ID: " + std::to_string(id);
        }
    }
    return "Game state with ID: " + std::to_string(id) + " not found.";
}
