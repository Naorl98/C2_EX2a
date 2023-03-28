#ifndef CARD_C
#define CARD_C
#include <string>
using namespace std;
namespace ariel{
    class Card{ 
    public:

        Card(int value, string shape);
        int getValue();
        string getName(int v);
        int compare(Card c);
        string toString();
    private:
        int value_;
        string name_;
        string shape_;

            
    };
}
#endif