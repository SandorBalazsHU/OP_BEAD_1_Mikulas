//time_t-hez szügséges
#include <time.h>
//strcpyhoz szügséges
#include <string.h>
//mallochoz szügséges
#include <stdlib.h>
#include "Gift.h"

//Ajándék létrehozása
struct Gift* newGift(size_t id, time_t date, char* name, char* city, char* address, char* text, giftTypes giftType)
{
	struct Gift* this = malloc(sizeof(struct Gift));
	this -> id = id;
	this -> date = date;
	this -> name = charCopyByValueToHeap(name);
	this -> city = charCopyByValueToHeap(city);
	this -> address = charCopyByValueToHeap(address);
	this -> text = charCopyByValueToHeap(text);
	this -> giftType = giftType;
	return this;
}

//Üres ajándék létrehozása
struct Gift* newEmptyGift()
{
	return malloc(sizeof(struct Gift));
}

//Az ajándék típus destruktora
void freeGift(Gift* gift)
{
	free(gift->name);
	free(gift->city);
	free(gift->address);
	free(gift->text);
	free(gift);
}
	
char* charCopyByValueToHeap(char* inString)
{
	size_t stringLenght = strlen(inString);
	char* outString = (char*) malloc((stringLenght+1)*sizeof(char));
	strcpy(outString,inString);
	return outString;
}