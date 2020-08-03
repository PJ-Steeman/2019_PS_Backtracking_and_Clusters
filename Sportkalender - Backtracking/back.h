#define AANTAL 16
#define NAAMLEN 16
#define SPEELDAGEN 2
#define SELECT_AANTAL 8

typedef struct ploeg{
		int		nummer;
		char 	naam[NAAMLEN];
		int		afstand[AANTAL];
}Ploeg;

void printKal(int kalender[][AANTAL]);
int geldig(Ploeg ploegen[], int kal[][AANTAL], int ploegNummer, int speelDag, int match, int t, int l);
void probeer(Ploeg ploegen[], int kal[][AANTAL], int speelDag, int match, int t, int l);
