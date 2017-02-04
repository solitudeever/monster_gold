#include "class_Monster.h"


// initialize statics
const Monster::Monster_data Monster::mon_arr[MAX_MON_TYPES]
{
    /* Containing all monster data
     * When adding a monster: also add it in the enum: Monster_type
     */

    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 },
};

Monster Monster::getRandomMonster()
{
    /* return a random monster in monster_type */

    int index = Random_int::gen(0, Monster::MAX_MON_TYPES - 1);
    return Monster(static_cast<Monster_type>(index));
}