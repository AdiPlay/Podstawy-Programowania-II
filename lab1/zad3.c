#include <stdio.h>
// w sprawozdaniu nr wiesza i kolumny z zabezpieczeniem
int main(int argc, char const *argv[])
{
	int x[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int n = 3, i, j, nrW = 2, nrK = 2, sumaW = 0, sumaK = 0;
	for (j = 0; j < 3; j++)
		sumaW = sumaW + x[nrW][j];
	printf("Suma wiersza = %d", sumaW);
	printf("\n");

	for (i = 0; i < 3; i++)
		sumaK = sumaK + x[i][nrK];
	printf("Suma kolumny = %d", sumaK);
	return 0;
}
