#include <stdio.h>

void function(int n, int tab1[], int tab2[], int tab3[]);

int main(int argc, char const *argv[])
{
    int n = 5;
    
    return 0;
}

void function(int n, int tab1[], int tab2[], int tab3[]) {
    for (int i = 0; i < n; i++) {
        tab3[i] = tab1[i];
    }
    for (int i = 0; i < n; i++) {
        tab3[i + n] = tab2[i];
    }
}