#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 1"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.stacksize() == 26);
    CHECK(p2.cardesTaken() == 0);
}
TEST_CASE("Test 2"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);
}

TEST_CASE("Test 3"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    int p;
    if(p1.cardesTaken() != 0 && p2.cardesTaken() == 0)
        p = 1;
    else if(p1.cardesTaken() != 0 && p2.cardesTaken() == 0)
        p = 2;
    CHECK(p != 0);
}
TEST_CASE("Test 4"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}
TEST_CASE("Test 5"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK(std::is_void<decltype(game.printLastTurn())>::value);
    CHECK(std::is_void<decltype(game.printLog())>::value);
    CHECK(std::is_void<decltype(game.printStats())>::value);
    CHECK(std::is_void<decltype(game.playAll())>::value);
    CHECK(std::is_void<decltype(game.playTurn())>::value);
    CHECK(std::is_void<decltype(game.printWiner())>::value);
}
TEST_CASE("Test 6"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printLog());
}
TEST_CASE("Test 7"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printStats());

}
TEST_CASE("Test 8"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    CHECK(p1.stacksize() == p2.stacksize());
    game.playTurn();
    CHECK(p1.stacksize() == p2.stacksize());
    game.playTurn();
    CHECK(p1.stacksize() == p2.stacksize());
}
TEST_CASE("Test 9"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    int s1 = p1.stacksize();
    game.playTurn();
    CHECK(p1.stacksize() != s1);
    s1 = p1.stacksize();
    game.playTurn();
    CHECK(p1.stacksize() != s1);
}
TEST_CASE("Test 10"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printWiner());
}
TEST_CASE("Test 11"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printLastTurn());
}
TEST_CASE("Test 12"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK(std::is_void<decltype(game.printLastTurn())>::value);
    CHECK(std::is_void<decltype(game.printLog())>::value);
    CHECK(std::is_void<decltype(game.printStats())>::value);
    CHECK(std::is_void<decltype(game.playAll())>::value);
    CHECK(std::is_void<decltype(game.playTurn())>::value);
    CHECK(std::is_void<decltype(game.printWiner())>::value);

}
TEST_CASE("Test 13"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK(p1.cardesTaken()+ p2.cardesTaken() == 52);
}
TEST_CASE("Test 14"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    game.playTurn();
    game.playTurn();    
    game.playTurn();  
    int p1Num = p1.cardesTaken() + p2.stacksize();
    int p2Num = p2.cardesTaken() + p2.stacksize(); 
    CHECK( p1.stacksize()<23);
    CHECK( p2.stacksize()<23);
    CHECK(p1Num + p2Num == 52);
    CHECK((p2.cardesTaken() + p2.stacksize()) < 52);

}

