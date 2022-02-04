#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "StateManager.h"
#include "Graphics.h"

class StateManager;

class GameState
{
    private:
        StateManager* stateManager;

    public:
        GameState();
        ~GameState();

        virtual void update();
        virtual void draw(Graphics* g);
        virtual void free();

        StateManager* getStateManager();
        void setStateManager(StateManager* manager);
};

#endif