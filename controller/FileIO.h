#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED

#include <stdio.h>
#include "../model/Gift.h"
#include "../model/GiftPack.h"

void GiftPackWriterForBinFile(GiftPack*, FILE*);
void GiftWriterForBinFile(Gift*, FILE*);
void stringWriterForBinFiles(char*, FILE*);

GiftPack* GiftPackReaderForBinFile(FILE*, char*);
Gift* GiftReaderForBinFile(FILE*);
char* stringReaderForBinFiles(FILE*);

FILE* openFileForRead(char*);
FILE* openFileForWrite(char*);

int filesize(char*);
#endif