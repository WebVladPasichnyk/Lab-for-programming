#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float T = 0.03;
int N = 200;

int i;

double sygn(float t)
{
    double s;

    if (t == 0) s = 0;
    if ((t > 0) && (t <= 0.4 * T)) s = 6 * t / (0.4 * T);
    if ((t > 0.4 * T) && (t <= 0.08 )) s = 6;
    if ((t > 0.8 * T) && (t <= T)) s = 6 - 6 * (t - 0.06) / 0.02;

    return s;

}
int main ()
 {
    FILE* file = fopen("lab_8", "w+");
    float h = T / N;
    float t[N], s[N];
    for (i = 0; i < N; i++ )
    {
        t[i] = i * h;
        s[i] = sygn(t[i]);
        fprintf(file, "%f    %f\n", t[i], s[i]);
    }

    fclose(file);   

}

