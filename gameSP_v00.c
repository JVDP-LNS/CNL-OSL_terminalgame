#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include "mygraphics.h"
//Large emerald, med ruby, hackmanite, small saph, tiny aqua

#define DRAW_OFFSETX 1
#define DRAW_OFFSETY 5
#define MAP_BORDER 1

//Global variables
int mapHeight = 9;
int mapWidth = 9;
char **map = NULL;

int gameStatus = 0; //0-Running | 1-GameOver | 2-Quit

char playerChar = '%';
char goalChar = '@';
char emptyChar = ' ';

int playerScore = 0;
int playerCoordsX = 0;
int playerCoordsY = 0;
char playerInput = '\0';

int goalCoordsX = 0;
int goalCoordsY = 0;

//Function Prototypes
void clearScreen();
void initMap();
void generateGoal();
void handlePlayerInput();
void draw();

int main() {
    srand(time(NULL));  //seed rand() generator for more randomness
    initMap();
    generateGoal();

    while(gameStatus == 0) {
        draw();
        handlePlayerInput();
    }
}

//----------

void initMap() {
    printf("Enter the MapHeight: ");
    scanf("%d", &mapHeight);
    printf("Enter the MapWidth: ");
    scanf("%d", &mapWidth);
    map = calloc(mapHeight, sizeof(char*));
    for(int i = 0; i < mapHeight; i++) {
        map[i] = calloc(mapWidth, sizeof(char));
        for(int j = 0; j < mapWidth; j++) {
            map[i][j] = emptyChar;
        }
    }
}
void generateGoal() {
    do {
        goalCoordsY = rand() % mapHeight;
        goalCoordsX = rand() % mapWidth;
    } while(goalCoordsY == playerCoordsY && goalCoordsX == playerCoordsX);
    map[goalCoordsY][goalCoordsX] = goalChar;
}
void handlePlayerInput() {
    map[playerCoordsY][playerCoordsX] = ' ';
    //TODO get player input and move char
    scanf("%c", &playerInput);
    switch (playerInput)
    {
    case 'w':
        playerCoordsY--;
        break;
    case 'a':
        playerCoordsX--;
        break;
    case 's':
        playerCoordsY++;
        break;
    case 'd':
        playerCoordsX++;
        break;
    case 'q':
        gameStatus = 2;
        break;
    default:
        break;
    }
    //Handle out of bounds
    if(playerCoordsY < 0 || playerCoordsY >= mapHeight || playerCoordsX < 0 || playerCoordsX >= mapWidth) {
        gameStatus = 0;
    }
    else {
        map[playerCoordsY][playerCoordsX] = playerChar;
    }
}
void draw() {
    //TODO using ANSI cursor moving
}
void draw_gameOver() {
	//TODO
}