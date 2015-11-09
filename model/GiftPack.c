//mallochoz sz�gs�ges
#include <stdlib.h>
#include <string.h>
#include "GiftPack.h"


//Aj�nd�kcsomag k�sz bemeneti t�mbb�l
/*	Eleve k�tszer akkora t�mb� hozunk l�tre (A C++ std::Vector szer� m�k�d�s miatt)*/
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

//Megadott m�get� �res aj�nd�kcsomag
/*	Eleve k�tszer akkora t�mb� hozunk l�tre (A C++ std::Vector szer� m�k�d�s miatt)*/
struct GiftPack* newGiftPackWidthSize(size_t size)
{
	struct GiftPack* this = malloc(sizeof(struct GiftPack));
	this -> size = size;
	this -> _realSize = size*2;
	Gift**  mallocGiftArray = malloc(this -> _realSize * sizeof(Gift*));
	this -> giftArray = mallocGiftArray;
	return this;
}

//�res aj�nd�kcsomag
struct GiftPack* newEmptyGiftPack()
{
	struct GiftPack* this = malloc(sizeof(struct GiftPack));
	this -> size = 0;
	this -> giftArray = NULL;
	return this;
}

//Aj�nd�k hozz�ad�s�t teszi lehet�ve egy aj�nd�kcsmaghoz
/*	Ha a csomagot reprezent�l� t�mb betelt,
	akkor dupla m�ret�t deklar�lunk, �tm�soljuk az adatokat �s a r�git t�r�lj�k.
	(C++ std::Vector szer� m�k�d�s)*/
void addGiftToPack(Gift* gift, GiftPack* giftPack)
{
	size_t i, uniqe = 0;
	for(i = 0; i < giftPack->size; ++i)
	{
		if(strcmp(giftPack->giftArray[i]->name,gift->name) == 0 )
		{
			uniqe = 1;
			printf("Te m�r k�ldt�l levelet!");
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

//Az aj�nd�kok t�pus destruktora
/*	Kell destrukfor, mivel a giftArray k�l�n �ll� egys�get
	k�pez a dinamikus mem�ri�ban, valamint a t�rolt aj�nd�kokat is t�r�lni kell*/
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