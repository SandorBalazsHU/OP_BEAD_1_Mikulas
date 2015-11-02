#include <stdio.h>
#include <time.h>
#include "Gifts.h"

int main(int argc, char** argv){
	
	FILE * f;
	f=fopen("santa.data","rb");
	if (f==NULL)
	{
		perror("Hiba a file megnyitasa soran\n");
	}
	Gifts datas;
	while (!feof(f))
	{
		fread(&datas,sizeof(datas),sizeof(datas),f); 
	}
	//printf(datas.giftArray[0].name);*/
	Gift* a[2] = {};
	a[0] = newGift(1, time(NULL), "a", "aa", "aaa", BALL);
	a[1] = newGift(2, time(NULL), "b", "bb", "bbb", BALL);
	Gifts* b = newGifts(2, a);
	//Gift x = b->giftArray[0];
	//char* w = x->id;
	//printf(w);
	//fwrite(&b,sizeof(b),sizeof(b),f); 
	
	fclose(f);
	
	
	
	
	
	
	
	
	printf("***** A mikulas adminisztracios renszere! *****\n");
	printf("\n     1.) Uj level irasa \n     2.) Adminisztracio \n");
	

	
	char selectedMenuPoint = ' ';
	while( !((selectedMenuPoint == '1') || (selectedMenuPoint == '2')) )
	{
		if (selectedMenuPoint != ' ') printf("\n     Hibas ertek! \n");
		printf("     Valassz funkciot:");
		selectedMenuPoint = getchar();
	} 
		
	putchar(selectedMenuPoint);
}