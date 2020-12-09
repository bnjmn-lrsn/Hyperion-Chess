#include <stdio.h>
#include <stdbool.h>

#include "defs.h"
#include "board.h"
#include "init.h"
#include "bitboards.h"

int main()
{
    InitializeAll();

    U64 play_bit_board = 0ull;

    PrintBitBoard(play_bit_board);

    play_bit_board |= (1ull << sq120_to_sq64[C2]);

    play_bit_board |= (1ull << sq120_to_sq64[D2]);

    play_bit_board |= (1ull << sq120_to_sq64[E2]);

    PrintBitBoard(play_bit_board);
    
    int count = CountBits(play_bit_board);
    printf("Number of bits sets: %d\n", count);

    int index = PopBit(&play_bit_board);
    printf("the index popped from the board: %d\n", index);

    PrintBitBoard(play_bit_board);

    return 0;
}