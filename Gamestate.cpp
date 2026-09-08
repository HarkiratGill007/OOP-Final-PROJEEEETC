#include "Gamestate.h"
void GameState::completeCheckpoint(Checkpoint cp){
    completedCheckpoints.insert(cp);
}

bool GameState::hasCompletedCheckpoint(Checkpoint cp) const{
    return completedCheckpoints.count(cp) > 0;
}