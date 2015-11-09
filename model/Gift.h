#ifndef GIFT_H_INCLUDED
#define GIFT_H_INCLUDED

//time_t-hez szügséges
#include <time.h>

//Az ajándékok fajtáit jelképező enumerátor
typedef enum {BABY, BALL, CAR, COLORINGBOOK, PUZZLE, BOOK} giftTypes;

//Egy ajándék modellezésére szolgáló szerkezet
/*
+------------------------+
|          Gift          |
| +--------------------+ |
| |      size_t id     | |
| +--------------------+ |
|                        |
| +--------------------+ |
| |     time_t date    | |
| +--------------------+ |
|                        |
| +--------------------+ |
| |       name[]       | |
| | +----------------+ | |
| | |      Char      | | |
| | +----------------+ | |
| | +----------------+ | |
| | |      Char      | | |
| | +----------------+ | |
| |         ...        | |
| +--------------------+ |
| +--------------------+ |
| |       city[]       | |
| | +----------------+ | |
| | |      Char      | | |
| | +----------------+ | |
| |         ...        | |
| +--------------------+ |
| +--------------------+ |
| |      address[]     | |
| | +----------------+ | |
| | |      Char      | | |
| | +----------------+ | |
| |         ...        | |
| +--------------------+ |
|                        |
| +--------------------+ |
| |     time_t date    | |
| +--------------------+ |
|                        |
+------------------------+
*/
typedef struct Gift
{
	size_t id;
	time_t date;
	char* name;
	char* city;
	char* address;
	char* text;
	giftTypes giftType;
} Gift;

//Ajándék létrehozása
struct Gift* newGift(size_t, time_t, char*, char*, char*, char*, giftTypes);

//Üres ajándék létrehozása
struct Gift* newEmptyGift();

//Az ajándék típus destruktora
void freeGift(Gift*);

char* charCopyByValueToHeap(char*);
#endif