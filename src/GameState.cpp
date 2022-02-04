#include "GameState.h"

GameState::GameState()
{
    this->stateManager = NULL;
};

GameState::~GameState(){};

void GameState::update(){};

void GameState::draw(Graphics* g){};

void GameState::free(){};

StateManager* GameState::getStateManager()
{
    return this->stateManager;
}

void GameState::setStateManager(StateManager* manager)
{
    this->stateManager = manager;
}