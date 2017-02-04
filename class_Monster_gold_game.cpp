#include "class_Monster_gold_game.h"



Monster_gold_game::Encounter_result Monster_gold_game::encounter()
{
    Monster mon{ Monster::getRandomMonster() };
    std::string input;
    bool monster_dead{ false };

    std::cout << "You have encountered a " << mon.getName()
        << " (" << mon.getSymbol() << ")." << std::endl;
    std::cout << "Your currently have gold: " << m_player.getGold() << std::endl;

    // The fighting loop
    // Can exit by win, flee or die
    while (true)
    {
        std::cout << "Your hp: " << m_player.getHealth() << " vs "
            << "The " << mon.getName() << "'s hp: " << mon.getHealth() << std::endl;

        // get player choice
        if ((input = get_input()) == "r")
            // if choose to flee
        {
            // check if successfully fled
            if (Random_int::gen(1, 100) <= FLEE_CHANCE)
            {
                std::cout << "You successfully fled." << std::endl;
                return PLAYER_FLED;
            }
            // failed -> be attacked
            else
            {
                std::cout << "You failed to flee." << std::endl;
                attack(mon, m_player);
            }
        }
        else if (input == "f")
            // if choose to fight
        {
            attack(m_player, mon);
            if (mon.is_dead())
            {
                monster_dead = true;
            }
            else
            {
                attack(mon, m_player);
            }
        }
        else
        {
            std::cout << "Unexpected input o.O" << std::endl;
            throw std::runtime_error("Unexpected input");
        }

        // gain gold and level up if monster is dead, then return
        if (monster_dead)
        {
            std::cout << mon.getName() << " is dead!" << std::endl;

            // gain gold
            int gold_gain{ mon.getGold() };
            m_player.addGold(gold_gain);
            std::cout << m_player.getName() << " got " << gold_gain << " gold." << std::endl;

            // level up
            level_up(m_player);
            m_player.level_up();
            std::cout << m_player.getName() << " leveled up to level " << m_player.getLevel()
                << "!" << std::endl;

            return PLAYER_WIN;
        }

        // if player is dead
        if (m_player.is_dead())
        {
            return PLAYER_DEAD;
        }

        // add some space between turns
        std::cout << std::endl;
    }
}

std::string Monster_gold_game::get_input()
{
    std::string input;
    while (true)
    {
        std::cout << "(R)un or (F)ight -> ";
        std::getline(std::cin, input);
        if (input == "R" || input == "r")
        {
            return "r";
        }
        else if (input == "F" || input == "f")
        {
            return "f";
        }
        else
        {
            std::cout << "What was that? o.O" << std::endl;
            continue;
        }
    }
}

void Monster_gold_game::attack(Creature& attacker, Creature& attacked)
{
    int damage = attacker.getAtk();
    attacked.reduceHealth(damage);
    std::cout << attacker.getName() << " hit " << attacked.getName() << " for "
        << damage << " damage." << std::endl;
}

void Monster_gold_game::level_up(Creature& creature)
{
    creature.addAtk(LEVEL_UP_ATK_GAIN).addHp(LEVEL_UP_HP_GAIN, true);
}

void Monster_gold_game::run()
{
    std::cout << "Welcome, " << m_player.getName() << std::endl;
    // discard the first rand value, due to Visual Studio
    rand();

    while (true)
    {
        Encounter_result outcome{ encounter() };

        // Check if end_game conditions met
        // Condition 1: player got max level
        if (m_player.getLevel() == MAX_LEVEL)
        {
            std::cout << "\nYou got max level, and carried your " << m_player.getGold()
                << " gold to your hometown and got married and lived a happy life thereafter."
                << std::endl;
            return;
        }
        // Condition 2: player dead
        if (outcome == PLAYER_DEAD)
        {
            std::cout << "\nYou died at level " << m_player.getLevel() << " and with "
                << m_player.getGold() << " gold.\n"
                << "Too bad you can't take it with you!" << std::endl;
            return;
        }

        // add a line between encounters
        std::cout << "\n----------------------------\n" << std::endl;
    }
}
