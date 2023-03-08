#include <stdio.h>
#include <math.h>

double pierw5(double x);

int main(int argc, char const *argv[])
{
    double x[9] = {-32, -64, -1, -0.5, 0, 0.5, 1, 64, 32}; 
    double y[9];                                           
    int i;                                                 
    for (i = 0; i < 9; i++)
    {
        y[i] = pierw5(x[i]); // obliczenie pierwiastka z x[i] i zapisanie w y[i]
    }
    for (i = 0; i < 9; i++)
    {
        if(y[i]<0){
            y[i]=-y[i]; // zmiana znaku na dodatni
            printf("y = %.2lf\n", y[i]);
        }else
        {
            printf("y = %.2lf\n", y[i]);
        }
    }
    return 0;
}

double pierw5 (double x) {
  double y;
  if (x < 0) {
    y = -pow (-x, 0.2); // zmiana znaku na dodatni i obliczenie pierwiastka
  }
  else {
    y = pow (x, 0.2); // obliczenie pierwiastka dla dodatniego x
  }
  return y;
}
