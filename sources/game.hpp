#ifndef GAME_C
#define GAME_C
#include "player.hpp"
namespace ariel{
    class Game{ 
    public:

        Game(Player & p1, Player & p2);
        ~Game();
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    private:
        Player & p1;
        Player & p2;
        int rounds_;
        

            
    };
}
#endif