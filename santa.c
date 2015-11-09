#include <stdio.h>
#include <string.h>
#include "model/GiftPack.h"
#include "model/Gift.h"
#include "controller/FileIO.h"
#include "view/ConsoleIO.h"

int main(int argc, char** argv)
{
	clearScrean();
	printIntro();
	printMainMenu();
	
	FILE* f = openFileForRead("santa.data");
	GiftPack* gifts = GiftPackReaderForBinFile(f, "santa.data");
	fclose(f);
	
	char slected;
	while((slected = mainManu()) != '3')
	{
		if(slected == '1')
		{
			clearScrean();
			printIntro();
			
			char nev[100];
			readFromConsole(nev, '*', "Neved(*):", 0);
			char varos[100];
			readFromConsole(varos, '*', "Városod(*):", 0);
			char cim[100];
			readFromConsole(cim, '*', "Címed(*):", 0);
			
			giftTypes giftType =  getGiftTypeFromConsole();
			char text[1000];
			readFromConsole(text, '*', "Új levél írása", 1);
				addGiftToPack(newGift(gifts->size+1, time(NULL), nev, varos, cim, text, giftType),gifts);
				FILE* fr = openFileForWrite("santa.data");
				GiftPackWriterForBinFile(gifts, fr);
				fclose(fr);
			printf("\nA mentett szöveg:\n%s   Üss *-ot a menühöz! ",text);
			vaitFromToken('*');
		}
		if(slected == '2')
		{
			clearScrean();
			printIntro();
			printSubMenu();
			char slectedSumbenu;
			while((slectedSumbenu = subManu()) != '4')
			{
				if(slectedSumbenu == '1')
				{
					clearScrean();
					printIntro();
					printf("Az összes levél:\n");
					printGiftPack(gifts);
					printf("\nÜss *-ot a menühöz! ");
					vaitFromToken('*');
				}
				if(slectedSumbenu == '2')
				{
					clearScrean();
					printIntro();
					printf("Az összes levél szűrése város szerint:\n");
					char city[100];
					readFromConsole(city, '*', "Városod:", 0);
					printGiftPack(filterForCity(gifts, city));
					printf("\nÜss *-ot a menühöz! ");
					vaitFromToken('*');
				}
				if(slectedSumbenu == '3')
				{
					clearScrean();
					printIntro();
					printf("Az összes levél szűrése ajándék típus szerint:\n");
					giftTypes giftType =  getGiftTypeFromConsole();
					printGiftPack(filterForGiftType(gifts, giftType));
					printf("\nÜss *-ot a menühöz! ");
					vaitFromToken('*');
				}
				clearScrean();
				printIntro();
				printSubMenu();
			}
		}
		clearScrean();
		printIntro();
		printMainMenu();
	}
	
	freeGiftPack(gifts);
	return 0;
}