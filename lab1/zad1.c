#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int i,j,n=3,m=3;
    for(i = 0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d",x[i][j]);
            printf("\n");
        }
        
    }
    
    return 0;
}
