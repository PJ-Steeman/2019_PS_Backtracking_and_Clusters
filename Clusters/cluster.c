#include <stdio.h>
#include <stdlib.h>
#include "cluster.h"

void inlezen(Persoon personen[])
{
	FILE *file;
	file = fopen("stud.txt","r");
	int i = 0;
	float resul = 0;
	while(fscanf(file, "%d %d %f",&personen[i].postcode, &personen[i].maand, &resul) != EOF)
	{
		personen[i].maxResultaat = (int)resul;
		printf(" %d - maand : %d - postcode : %d - maxResultaat : %d\n", i, personen[i].maand, personen[i].postcode, personen[i].maxResultaat);
		i++;
	}
	fclose(file);
}

void clustersInit(Persoon personen[], int aantal, Persoon middelpunt[])
{
	for(int i = 0; i < aantal; i++)
	{
		middelpunt[i].maand = personen[i].maand;
		middelpunt[i].postcode = personen[i].postcode;
		middelpunt[i].maxResultaat = personen[i].maxResultaat;
		personen[i].clusterNr = i;
		middelpunt[i].clusterNr = personen[i].clusterNr;
	}
	for(int j = aantal; j < AANTAL_PERSONEN; j++)
	{
	int beste = 1000000;
		for(int k = 0; k < aantal; k++)
		{
			int afstand = (personen[j].maand-middelpunt[k].maand)*(personen[j].maand-middelpunt[k].maand);
			afstand += (personen[j].postcode-middelpunt[j].postcode)*(personen[j].postcode-middelpunt[j].postcode);
			afstand += (personen[j].maxResultaat-personen[j].maxResultaat)*(personen[j].maxResultaat-personen[j].maxResultaat);
			if(afstand < beste)
			{
				personen[j].clusterNr = k;
				beste = afstand;
			}
		}
	}
}

void cluster(Persoon personen[], int aantal, Persoon middelpunt[])
{
	int afstanden[MAX_MIDDELPUNTEN];
	for(int i = 0; i < AANTAL_PERSONEN; i ++)
	{
		afstanden[personen[i].clusterNr] += iets	
	}
}

int main(int argc, char *argv[])
{
	int aantal = 6;
	if(argc > 1)
		aantal = atoi(argv[1]);
	Persoon personen[AANTAL_PERSONEN];
	Persoon middelpunt[MAX_MIDDELPUNTEN];
	inlezen(personen);
	clustersInit(personen, aantal, middelpunt);
	int totaleFout = 1000;
	if(totaleFout < MAX_FOUT)
	{
		totaleFout = clusters(personen, aantal, middelpunt);
	}
}
