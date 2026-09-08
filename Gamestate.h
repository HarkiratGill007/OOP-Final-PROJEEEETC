#pragma once
#include "types.h"
#include <unordered_set>
//CHekpoint enum in types.h
class GameState{
    private:
    std::unordered_set<Checkpoint> completedCheckpoints;

    public:
    void completeCheckpoint(Checkpoint cp);
    bool hasCompletedCheckpoint(Checkpoint cp) const;
    //+ other stateknowledge later including choice based outcomes
};