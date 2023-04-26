#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int i, buf;
    char bufc;
    FILE *fp1, *fp2, *fp3;
    fp1 = fopen("liczby3.dat", "w+b");
    if (fp1 == NULL){
        printf("Brak pliku!\n");
        exit(1);
    }
    fp2 = fopen("kopia.dat", "w+b");
    if (fp2 == NULL){
        printf("Brak pliku!\n");
        exit(1);
    }
    fp3 = fopen("liczby4.dat", "w+b");
    if (fp3 == NULL){
        printf("Brak pliku!\n");
        exit(1);
    }
    for (i = 0; i < 10; i++){
        buf = rand() % 20;
        fwrite(&buf, sizeof(int), 1, fp1);
    }
    fseek(fp1, 0, 0);
    while(fread(&buf, sizeof(int), 1, fp1))
        fwrite(&buf, sizeof(int), 1, fp2);
    fseek(fp2, 0, 0);
    printf("Odczyt pliku kopia.dat");
    i=0;
    while(fread(&buf, sizeof(int), 1, fp2)){
        printf("\nElement pliku nr %d = %d",i, buf);
        i++;
    }
    fclose(fp1);
    fseek(fp2, 0, 0);
    while(fread(&buf, sizeof(int), 1, fp2)){
        if (buf % 2 == 0)
            fwrite(&buf, sizeof(int), 1, fp3);
    }
    fseek(fp3, 0, 0);
    i=0;
    printf("\nLiczby parzyste z pliku");
    while(fread(&buf, sizeof(int), 1, fp3)){
        printf("\nElement pliku nr %d = %d",i, buf);
        i++;
    }
    fclose(fp2);
    fclose(fp3);
    return 0;
}
