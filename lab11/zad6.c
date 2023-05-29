#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DaneTechniczne {
    int pojemnoscSkokowa;
    int moc;
    int momentObrotowy;
    char paliwo[10];
};

struct Silnik {
    char nazwa[25];
    char producent[25];
    double cenaNetto;
    struct DaneTechniczne daneSilnika;
    int VAT;
    double cenaBrutto;
};