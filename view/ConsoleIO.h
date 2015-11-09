#ifndef CONSOLEIO_H_INCLUDED
#define CONSOLEIO_H_INCLUDED

//time_t-hez szügséges
#include <time.h>
//strcpyhoz szügséges
#include <string.h>
#include <stdio.h>
#include "../model/Gift.h"
#include "../model/GiftPack.h"

void dateOut(time_t date);
int getConsoleWindowWidth();
inline void printIntro();
inline void printMainMenu();
char mainManu();
inline void clearScrean();
void readFromConsole(char*, char, char*, int);
void printRecord(Gift*);

inline void printSubMenu();
char subManu();
inline void printGiftPack(GiftPack*);
inline giftTypes getGiftTypeFromConsole();
inline void vaitFromToken(char token);

#endif