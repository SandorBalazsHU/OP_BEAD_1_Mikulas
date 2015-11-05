#include <stdio.h>

int main(int argc, char** argv){
	FILE* f;
	f=fopen("x.txt","wb");
	if (f==NULL){perror("Hiba a file megnyitasa soran\n");}
	char* a = "aaaaa";
	int i;
	i=6;
	fwrite(&i,sizeof(i),sizeof(i),f);
	for(i=0; i<6; i++){fwrite(&a[i],sizeof(&a[i]),sizeof(&a[i]),f);}
	fclose(f);
	
	f==NULL;
	f=fopen("x.txt","rb");
	if (f==NULL){perror("Hiba a file megnyitasa soran\n");}
	int j;
	printf("*\n");
	fread(&j,sizeof(j),sizeof(j),f);
	printf("*\n");
	char c[j];
	for(i=0; i<j; i++)
	{	printf("x\n");
		char tmp;
		fread(&tmp,sizeof(tmp),sizeof(tmp),f); 
		c[i]=tmp;
	}
	printf("*\n");
	 puts(c);
	fclose(f);
}