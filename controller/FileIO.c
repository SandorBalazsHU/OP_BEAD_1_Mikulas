#include <stdio.h>
#include <string.h>
//mallochoz szügséges
//#include <stdlib.h>
#include "../model/Gift.h"
#include "../model/GiftPack.h"
#include "FileIO.h"

void GiftPackWriterForBinFile(GiftPack* giftPack, FILE* f)
{
	int a = (int) giftPack->size;
	fwrite(&a,sizeof(a),1,f);
	int i;
	for(i = 0; i<giftPack->size; ++i)
	{
		GiftWriterForBinFile(giftPack->giftArray[i], f);
	}
}

void GiftWriterForBinFile(Gift* gift, FILE* f)
{
	fwrite(&gift->id,sizeof(gift->id),1,f);
	fwrite(&gift->date,sizeof(gift->date),1,f);
	stringWriterForBinFiles(gift->name, f);
	stringWriterForBinFiles(gift->city, f);
	stringWriterForBinFiles(gift->address, f);
	stringWriterForBinFiles(gift->text, f);
	fwrite(&gift->giftType,sizeof(gift->giftType),1,f);
}

void stringWriterForBinFiles(char* str, FILE* f)
{
	int stringLenght = (int) strlen(str);
	fwrite(&stringLenght,sizeof(stringLenght),1,f);
	int i;
	for(i=0; i<=stringLenght; ++i)
	{
		fwrite(&str[i],sizeof(char),1,f);
	}
}





GiftPack* GiftPackReaderForBinFile(FILE* f, char* name)
{
	if(filesize(name) > 0)
	{
		int size;
		fread(&size,sizeof(size),1,f);
		GiftPack* giftPack = newGiftPackWidthSize(size);
		int i;
		for(i = 0; i<size; ++i)
		{
			giftPack->giftArray[i] = GiftReaderForBinFile(f);
		}
		return giftPack;
	}
	else
	{
		GiftPack* giftPack = newGiftPackWidthSize(1);
		giftPack->size = 0;
		return giftPack;
	}
}

Gift* GiftReaderForBinFile(FILE* f)
{
	Gift* gift = newEmptyGift();
	fread(&gift->id,sizeof(gift->id),1,f);
	fread(&gift->date,sizeof(gift->date),1,f);
	gift->name = stringReaderForBinFiles(f);
	gift->city = stringReaderForBinFiles(f);
	gift->address = stringReaderForBinFiles(f);
	gift->text = stringReaderForBinFiles(f);
	fread(&gift->giftType,sizeof(gift->giftType),1,f);
	return gift;
}

char* stringReaderForBinFiles(FILE* f)
{
	int stringLenght;
	fread(&stringLenght,sizeof(stringLenght),1,f);
	char tmpString[stringLenght+1];
	int i;
	for(i=0; i<=stringLenght; ++i)
	{
		fread(&tmpString[i],sizeof(char),1,f);
	}
	return charCopyByValueToHeap(tmpString);
}


FILE* openFileForWrite(char* name)
{
	FILE* f;
	f=fopen(name,"wb+");
	if (f==NULL)
	{
		printf("Hiba az írásra nyitás során\n");
	}
	return f;
}

FILE* openFileForRead(char* name)
{
	FILE* f;
	f=fopen(name,"rb");
	if (f==NULL)
	{
		f=fopen(name,"wb+");  if (f==NULL) printf("Nem sikerült létrehozni a filet!\n");
		fclose(f);
		f=fopen(name,"rb");   if (f==NULL) printf("HIBA!\n");
	}
	return f;
}
int filesize(char* name)
{
	FILE* f = openFileForRead(name);
	fseek(f, 0, SEEK_END);
	return(ftell(f));
	fclose(f);
}