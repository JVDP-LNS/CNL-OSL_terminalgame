#include "temp.h"
#include<unistd.h>
#include<stdio.h>
#include<string.h>

void out(char msg[]) {
    write(1, msg, strlen(msg));
}

void setCurX(int y) {
    char msg[16];
    sprintf(msg, "\e[%dGya", y+1);
    out(msg);
}
void setCurXY(int x, int y) {
    char msg[16];
    sprintf(msg, "\e[%d;%dH", x+1, y+1);
    out(msg);
}
void moveCurX(int x) {
    char msg[16];
    sprintf(msg, "\e[%dC", x);
    out(msg);
}
void moveCurY(int y) {
    char msg[16];
    sprintf(msg, "\e[%dB", y);
    out(msg);
}

void sgrUnderline() {
    char msg[16];
    sprintf(msg, "\e[4m");
    out(msg);
}
void sgrReverse() {
    char msg[16];
    sprintf(msg, "\e[7m");
    out(msg);
}

void sgrCurColor(int color) {
    char msg[16];
    sprintf(msg, "\e[3%dm", color);
    out(msg);
}
void sgrCurColorBright(int color) {
    char msg[16];
    sprintf(msg, "\e[9%dm", color);
    out(msg);
}
void sgrBGColor(int color) {
    char msg[16];
    sprintf(msg, "\e[4%dm", color);
    out(msg);
}
void sgrBGColorBright(int color) {
    char msg[16];
    sprintf(msg, "\e[10%dm", color);
    out(msg);
}