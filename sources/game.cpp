
#include "game.hpp"
#include "player.hpp"
#include <iostream>
using namespace std;
namespace ariel{

        Game::Game(Player & p1, Player & p2) : p1(p1), p2(p2){
        }
        Game::~Game() {}

        void Game::playTurn() {}

        void Game::printLastTurn() {}

        void Game::playAll() {}

        void Game::printWiner() {}

        void Game::printLog() {}

        void Game::printStats() {}
            
}