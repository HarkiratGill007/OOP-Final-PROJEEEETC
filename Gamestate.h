#pragma once
#include <nlohmann/json.hpp>
#include "types.h"
#include <string>
#include <utility>
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

    GameState(Checkpoint las_cp , MainChar mc_ , SideChar sc_) :  last_checkpoint(las_cp) , mc_state(std::move(mc_)) , sc_state(std::move(sc_)){}
//+other choice based shi
    //+ other stateknowledge later including choice based outcomes

    friend void to_json(json& j, const GameState& gs) {
        j = json{
            {"completedCheckpoints", gs.completedCheckpoints},
            {"last_checkpoint", gs.last_checkpoint},
            {"mc_state", gs.mc_state},
            {"sc_state", gs.sc_state}
        };
    }

    friend void from_json(const json& j, GameState& gs) {
        j.at("completedCheckpoints").get_to(gs.completedCheckpoints);
        j.at("last_checkpoint").get_to(gs.last_checkpoint);
        j.at("mc_state").get_to(gs.mc_state);
        j.at("sc_state").get_to(gs.sc_state);
    }
};




std::string save_state(const GameState &gs);

std::string load_state(int id ,  GameState &gs);