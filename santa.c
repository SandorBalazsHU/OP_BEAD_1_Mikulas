#include <stdio.h>
#include <time.h>
#include "Gifts.h"

int main(int argc, char** argv){
	
	Gift* a[2] = {};
	a[0] = newGift(1, time(NULL), "korte", "aa", "aaa", BALL);
	a[1] = newGift(2, time(NULL), "barack", "bb", "bbb", BALL);
	Gifts* b = newGifts(2, a);
	FILE* f;
	f=fopen("santa.data","wb+");
	if (f==NULL){perror("Hiba a file megnyitasa soran\n");}
	GiftsWriterForBinFile(b, f);
	fclose(f);
	
	f=NULL;
	f=fopen("santa.data","rb");
	if (f==NULL){perror("Hiba a file megnyitasa soran\n");}
	printf("--*--\n");
	Gifts* c = GiftsReaderForBinFile(f);
	printf("-----\n");
	fclose(f);
	printf("-----\n");
	printf(c->giftArray[0]->name);
	printf("-----\n");
	
	
	
	
	printf("\n***** A mikulas adminisztracios renszere! *****\n");
	printf("\n     1.) Uj level irasa \n     2.) Adminisztracio \n");
	char selectedMenuPoint = ' ';
	while( !((selectedMenuPoint == '1') || (selectedMenuPoint == '2')) )
	{
		if (selectedMenuPoint != ' ') printf("\n     Hibas ertek! \n");
		printf("     Valassz funkciot:");
		selectedMenuPoint = getchar();
	} 
		
	putchar(selectedMenuPoint);
	return 0;
}