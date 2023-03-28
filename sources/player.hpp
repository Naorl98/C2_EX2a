#ifndef PLAYER_C
#define PLAYER_C
#include "card.hpp"
#include <stack>
using namespace std;

namespace ariel{
    class Player{
    public:
        Player();
        Player(std::string name);
        std::string Getname();
        Card Getcard();
        void won(stack<Card> cards);
        int stacksize();
        int cardesTaken();
        void lost(int count);
        void draw();


    private:
        stack<Card> cards_;
        std::string name_;
        stack<Card> takenCards_;
        int draw_ = 0;
        int won_ = 0;
        int lose_ = 0;
        int CardSize = 26;
        int CardTaken = 0;


    };
}
#endif
