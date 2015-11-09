//mallochoz szügséges
#include <stdlib.h>
#include <string.h>
#include "GiftPack.h"


//Ajándékcsomag kész bemeneti tömbbõl
/*	Eleve kétszer akkora tömbö hozunk létre (A C++ std::Vector szerû mûködés miatt)*/
struct GiftPack* newGiftPack(size_t size, Gift** giftArray)
{
	struct GiftPack* this = malloc(sizeof(struct GiftPack));
	this -> size = size;
	this -> _realSize = size*2;
	Gift**  mallocGiftArray = malloc(this -> _realSize * sizeof(Gift*));
	size_t i;
	for(i = 0; i < size; ++i)
	{
		mallocGiftArray[i] = giftArray[i];
	}
	this -> giftArray = mallocGiftArray;
	return this;
}

//Megadott mégetû üres ajándékcsomag
/*	Eleve kétszer akkora tömbö hozunk létre (A C++ std::Vector szerû mûködés miatt)*/
struct GiftPack* newGiftPackWidthSize(size_t size)
{
	struct GiftPack* this = malloc(sizeof(struct GiftPack));
	this -> size = size;
	this -> _realSize = size*2;
	Gift**  mallocGiftArray = malloc(this -> _realSize * sizeof(Gift*));
	this -> giftArray = mallocGiftArray;
	return this;
}

//Üres ajándékcsomag
struct GiftPack* newEmptyGiftPack()
{
	struct GiftPack* this = malloc(sizeof(struct GiftPack));
	this -> size = 0;
	this -> giftArray = NULL;
	return this;
}

//Ajándék hozzáadását teszi lehetõve egy ajándékcsmaghoz
/*	Ha a csomagot reprezentáló tömb betelt,
	akkor dupla méretût deklarálunk, átmásoljuk az adatokat és a régit töröljük.
	(C++ std::Vector szerû mûködés)*/
void addGiftToPack(Gift* gift, GiftPack* giftPack)
{
	size_t i, uniqe = 0;
	for(i = 0; i < giftPack->size; ++i)
	{
		if(strcmp(giftPack->giftArray[i]->name,gift->name) == 0 )
		{
			uniqe = 1;
			printf("Te már küldtél levelet!");
			break;
		}
	}
	
	if(uniqe == 0)
	{
		if(giftPack->_realSize > giftPack->size)
		{
			giftPack->giftArray[giftPack->size] = gift;
			giftPack->size++;
		}
		else
		{
			giftPack -> _realSize *= 2;
			Gift**  mallocGiftArray = malloc(giftPack -> _realSize * sizeof(Gift*));
			size_t i;
			for(i = 0; i < giftPack->size; ++i)
			{
				mallocGiftArray[i] = giftPack->giftArray[i];
			}
			Gift** arr = giftPack -> giftArray;
			free(arr);
			giftPack -> giftArray = mallocGiftArray;
			
			giftPack->giftArray[giftPack->size] = gift;
			giftPack->size++;
		}
	}
}

GiftPack* filterForCity(GiftPack* oldGiftPack, char* city)
{
	size_t i, j = 0;
	Gift*  giftArray[oldGiftPack->size];
	for(i = 0; i < oldGiftPack->size; ++i)
	{
		if(strcmp(oldGiftPack->giftArray[i]->city,city) == 0 )
		{
			giftArray[j] = oldGiftPack->giftArray[i];
			++j;
		}
	}
	return newGiftPack(j,giftArray);
}
GiftPack* filterForGiftType(GiftPack* oldGiftPack, giftTypes giftType)
{
	size_t i, j = 0;
	Gift*  giftArray[oldGiftPack->size];
	for(i = 0; i < oldGiftPack->size; ++i)
	{
		if(oldGiftPack->giftArray[i]->giftType == giftType)
		{
			giftArray[j] = oldGiftPack->giftArray[i];
			++j;
		}
	}
	return newGiftPack(j,giftArray);
}

//Az ajándékok típus destruktora
/*	Kell destrukfor, mivel a giftArray külön álló egységet
	képez a dinamikus memóriában, valamint a tárolt ajándékokat is törölni kell*/
void freeGiftPack(GiftPack* giftPack)
{
	size_t i;
	for(i = 0; i < giftPack->size; ++i)
	{
		free(giftPack->giftArray[i]);
	}
	free(giftPack->giftArray);
	free(giftPack);
}