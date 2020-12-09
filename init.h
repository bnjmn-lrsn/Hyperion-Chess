#ifndef INIT_H
#define INIT_H

#include <stdbool.h>

#include "defs.h"
#include "board.h"

U64 set_mask[64];
U64 clear_mask[64];

void InitializeBitmask(){
    int index = 0;
    for(index = 0; index < 64; index++){
        set_mask[index] = 0ull;
        clear_mask[index] = 0ull;
    }
    for(index = 0; index < 64; index++){
        set_mask[index] = 1ull << index;
        clear_mask[index] = ~set_mask[index];
    }
}

void InitializeAll() 
{
    InitSq120ToSq64Conversion();
    InitializeBitmask();
}


#endif

