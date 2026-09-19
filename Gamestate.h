#pragma once
#include <nlohmann/json.hpp>
#include "types.h"
#include <string>
#include <unordered_set>
#include "Character.h"

using json =  nlohmann::json;
//CHekpoint enum in types.h
class GameState{
   

    public:
    
    std::unordered_set<Checkpoint> completedCheckpoints;
    void completeCheckpoint(Checkpoint cp);
    bool hasCompletedCheckpoint(Checkpoint cp) const;
    Checkpoint last_checkpoint;
    MainChar mc_state;
    SideChar sc_state;

    GameState(Checkpoint las_cp , MainChar mc_ , SideChar sc_) : last_checkpoint(las_cp) , mc_state(mc_) , sc_state(sc_){}//+other choice based shi
    //+ other stateknowledge later including choice based outcomes
};


NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(GameState ,completedCheckpoints, last_checkpoint , mc_state , sc_state );

std::string save_state(GameState gs);