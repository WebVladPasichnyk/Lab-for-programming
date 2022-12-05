#include "stdio.h"
#include "math.h"

double sygn (float t)
{
    double s;
    float T = 0.03;
    
    if (t == 0) s = 0;
    if ((t > 0) && (t <= T / 4)) s = 5*t / (T / 4);
    if ((t > T/4) && (t <= 0.75 * T)) s = 5-15*(t-T/4) / (0.75*T);
    if ((t > 0.75*T ) && (t <= T)) s = 5*t / (T / 4) - 20 ;
    if (t == T) s = 0;

    return s;
}
int main()
{
   const float T = 0.03;
   const int N = 200;
   int i;
   FILE *graf1 = fopen("graf1.txt", "w");
   double w;
   w = (2 * 3.14159) / T;
   float h;
   h = T/N;
   float t[N], s[N];
   for (i = 0; i < N; i++)
   {
      t[i] = i * h;
      s[i] = sygn(t[i]);
      fprintf(graf1, "%f %f\n", t[i], s[i]);
   }
   fclose(graf1);

   // Part3

   double a0 = 0;
   double Sum = 0;
   for (i = 1; i < N; i++)
   {
      Sum += s[i];
   }
   a0 = 2 / T * h * Sum;
   printf("a0 = %f\n", a0);

   int k = 10;
   float a[k], b[k];
   for (k = 1; k <= 10; k++)
   {

      Sum = 0;
      for (i = 1; i < N; i++)
      {
         Sum += s[i] * cos(k * w * t[i]);
      }
      a[k -1] = 2 * h * Sum / T;
      printf("ak = %f\n", a[k - 1]);

      Sum = 0;
      for(i = 1; i < N; i++)
      {
        Sum += s[i] * sin(k * w * t[i]);
      }
      b[k - 1] = 2 * h * Sum / T;
      printf("bk = %f\n", b[k - 1]);
   }

   // Part4

   FILE *graf2 = fopen("graf2.txt", "w");
   float Suma = 0;
   for (i = 1; i < N; i++)
   {
      Suma = a0 / 2;
      for (k = 1; k <= 10; k++)
      {
         Suma = Suma + a[k - 1] * cos(k * w * t[i]) + b[k - 1] * sin(k * w * t[i]);
      }
      fprintf(graf2, "%f %f\n", t[i], Suma);
   }
   fclose(graf2);
   return 0;
}