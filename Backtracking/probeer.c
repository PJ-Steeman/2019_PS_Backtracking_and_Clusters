#include <stdio.h>
#include <stdlib.h>
#include "back.h"

extern int aantalOplossingen;
extern int besteOplossing[SPEELDAGEN][AANTAL];
extern int afstandOplossing;

void printKal(int kalender[][AANTAL])
{
	printf("%d - [", aantalOplossingen);
	for(int i = 0; i < SPEELDAGEN; i++)
	{
		printf("[");
		for(int j = 0; j < SELECT_AANTAL; j++)
		{
			printf("%d", kalender[i][j]);
			if(j != SELECT_AANTAL-1)
				printf(", ");
		}
		printf("]");
		if(i != SPEELDAGEN-1)
			printf(",");
	}
	printf("]\n");
}

int geldig(Ploeg ploegen[], int kal[][AANTAL], int ploegNummer, int speelDag, int match, int t, int l )
{
	if(match%2 != 0 && kal[speelDag][match-1] <= t && ploegNummer <= t)
		return 0;
	if(match%2 != 0 && kal[speelDag][match-1] > SELECT_AANTAL-t && ploegNummer > SELECT_AANTAL-t)
		return 0;
	if(match%2 != 0 && ploegen[ploegNummer-1].afstand[((kal[speelDag][match-1])-1)] < l)
		return 0;
	if(match%2 != 0 && kal[speelDag][match-2] > ploegNummer && match != 1)
		return 0;
	for(int i = 0; i < match; i++)
	{
		if(kal[speelDag][i] == ploegNummer)
			return 0;
	}
	if(speelDag != 0)
	{	
		int j = 0;
		if(match%2 !=  0)
		j = 1;
		while(j < SELECT_AANTAL)
		{
			if(kal[speelDag-1][j] == ploegNummer)
				return 0;
			if((match%2 != 0) && (kal[speelDag-1][j-1] == ploegNummer) && (kal[speelDag][match-1] == kal[speelDag-1][j]))
				return 0;
			j = j+2;
				
		}
	}
	return 1;

}

void berekenAfstand(Ploeg ploegen[], int kal[][AANTAL])
{
	int afstand = 0;
	for(int i = 0; i < SPEELDAGEN; i++)
	{	
		int j = 1;
		while(j < SELECT_AANTAL)
		{
			afstand += ploegen[(kal[i][j])].afstand[(kal[i][j-1])];
			j = j+2;
		}
	}
	printf("AFSTAND : %d\n", afstand);
	if(afstand < afstandOplossing)
	{
		for(int k = 0; k < SPEELDAGEN; k++)
		{
			for(int l = 0; l < SELECT_AANTAL; l++)
			{
				besteOplossing[k][l] = kal[k][l];	
			}
		}
	}
}

void probeer(Ploeg ploegen[], int kal[][AANTAL], int speelDag, int match, int t, int l)
{
	for(int ploegNummer = 1; ploegNummer <= SELECT_AANTAL; ploegNummer++)
	{
		//	printf("OK %d %d %d\n", speelDag, match, ploegNummer);
		if(geldig(ploegen, kal, ploegNummer, speelDag, match, t, l))
		{
			kal[speelDag][match] = ploegNummer;
			if(speelDag == SPEELDAGEN-1 && match == SELECT_AANTAL-1)
			{
				aantalOplossingen++;
				berekenAfstand(ploegen, kal);
				printKal(kal);
				return;
			}
			else
			{
				int nieuwSDag = speelDag;
				if((match+1) == SELECT_AANTAL)
					nieuwSDag ++;
				int nieuwMatch = (match+1) % SELECT_AANTAL;
				probeer(ploegen, kal, nieuwSDag, nieuwMatch, t, l);
			}
			kal[speelDag][match] = 0;
		}
	}	
} 
