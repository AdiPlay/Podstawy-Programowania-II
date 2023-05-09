#include <stdio.h>

int main(int argc, char const *argv[]){
    int i = 0;
    FILE *fp;
    fp = fopen("liczby4.dat", "r+b");
    if (fp == NULL){
        printf("Nie mozna otworzyc pliku\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    int n = size / sizeof(int);
    int tab[n];
    fseek(fp, 0, SEEK_SET);
    fread(tab, sizeof(int), n, fp);
    printf("Odczytano %d liczb\n", n);
    printf("Oto one: ");
    for (i = 0; i < n; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
    fclose(fp);
    fp = fopen("liczby5.dat", "w+b");
    if (fp == NULL){
        printf("Nie mozna otworzyc pliku\n");
        return 1;
    }
    for (i = n - 1; i >= 0; i--){
        fwrite(&tab[i], sizeof(int), 1, fp);
    }
    fseek(fp, 0, SEEK_SET);
    fread(tab, sizeof(int), n, fp);
    printf("Liczby z pliku liczby5.dat: \n");
    for (i = 0; i < n; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
    int j, temp;
    for (i = 0; i < n; i++){
        for (j = 0; j < n - 1; j++){
            if (tab[j] > tab[j + 1]){
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
    printf("Posortowane liczby: \n");
    for (i = 0; i < n; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
    fclose(fp);
    return 0;
}
