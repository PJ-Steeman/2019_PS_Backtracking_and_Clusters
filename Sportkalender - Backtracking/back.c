#include <stdio.h>
#include <stdlib.h>
#include "back.h"

int aantalOplossingen = 0;

void inlezen(Ploeg ploegen[])
{
	FILE *file;
	file = fopen("afst.txt","r");
	int i = 0;
	while(i < AANTAL)
	{
		fscanf(file, "%d %s",&ploegen[i].nummer, ploegen[i].naam);
		printf("%d %s",ploegen[i].nummer, ploegen[i].naam);
		for(int j = 0; j<AANTAL; j++)
		{
			fscanf(file, "%d", &ploegen[i].afstand[j]);
			printf(" %d", ploegen[i].afstand[j]);
		}
		i++;
		printf("\n");

	}
	fclose(file);
}

void initKal(int kalender[][AANTAL])
{
	for(int i = 0; i< SPEELDAGEN; i++)
	{
		for(int j = 0; j < AANTAL; j++)
		{
			kalender[i][j] = 0;
		}
	}
}

int main( int argc, char *argv[])
{
	int t = 3;
	int l = 25;

	if(argc > 1)
	{
		t = atoi(argv[1]);
		l = atoi(argv[2]);
	}

	Ploeg ploegen[AANTAL];
	inlezen(ploegen);
	int kalender[SPEELDAGEN][AANTAL];
	initKal(kalender);
	probeer(ploegen, kalender, 0, 0, t, l);
}
