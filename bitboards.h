#include <stdio.h>

#include "defs.h"

const int BitTable[64] = {
  63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
  51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
  26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
  58, 20, 37, 17, 36, 8
};

int PopBit(U64 *bitboard){
    U64 bit = *bitboard ^ (*bitboard - 1);
    unsigned int fold = (unsigned) ((bit & 0xffffffff) ^ (bit >> 32));
    *bitboard &= (*bitboard - 1);
    return BitTable[(fold * 0x783a9b23) >> 26];
}

int CountBits(U64 bitboard){
    int sum;
    for(sum = 0; bitboard; sum++, bitboard &= bitboard - 1);
    return sum;
}

void PrintBitBoard(U64 bitboard){
    U64 shift_me = 1ull;

    int rank = 0;
    int file = 0;
    int square = 0;
    int sqaure64 = 0;

    printf("\n");
    for(rank = RANK_8; rank >= RANK_1; --rank)
    {
        for(file = FILE_A; file <= FILE_H; ++file)
        {
            square = (21 + file) + (10 * rank);
            sqaure64 = sq120_to_sq64[square];
            if((shift_me << sqaure64) & bitboard)
            {
                printf("X");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("\n");
}