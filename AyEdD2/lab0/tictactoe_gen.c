#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (4 * 4 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[4][4])
{
    int cell = 0;

    print_sep(4);
    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 4; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(4);
    }
}
char get_winner(char board[4][4]){
    char winner='-';
    int n,m;
    for(n=0;n<4;n++){
        for (m=0;m<4;m++){
    //verificar si tienen los mismos valores las filas
        if(board[n][0]!='-' && board[n][0]==board[n][1] && board[n][1]==board[n][2] && board[n][2]==board[n][3]){
            return board[n][0];
            }
    //verificamos columnas
        if(board[0][m]!='-' && board[0][m]==board[1][m] && board[1][m]==board[2][m] && board[2][m]==board[3][m]){
            return board[0][m];
            }
    //verificamos la diagonal principal
        if(board[0][0]!='-' && board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]==board[3][3]){
            return board[0][0];
            }
    //verificamos la diagonal secundaria
        if(board[0][3]!='-' && board[0][3]==board[1][2] && board[1][2]==board[2][1] && board[2][1]==board[0][3]){
        return board[0][3];
            }
        }
    }
    return winner; //si no hay ganador
}

bool has_free_cell(char board[4][4]){
    bool free_cell=false;
    int n,m;
    for(n=0;n<4;n++){
        for(m=0;m<4;m++){
            if (board[n][m]=='-'){
                return true; //verifica si hay un lugar vacio en la matriz
            }
        }
    }
    return free_cell; //en caso contrario, entonces devolvera false, es decir que no estan vacias
}


int main(void){
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[4][4] = {
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 4;
            int colum = cell % 4;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
