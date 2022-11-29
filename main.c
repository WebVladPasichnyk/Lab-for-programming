#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const float T = 0.04;
const int N = 200;
int i;

double sygn (float t)
{
    double s;
    
    if (t == 0) s = 0;
    if ((t > 0) && (t <= T / 4)) s = 5*t / (T / 4);
    if ((t > T/4) && (t <= 0.75 * T)) s = 5-15*(t-T/4) / (0.75*T);
    if ((t > 0.75*T ) && (t <= T)) s = 5*t / (T / 4) - 20 ;
    if (t == T) s = 0;

    return s;
}

int main()
{
      double w;
    w = (2 * 3.14159) / T;
    FILE *graf;

    float h = T / N;
    float t[N], s[N];
    graf = fopen("graf.txt", "w");
    for (i = 0; i < N; i++)
    {
        t[i]=i*h;
        s[i]=sygn(t[i]);
      fprintf(graf,"%f %f\n", t[i], s[i]);
    }
    fclose(graf);
}