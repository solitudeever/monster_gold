#include "class_Monster.h"


// initialize statics
const Monster::Monster_data Monster::mon_arr[MAX_MON_TYPES]
{
    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 },
};