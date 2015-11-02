#include <time.h>
#include <stdio.h>
#include "Gifts.h"

Gift* newGift(size_t id, time_t date, char* name, char* city, char* address, giftTypes giftType)
{
	struct Gift* this = (struct Gift*) malloc(sizeof(struct Gift));
	this -> id = id;
	this -> date = date;
	this -> name = name;
	this -> city = city;
	this -> address = address;
	this -> giftType = giftType;
	return this;
}
Gifts* newGifts(size_t size, Gift* giftArray)
{
	struct Gifts* this = (struct Gifts*) malloc(sizeof(struct Gifts));
	Gift*  mallocGiftArray = malloc(size * sizeof(Gifts));
	int i;
	for(i = 0; i < size; ++i)
	{
		mallocGiftArray[i] = giftArray[i];
	}
	this -> size = size;
	this -> giftArray = mallocGiftArray;
	return this;
}