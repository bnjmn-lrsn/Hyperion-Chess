#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <stdlib.h>

#include "defs.h"

int sq64_to_sq120[NUMBER_LEGAL_SQUARES];
int sq120_to_sq64[NUMBER_OF_SQUARES];

typedef struct 
{
    int move;
    int castle_permission;
    int enpassant_square;
    int fifty_move_counter;
    U64 position_key;

} S_UNDO;

typedef struct 
{
    int pieces[NUMBER_OF_SQUARES];

    U64 pawns[3];//0 white, 1 black, 2 both

    int king_squares[2];// king_squares[0] is the location of the white king, [1] the location of the black king

    int side_to_move;

    int enpassant_square;

    int fifty_move_counter;

    int castle_permission;

    int current_number_ply;
    int number_ply_played;

    U64 position_key;

    int piece_number_by_type[13];// the number at piece_number_by_type[1] is the number of white pawns, [2] is the number of white knights, etc...
    int number_pieces[3]; //anything that isn't a pawn
    int number_minor_pieces[3];//knights and bishops
    int number_major_pieces[3];//rooks and queens

    S_UNDO game_history[MAX_NUMBER_MOVES];

    int piece_list[13][10];

} S_BOARD;

void InitSq120ToSq64Conversion()
{
    int index = 0;
    int file = FILE_A;
    int rank = RANK_1;

    int sq120 = A1;
    int sq64 = 0;

    for(index = 0; index < NUMBER_OF_SQUARES; ++index)
    {
        sq120_to_sq64[index] = 65;
    }

    for(index = 0; index < NUMBER_LEGAL_SQUARES; ++index)
    {
        sq64_to_sq120[index] = 120;
    }

    for(rank = RANK_1; rank <= RANK_8; ++rank)
    {
        for(file = FILE_A; file <= FILE_H; ++file)
        {
            sq120 = ((21 + file) + (rank * 10));
            sq64_to_sq120[sq64] = sq120;
            sq120_to_sq64[sq120] = sq64;
            sq64++;
        }
    }

}

bool IsValidSquare(int coordinate)
{
    return coordinate >=0 && coordinate <= 63;
}

#endif