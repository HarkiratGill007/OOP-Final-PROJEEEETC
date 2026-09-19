#include "Gamestate.h"
#include <fstream>

// {
//   "saves": [
//     {"id": 1, "gamestate" : gamestateobj},
//     {"id": 2, "gamestate" : gamestateobj}
//   ]
// }
void GameState::completeCheckpoint(Checkpoint cp){
    completedCheckpoints.insert(cp);
}

bool GameState::hasCompletedCheckpoint(Checkpoint cp) const{
    return completedCheckpoints.count(cp) > 0;
}

std::string save_state(GameState gs){
    json root;
    std::ifstream in("gamestates.json");
    if (in) in>>root;

    if (!root.contains("saves") || !root["saves"].is_array()){
        root["saves"] = json::array();
    }

    int maxid = 0;
    for (const auto& x : root["saves"]){
        if (x.contains("id") && x["id"].is_number_integer()){
            maxid+=1;
        }
    }
    
    json entry;
    entry["id"] = maxid+1;
    entry["GameState"] = gs;

    
}