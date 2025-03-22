#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 20
#define PIPE_WIDTH 3
#define GAP_HEIGHT 5

int birdY, pipeX, pipeGapY, score;
int gameOver;

void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawBorder() {
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        gotoxy(i, 0); printf("-");
        gotoxy(i, SCREEN_HEIGHT - 1); printf("-");
    }
    for (int i = 1; i < SCREEN_HEIGHT - 1; i++) {
        gotoxy(0, i); printf("|");
        gotoxy(SCREEN_WIDTH - 1, i); printf("|");
    }
}

void drawBird() {
    gotoxy(5, birdY);
    printf("@");
}

void drawPipe() {
    for (int i = 1; i < pipeGapY; i++) {
        gotoxy(pipeX, i);
        printf("|");
    }
    for (int i = pipeGapY + GAP_HEIGHT; i < SCREEN_HEIGHT - 1; i++) {
        gotoxy(pipeX, i);
        printf("|");
    }
}

void clearScreen() {
    system("cls");
}

void update() {
    // Apply gravity
    birdY++;

    // Move pipe left
    pipeX--;

    // Check for collision with ground or top
    if (birdY <= 1 || birdY >= SCREEN_HEIGHT - 2) {
        gameOver = 1;
    }

    // Check for collision with pipe
    if (pipeX == 5 && (birdY < pipeGapY || birdY > pipeGapY + GAP_HEIGHT)) {
        gameOver = 1;
    }

    // Reset pipe if it goes off-screen
    if (pipeX <= 0) {
        pipeX = SCREEN_WIDTH - 1;
        pipeGapY = rand() % (SCREEN_HEIGHT - GAP_HEIGHT - 2) + 1;
        score++;
    }
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == ' ' || key == 'w') {
            birdY -= 3; // Move bird up
        }
    }
}

void gameLoop() {
    while (!gameOver) {
        clearScreen();
        drawBorder();
        drawBird();
        drawPipe();
        gotoxy(SCREEN_WIDTH / 2 - 5, 0);
        printf("Score: %d", score);

        input();
        update();
        Sleep(100); // Control game speed
    }
}

void resetGame() {
    birdY = SCREEN_HEIGHT / 2;
    pipeX = SCREEN_WIDTH - 1;
    pipeGapY = rand() % (SCREEN_HEIGHT - GAP_HEIGHT - 2) + 1;
    score = 0;
    gameOver = 0;
}

int main() {
    resetGame();
    gameLoop();
    gotoxy(SCREEN_WIDTH / 2 - 5, SCREEN_HEIGHT / 2);
    printf("Game Over! Score: %d", score);
    getch();
    return 0;
}
