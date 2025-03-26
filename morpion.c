#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define SIZE 3

char board[SIZE][SIZE];
int cursorX = 0, cursorY = 0;

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    system("clear"); // Utiliser "cls" sous Windows
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (cursorX == j && cursorY == i) {
                printf("[%c]", board[i][j]);
            } else {
                printf(" %c ", board[i][j]);
            }
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
}

int checkWin() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void moveCursor() {
    char ch;
    while (1) {
        ch = getch();
        if (ch == 27) {
            getch();
            ch = getch();
            switch (ch) {
                case 'A': if (cursorY > 0) cursorY--; break;
                case 'B': if (cursorY < SIZE - 1) cursorY++; break;
                case 'D': if (cursorX > 0) cursorX--; break;
                case 'C': if (cursorX < SIZE - 1) cursorX++; break;
            }
        } else if (ch == 10) {
            if (board[cursorY][cursorX] == ' ') return;
        }
        printBoard();
    }
}

void botMove(char symbol) {
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (board[y][x] != ' ');
    board[y][x] = symbol;
}

void playGame(int mode) {
    char player = 'X', bot = 'O';
    int moves = 0, maxMoves = SIZE * SIZE;
    initBoard();
    printBoard();
    
    while (moves < maxMoves) {
        if (mode == 1 || (mode == 2 && player == 'X')) {
            moveCursor();
            board[cursorY][cursorX] = player;
        } else {
            botMove(player);
        }
        moves++;
        printBoard();
        if (checkWin()) {
            printf("%c wins!\n", player);
            return;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    printf("It's a draw!\n");
}

int main() {
    srand(time(NULL));
    int mode = 1;
    system("clear");
    printf("Use arrows to choose mode, Enter to confirm:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs Bot\n");
    printf("3. Bot vs Bot\n");
    
    while (1) {
        char ch = getch();
        if (ch == 10) break;
        if (ch == 27) {
            getch();
            ch = getch();
            if (ch == 'A' && mode > 1) mode--;
            if (ch == 'B' && mode < 3) mode++;
            system("clear");
            printf("Use arrows to choose mode, Enter to confirm:\n");
            printf("1. Player vs Player %s\n", mode == 1 ? "<--" : "");
            printf("2. Player vs Bot %s\n", mode == 2 ? "<--" : "");
            printf("3. Bot vs Bot %s\n", mode == 3 ? "<--" : "");
        }
    }
    playGame(mode);
    return 0;
}
