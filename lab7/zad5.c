#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0, buf,min,max;
    FILE* fp;
    fp = fopen("liczby3.dat", "rb");
    fread(&buf, sizeof(int), 1, fp);
    max=min=buf;
    while(fread(&buf, sizeof(int), 1, fp)){
        if (buf > max)
            max = buf;
        if (buf < min)
            min = buf;
    }
    printf("Najmniejsza liczba: %d\nNajwieksza liczba: %d", min, max);
    fclose(fp);
    return 0;
}

