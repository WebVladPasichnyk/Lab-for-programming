#include <stdio.h>
#include <math.h>

float fun(float x)
{
   return x * x / 4 + x - 1.2502;
}

int main()
{
   FILE *text = fopen("lab_6_2_resolt.txt", "w");
   for (float x = 0; x <= 10; x++)
   {
      fprintf(text, "\n%f", x);
      fprintf(text, "   %f", fun(x));
   }
   fclose(text);
   return 0;
}