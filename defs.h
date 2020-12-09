#ifndef defs_h
#define defs_h

#include <stdbool.h>

//types
typedef unsigned long long U64;

//macros
#define NAME "Hyperion"
#define NUMBER_OF_SQUARES 120
#define NUMBER_LEGAL_SQUARES 64
#define MAX_NUMBER_MOVES 2048 //this is max number of half-moves (plies), so the actual max moves is 1024

#define CLRBIT(bb,sq) ((bb) &= clear_mask[(sq)])
#define SETBIT(bb,sq) ((bb) |= set_mask[(sq)])

#define DEBUG
#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed ", #n); \
printf("On %s ", __DATE__); \
printf("At %s ", __TIME__); \
printf("In file %s ", __FILE__); \
printf("At Line %d\n", __LINE__); \
exit(1);}
#endif

//enums
enum{ EMPTY, WP, WN, WB, WR, WQ, WK, BP, BN, BB, BR, BQ, BK };

enum{ FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, NO_FILE };

enum{ RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, NO_RANK };

enum{ WHITE, BLACK, BOTH };

enum
{
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2 ,E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4 ,D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQUARE
};

enum { FALSE, TRUE };

enum
{ 
    WHITE_KING_CASTLING = 1, WHITE_QUEEN_CASTLING = 2, BLACK_KING_CASTLING = 4, BLACK_QUEEN_CASTLING = 8 
};

//functions
extern void InitializeAll();
extern void PrintBitBoard(U64 bitboard);
extern int PopBit(U64 *bitboard);
extern int CountBits(U64 bitboard);

//variables
extern int sq64_to_sq120[NUMBER_LEGAL_SQUARES];
extern int sq120_to_sq64[NUMBER_OF_SQUARES];
extern U64 set_mask[64];
extern U64 clear_mask[64];   

#endif