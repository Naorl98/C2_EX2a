
#include "card.hpp"
#include <iostream>
#include <stack>
#include "player.hpp"

using namespace std;
using namespace ariel;

Player::Player() {
    this->name_ = ("No name");
}
Player::Player(std::string name) {
    this->name_ = name;
}
std::string Player::Getname(){
    return this->name_;
}

Card Player::Getcard(){
    Card first =  this->cards_.top();
    cards_.pop();
    this->CardSize -= 1;
    return first;
}
void Player::won(stack<Card> cardt)
{
    while (!cardt.empty()){
        this->takenCards_.push(cardt.top());
        cardt.pop();
        this->CardTaken += 1;
    }
    this->won_ += 1;
}
void Player::lost(int count)
{
    this->lose_ += count;
}
void Player::draw()
{
    this->draw_ += 1;
}
int Player::cardesTaken()
{
    return this->lose_;
}

int Player::stacksize() {
    return 26 - this->lose_;
}