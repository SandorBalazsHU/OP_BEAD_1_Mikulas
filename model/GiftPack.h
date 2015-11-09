#ifndef GIFTPACK_H
#define GIFTPACK_H

#include <stdio.h>
#include "Gift.h"

//Aj�nd�kok gy�jtem�ny�t modellez� adatszerkezet
/*
+------------------------+
|        GiftPack        |
| +--------------------+ |
| |     size_t size    | |
| +--------------------+ |
| +--------------------+ |
| |  size_t _realSize  | |
| +--------------------+ |
|                        |
| +--------------------+ |          +--------------------+
| |  Gift** giftArray  |===========>|     giftArray[]    |
| +--------------------+ |          | +----------------+ |
|                        |          | |      Gift*     | |
|                        |          | +----------------+ |
|                        |          | +----------------+ |
|                        |          | |      Gift*     | |
|                        |          | +----------------+ |
|                        |          | +----------------+ |
|                        |          | |      Gift*     | |
|                        |          | +----------------+ |
|                        |          |         ...        |
|                        |          +--------------------+
+------------------------+
*/
typedef struct GiftPack
{
	//Felvett aj�nd�kok sz�ma
	size_t size;
	//A t�rol� t�mb val�s m�rete
	size_t _realSize;
	//Aj�nd�kra mutat� pointerek t�mbje
	Gift** giftArray;
}GiftPack;

//Aj�nd�kcsomag k�sz bemeneti t�mbb�l
struct GiftPack* newGiftPack(size_t, Gift**);

//Megadott m�get� �res aj�nd�kcsomag
struct GiftPack* newGiftPackWidthSize(size_t);

//�res aj�nd�kcsomag
struct GiftPack* newEmptyGiftPack();

//Aj�nd�k hozz�ad�s�t teszi lehet�ve egy aj�nd�kcsmaghoz
/*	Ha a csomagot reprezent�l� t�mb betelt,
	akkor dupla m�ret�t deklar�lunk, �tm�soljuk az adatokat �s a r�git t�r�lj�k.*/
void addGiftToPack(Gift*, GiftPack* );

GiftPack* filterForCity(GiftPack*, char*);
GiftPack* filterForGiftType(GiftPack*, giftTypes);

//Az aj�nd�kok t�pus destruktora
/*	Kell destrukfor, mivel a giftArray k�l�n �ll� egys�get
	k�pez a dinamikus mem�ri�ban*/
void freeGiftPack(GiftPack*);

#endif