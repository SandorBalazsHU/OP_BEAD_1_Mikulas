//time_t-hez sz�gs�ges
#include <time.h>
//strcpyhoz sz�gs�ges
#include <string.h>
//mallochoz sz�gs�ges
#include <stdlib.h>
#include "Gift.h"

//Aj�nd�k l�trehoz�sa
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

//�res aj�nd�k l�trehoz�sa
struct Gift* newEmptyGift()
{
	return malloc(sizeof(struct Gift));
}

//Az aj�nd�k t�pus destruktora
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