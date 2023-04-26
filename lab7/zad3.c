#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i, ind1, ind2, k;
    double buf1, buf2, buf, iloscEl;
    FILE *fp;
    fp = fopen("liczby2.dat", "r+b");
    fseek(fp, 0, SEEK_END);
    iloscEl = ftell(fp) / sizeof(double);
    if (iloscEl < 6){
        printf("Za malo elementow w pliku!");
        getchar();
        fclose(fp);
        exit(1);
    }
    do{
        printf("Podaj dolny zakres elementow do zamiany: ");
        k = scanf("%d", &ind1);
        if (k == 0)
            printf("Nieprawidłowy format.\n");
        fflush(stdin);
    } while (k == 0);
    do{
        printf("Podaj gorny zakres elementow do zamiany: ");
        k = scanf("%d", &ind2);
        if (k == 0)
            printf("Nieprawidłowy format.\n");
        fflush(stdin);
    } while (k == 0);

    printf("Tablica przed zamiana:\n");
    fseek(fp, 0, 0);
    for (i = 0; i < 6; i++){
        fread(&buf, sizeof(double), 1, fp);
        printf("Element pliku nr %d = %lf\n", i, buf);
    }
    fseek(fp, ind1 * sizeof(double), SEEK_SET);
    fread(&buf1, sizeof(double), 1, fp);
    fseek(fp, ind2 * sizeof(double), SEEK_SET);
    fread(&buf2, sizeof(double), 1, fp);
    fseek(fp, ind1 * sizeof(double), SEEK_SET);
    fwrite(&buf2, sizeof(double), 1, fp);
    fseek(fp, ind2 * sizeof(double), SEEK_SET);
    fwrite(&buf1, sizeof(double), 1, fp);
    fseek(fp, 0, 0);
    printf("Tablica po zamianie:\n");
    for (i = 0; i < 6; i++){
        fread(&buf, sizeof(double), 1, fp);
        printf("Element pliku nr %d = %lf\n", i, buf);
    }
    fclose(fp);
    getchar();
    return 0;
}
