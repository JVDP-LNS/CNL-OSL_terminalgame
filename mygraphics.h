#ifndef TEMP_H
#define TEMP_H

void out(char msg[]);

void setCurX(int x);
void setCurXY(int x, int y);
void moveCurX(int x);
void moveCurY(int y);

void sgrUnderline();
void sgrReverse();         //Swap Cursor and BG colors

void sgrCurColor(int color); //From 0, black,R,G,Y,B,Magenta,Cyan,White
void sgrCurColorBright(int color); //From 0, black,R,G,Y,B,Magenta,Cyan,White
void sgrBGColor(int color); //From 0, black,R,G,Y,B,Magenta,Cyan,White
void sgrBGColorBright(int color); //From 0, black,R,G,Y,B,Magenta,Cyan,White

#endif