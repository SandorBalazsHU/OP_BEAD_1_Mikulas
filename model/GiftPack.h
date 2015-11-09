#ifndef GIFTPACK_H
#define GIFTPACK_H

#include <stdio.h>
#include "Gift.h"

//Ajándékok gyûjteményét modellezõ adatszerkezet
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
	//Felvett ajándékok száma
	size_t size;
	//A tároló tömb valós mérete
	size_t _realSize;
	//Ajándékra mutató pointerek tömbje
	Gift** giftArray;
}GiftPack;

//Ajándékcsomag kész bemeneti tömbbõl
struct GiftPack* newGiftPack(size_t, Gift**);

//Megadott mégetû üres ajándékcsomag
struct GiftPack* newGiftPackWidthSize(size_t);

//Üres ajándékcsomag
struct GiftPack* newEmptyGiftPack();

//Ajándék hozzáadását teszi lehetõve egy ajándékcsmaghoz
/*	Ha a csomagot reprezentáló tömb betelt,
	akkor dupla méretût deklarálunk, átmásoljuk az adatokat és a régit töröljük.*/
void addGiftToPack(Gift*, GiftPack* );

GiftPack* filterForCity(GiftPack*, char*);
GiftPack* filterForGiftType(GiftPack*, giftTypes);

//Az ajándékok típus destruktora
/*	Kell destrukfor, mivel a giftArray külön álló egységet
	képez a dinamikus memóriában*/
void freeGiftPack(GiftPack*);

#endif