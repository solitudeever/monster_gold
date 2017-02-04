#pragma once
#include "common_lib.h"
#include "class_Creature.h"
#include "class_Player.h"
#include "class_Monster.h"
#include "class_Random_int.h"


class Monster_gold_game
{
private:
    // the result of a fight
    enum Encounter_result
    {
        PLAYER_FLED,
        PLAYER_WIN,
        PLAYER_DEAD,
        MAX_ENCOUNTER_RESULT,
    };
    // members and initial setting
    Player m_player;
    const int MAX_LEVEL{ 20 };
    const int FLEE_CHANCE{ 50 };
    const int LEVEL_UP_ATK_GAIN{ 1 };
    const int LEVEL_UP_HP_GAIN{ 2 };

    // an encounter
    Encounter_result encounter();
    // get user choice
    std::string get_input();
    // player and monster's attack, no death check
    void attack(Creature& attacker, Creature& attacked);
    // player level up
    void level_up(Creature& creature);
public:
    Monster_gold_game(std::string player_name) :
        m_player(Player(player_name))
    {}

    // the main game code
    void run();
};