#include <iostream>
#include <stack>
#include "card.hpp"
using namespace std;
using namespace ariel;    
int value_;
std::string name_;
std::string shape_;
Card::Card(int value, string shape){
    this->value_ = value;
    this->shape_ = shape;
}
std::string Card::getName(int v ){
    v = 1;
    return "One";
}

int Card::getValue(){return this->value_;}
        
int Card::compare(Card c){
    if( this->value_ > c.getValue()) return 1;
    else if( this->value_ < c.getValue()) return 2;
    return 0;
}
std::string Card::toString(){
    return "Card: " +this->shape_ + " " + this->name_;
}
