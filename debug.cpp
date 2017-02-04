#include "debug.h"


void Test_all::run()
{
    Test_Monster_gold_game::run();
}

void Test_Creature::run()
{
    Creature o("orc", 'o', 4, 2, 10);
    o.addGold(5);
    o.reduceHealth(1);
    std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " 
        << o.getGold() << " gold." << std::endl;
}

void Test_Player::run()
{
    std::string input_name{ "Alex" };
    //std::cout << "Please enter your name -> ";
    //std::cin >> input_name;
    //assert(input_name != "" && "name cannot be empty...");

    Player test_player(input_name);
    std::cout << "Welcome, " << test_player.getName() << "." << std::endl;
    std::cout << "You have " << test_player.getHealth() << " health and are carrying "
        << test_player.getGold() << " gold." << std::endl;
}

void Test_Monster::run()
{
    for (int i = 0; i < 5; ++i) 
    {
        Monster m{ Monster::getRandomMonster() };
        std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created." << std::endl;
    }
}

void Test_Monster_gold_game::run()
{
    std::string input_name{ "Soli" };
    /*std::cout << "Please enter your name -> ";
    std::cin >> input_name;
    assert(input_name != "" && "name cannot be empty...");*/
    Monster_gold_game game(input_name);
    game.run();
}