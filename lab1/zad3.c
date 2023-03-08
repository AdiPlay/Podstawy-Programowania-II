#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int n = 3, i, j, k, nrW, nrK, sumaW = 0, sumaK = 0;
	do{
		printf("Podaj numer wiersza (0-2): ");
		k = scanf("%d", &nrW);
		if (k == 0 || nrW > 2)
			printf("Blad formatu lub liczba poza zakresem\n");

		fflush(stdin);

	}while(k == 0);
	do{
		printf("Podaj numer kolumny (0-2): ");
		k = scanf("%d", &nrK);
		if (k == 0 || nrK > 2)
			printf("Blad formatu \n");
		fflush(stdin);
	}while(k == 0);

	for (j = 0; j < 3; j++)
		sumaW = sumaW + x[nrW][j];
	printf("Suma wiersza = %d", sumaW);
	printf("\n");

	for (i = 0; i < 3; i++)
		sumaK = sumaK + x[i][nrK];
	printf("Suma kolumny = %d", sumaK);
	return 0;
}
