#include "StateManager.h"

StateManager::StateManager(){};

StateManager::~StateManager(){};

void StateManager::addState(GameState* state)
{
    state->setStateManager(this);
    states.push(state);
};

void StateManager::popState()
{
    states.pop();
};

void StateManager::update()
{
    if(!states.empty() )
    {
        if(states.top() != NULL)
        {
            states.top()->update();
        }    
    }
};

void StateManager::draw(Graphics* g)
{
    if(!states.empty() )
    {
        if(states.top() != NULL)
        {
            states.top()->draw(g);
        }
    }
};

bool StateManager::isEmpty()
{
    return states.empty();
}