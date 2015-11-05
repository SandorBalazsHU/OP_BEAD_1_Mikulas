#ifndef GIFTS_H
#define GIFTS_H

#include <stdio.h>
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
	Gift** giftArray;
} Gifts;

Gift* newGift(size_t, time_t, char*, char*, char*, giftTypes);
Gifts* newGifts(size_t, Gift**);
void GiftsWriterForBinFile(Gifts*, FILE*);
void GiftWriterForBinFile(Gift*, FILE*);
Gifts* GiftsReaderForBinFile(FILE*);
Gift* GiftReaderForBinFile(FILE*);
void stringWriterForBinFiles(char*, FILE*);
char* stringReaderForBinFiles(FILE*);
char* charCopyByValueToHeap(char*);
Gifts* newEmptyGifts(size_t);
Gift* newEmptyGift();

#endif