#ifndef GIFTS_H
#define GIFTS_H

#include <time.h>

typedef enum {BABY, BALL, CAR, COLORINGBOOK, PUZZLE, BOOK} giftTypes;

typedef struct Gift
{
	size_t id;
	time_t date;
	char* name;
	char* city;
	char* address;
	giftTypes giftType;
} Gift;

typedef struct Gifts
{
	size_t size;
	Gift* giftArray;
} Gifts;

Gift* newGift(size_t, time_t, char*, char*, char*, giftTypes);
Gifts* newGifts(size_t, Gift*);

#endif