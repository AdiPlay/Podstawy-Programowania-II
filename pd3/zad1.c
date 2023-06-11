#include "zad1.h" // plik nagłówkowy do zadania 1 - zawiera prototypy funkcji oraz biblioteki
int main(int argc, char *argv[]){
    // Ustawienie parametrów zadania
    int A[5][5], n = 5;
    unsigned int nrAlbumu = 19727; // Należy wstawić własny nr albumu
    int w3 = 3;
    int k1 = 1;
    fillArray(A, n, nrAlbumu); // Wypełnienie tablicy A
    printArray(A, n);          // Wypisanie tablicy A
    int B[5][4][4];
    int C[4][3][3];
    int detB[5];
    int detC[4];
    // Przepisanie podmacierzy 5x4 do macierzy 4x4
    for (int i = 0; i < 5; i++){
        przepisz54(A, i, k1, B[i]);
    }
    // Przepisanie podmacierzy 4x4 do macierzy 3x3
    for (int i = 0; i < 4; i++){
        przepisz43(B[i], w3, 0, C[i]);
    }
    // Obliczenie wyznaczników
    for (int i = 0; i < 4; i++){
        detC[i] = sarrus(C[i]);
        detB[i] = laplace(B[i]);
    }
    // Obliczenie wyznacznika B4
    detB[4] = laplace(B[4]);
    //Obliczenie wyznacznika A metoda Laplace'a
    int detA = laplace(A);
    // Wypisanie podmacierzy
    printf("\nPodmacierze:\n");
    for (int i = 0; i < 5; i++){
        printf("B%d:\n", i);
        for (int j = 0; j < 4; j++){
            printf("|");
            for (int k = 0; k < 4; k++){
                printf("%3d ", B[i][j][k]);
            }
            printf("|\n");
        }
    }
    for (int i = 0; i < 4; i++){
        printf("C%d:\n", i);
        for (int j = 0; j < 3; j++){
            printf("|");
            for (int k = 0; k < 3; k++){
                printf("%3d ", C[i][j][k]);
            }
            printf("|\n");
        }
    }
    // Wypisanie wyznaczników
    printf("\nWyznaczniki:\n");
    for (int i = 0; i < 5; i++){
        printf("detB%d = %d\n", i, detB[i]);
    }
    for (int i = 0; i < 4; i++){
        printf("detC%d = %d\n", i, detC[i]);
    }
    printf("detA = %d\n", detA); 
    return 0;
}
void przepisz43(int macierz[][4], int nrWiersza, int nrKolumny,
                int podmacierz[][3]){
    int m = 0, n = 0;
    for (int i = 0; i < 4; i++){
        if (i != nrWiersza){
            n = 0;
            for (int j = 0; j < 4; j++){
                if (j != nrKolumny){
                    podmacierz[m][n] = macierz[i][j];
                    n++;
                }
            }
            m++;
        }
    }
}
void przepisz54(int macierz[][5], int nrWiersza, int nrKolumny,
                int podmacierz[][4]){
    int m = 0, n = 0;
    for (int i = 0; i < 5; i++){
        if (i != nrWiersza){
            n = 0;
            for (int j = 0; j < 5; j++){
                if (j != nrKolumny){
                    podmacierz[m][n] = macierz[i][j];
                    n++;
                }
            }
            m++;
        }
    }
}
int sarrus(int macierz[][3]){
    return macierz[0][0] * macierz[1][1] * macierz[2][2] +
           macierz[0][1] * macierz[1][2] * macierz[2][0] +
           macierz[0][2] * macierz[1][0] * macierz[2][1] -
           macierz[0][2] * macierz[1][1] * macierz[2][0] -
           macierz[0][1] * macierz[1][0] * macierz[2][2] -
           macierz[0][0] * macierz[1][2] * macierz[2][1];
}
int laplace(int macierz[][4]){
    int det = 0;
    for (int i = 0; i < 4; i++)
    {
        int m[3][3];
        przepisz43(macierz, 0, i, m);
        int sign = (i % 2 == 0) ? 1 : -1;
        det += sign * macierz[0][i] * sarrus(m);
    }
    return det;
}

void fillArray(int A[][5], int n, unsigned int nrAlbumu){
    unsigned int i, j, m;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m = nrAlbumu % (rand() % 10 + 1);
            A[i][j] = rand() % 10 + m;
        }
    }
}
void printArray(int A[][5], int n){
    unsigned int i, j;
    printf("Wygenerowana macierz:\n");
    for (i = 0; i < n; i++)
    {
        printf("|");
        for (j = 0; j < n; j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("|\n");
    }
}