#include "stdio.h"
#include "math.h"

struct dataN
{
   int N ;
   float T ;
   float h ;
   double w ;
   // int N = 200;
   // float T = 0.03;
   // float h = T / N;
   // double w = (2 * 3.14159) / T;
};


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
   struct dataN dataM;
   dataM.N = 200;
   dataM.T = 0.03;
   dataM.h = dataM.T / dataM.N;
   dataM.w = (2 * 3.14159) / dataM.T;

   int i;
   FILE *graf1 = fopen("graf1.txt", "w");
   // double w;
   // w = (2 * 3.14159) / T;
   // float h;
   // h = T / N;
   float t[dataM.N], s[dataM.N];
   for (i = 0; i < dataM.N; i++)
   {
      t[i] = i * dataM.h;
      s[i] = sygn(t[i]);
      fprintf(graf1, "%f %f\n", t[i], s[i]);
   }
   fclose(graf1);

   // Part3

   double a0 = 0;
   double Sum = 0;
   for (i = 1; i < dataM.N; i++)
   {
      Sum += s[i];
   }
   a0 = 2 / dataM.T * dataM.h * Sum;
   printf("a0 = %f\n", a0);

   int k = 10;
   float a[k], b[k];
   for (k = 1; k <= 10; k++)
   {

      Sum = 0;
      for (i = 1; i < dataM.N; i++)
      {
         Sum += s[i] * cos(k * dataM.w * t[i]);
      }
      a[k - 1] = 2 * dataM.h * Sum / dataM.T;
      printf("ak = %f\n", a[k - 1]);

      Sum = 0;
      for (i = 1; i < dataM.N; i++)
      {
         Sum += s[i] * sin(k * dataM.w * t[i]);
      }
      b[k - 1] = 2 * dataM.h * Sum / dataM.T;
      printf("bk = %f\n", b[k - 1]);
   }

   // Part4

   FILE *graf2 = fopen("graf2.txt", "w");
   float Suma = 0;
   for (i = 1; i < dataM.N; i++)
   {
      Suma = a0 / 2;
      for (k = 1; k <= 10; k++)
      {
         Suma = Suma + a[k - 1] * cos(k * dataM.w * t[i]) + b[k - 1] * sin(k * dataM.w * t[i]);
      }
      fprintf(graf2, "%f %f\n", t[i], Suma);
   }
   fclose(graf2);
   return 0;
}