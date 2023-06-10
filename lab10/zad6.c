#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Pointers{
    int *wskInt;
    double *wskD;
};
struct Pointers alokujtablice(int n, char typTablicy[]){
    struct Pointers p;
    p.wskInt = NULL;
    p.wskD = NULL;
    if (strcmp(typTablicy, "int") == 0){
        p.wskInt = malloc(n * sizeof(int));
        if (p.wskInt == NULL){
            printf("Błąd alokacji pamięci.\n");
            exit(1);
        }
    }
    else if (strcmp(typTablicy, "double") == 0){
        p.wskD = malloc(n * sizeof(double));
        if (p.wskD == NULL){
            printf("Błąd alokacji pamięci.\n");
            exit(1);
        }
    }
    else{
        printf("Nieznany typ tablicy: %s\n", typTablicy);
        exit(1);
    }
    return p;
}
int main(){
    int n;
    char typTablicy[10];
    struct Pointers p;
    printf("Podaj liczbę elementów tablicy: ");
    scanf("%d", &n);
    printf("Podaj typ tablicy (int/double): ");
    scanf("%s", typTablicy);
    p = alokujtablice(n, typTablicy);
    if (p.wskInt != NULL){
        for (int i = 0; i < n; i++){
            printf("Podaj element nr %d: ", i + 1);
            scanf("%d", &p.wskInt[i]);
        }
        printf("Elementy tablicy typu int:\n");
        for (int i = 0; i < n; i++){
            printf("%d ", p.wskInt[i]);
        }
        printf("\n");
        free(p.wskInt);
    }
    else if (p.wskD != NULL){
        for (int i = 0; i < n; i++){
            printf("Podaj element nr %d: ", i + 1);
            scanf("%lf", &p.wskD[i]);
        }
        printf("Elementy tablicy typu double:\n");
        for (int i = 0; i < n; i++){
            printf("%lf ", p.wskD[i]);
        }
        printf("\n");
        free(p.wskD);
    }
    else{
        printf("Nieznany typ tablicy: %s\n", typTablicy);
        exit(1);
    }
    return 0;
}
