#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "Gifts.h"

Gift* newGift(size_t id, time_t date, char* name, char* city, char* address, giftTypes giftType)
{
	struct Gift* this = (struct Gift*) malloc(sizeof(struct Gift));
	this -> id = id;
	this -> date = date;
	this -> name = charCopyByValueToHeap(name);
	this -> city = charCopyByValueToHeap(city);
	this -> address = charCopyByValueToHeap(address);
	this -> giftType = giftType;
	return this;
}
Gifts* newGifts(size_t size, Gift** giftArray)
{
	struct Gifts* this = (struct Gifts*) malloc(sizeof(struct Gifts));
	Gift**  mallocGiftArray = malloc(size * sizeof(Gifts*));
	size_t i;
	for(i = 0; i < size; ++i)
	{
		mallocGiftArray[i] = giftArray[i];
	}
	this -> size = size;
	this -> giftArray = mallocGiftArray;
	return this;
}

Gifts* newEmptyGifts(size_t size)
{
	struct Gifts* this = (struct Gifts*) malloc(sizeof(struct Gifts));
	Gift**  mallocGiftArray = malloc(size * sizeof(Gifts*));
	this -> size = size;
	this -> giftArray = mallocGiftArray;
	return this;
}

Gift* newEmptyGift()
{
	struct Gift* this = (struct Gift*) malloc(sizeof(struct Gift));
	return this;
}

void GiftsWriterForBinFile(Gifts* gifts, FILE* f)
{
	fwrite(&gifts->size,sizeof(gifts->size),sizeof(gifts->size),f);
	size_t i;
	for(i = 0; i<gifts->size; ++i)
	{
		GiftWriterForBinFile(gifts->giftArray[i], f);
	}
}

void GiftWriterForBinFile(Gift* gift, FILE* f)
{
	fwrite(&gift->id,sizeof(gift->id),sizeof(gift->id),f);
	fwrite(&gift->date,sizeof(gift->date),sizeof(gift->date),f);
	stringWriterForBinFiles(gift->name, f);
	stringWriterForBinFiles(gift->city, f);
	stringWriterForBinFiles(gift->address, f);
	fwrite(&gift->giftType,sizeof(gift->giftType),sizeof(gift->giftType),f);
}

Gifts* GiftsReaderForBinFile(FILE* f)
{
	size_t size;
	fread(&size,sizeof(size),sizeof(size),f);
	Gifts* gifts = newEmptyGifts(size);
	size_t i;
	for(i = 0; i<size; ++i)
	{
			printf("__*__C\n");
		gifts->giftArray[i] = GiftReaderForBinFile(f);
	}
		printf("_____\n");
	return gifts;
}

Gift* GiftReaderForBinFile(FILE* f)
{
	Gift* gift = newEmptyGift();
	fread(&gift->id,sizeof(gift->id),sizeof(gift->id),f);
	fread(&gift->date,sizeof(gift->date),sizeof(gift->date),f);
		printf("~~*~~\n");
	gift->name = stringReaderForBinFiles(f);
		printf("~~~~~\n");
	gift->city = stringReaderForBinFiles(f);
		printf("~~~~~\n");
	gift->address = stringReaderForBinFiles(f);
		printf("~~~~~\n");
	fread(&gift->giftType,sizeof(gift->giftType),sizeof(gift->giftType),f);
		printf("~~~~~\n");
	return gift;
}

void stringWriterForBinFiles(char* str, FILE* f)
{
	size_t lenght = strlen(str);
	fwrite(&lenght,sizeof(lenght),sizeof(lenght),f);
	size_t i;
	for(i=0; i<=lenght; ++i)
	{
		fwrite(&str[i],sizeof(char),sizeof(char),f);
	}
}

char* stringReaderForBinFiles(FILE* f)
{
	size_t lenght;
	fread(&lenght,sizeof(lenght),sizeof(lenght),f);
		printf("^^*^^\n");
	char* str = (char*) malloc((lenght+1) * sizeof(char));
		printf("^^^^^\n");	
	size_t i;
		printf("^^^^^\n");
	for(i=0; i<=lenght; i++)
	{
			printf("^^^^^C\n");
		fread(&str[i],sizeof(char),sizeof(char),f);
	}
		printf(str);
		printf("\n");
		printf("^^^^^\n");
	return str;
}

char* charCopyByValueToHeap(char* inString)
{
	size_t stringLenght = strlen(inString);
	char* outString = (char*) malloc((stringLenght+1)*sizeof(char));
	size_t i;
	for(i=0; i<=stringLenght; ++i)
	{
		outString[i] = inString[i];
	}
	return outString;
}