#include <stdio.h>
#include <math.h>

float fun(float x)
{
   return x * x / 4 + x - 1.2502;
}
float fun2(float x)
{
   return 0.5 * x + 1;
}

int main()
{
   float xMin, xMax, esp, c;
   xMin = 0;
   xMax = 2;
   esp = 0.00001;
   do
   {
      c = fun(xMin) / fun2(xMin);
      xMin = xMin - c;
   }
   while (c > esp);
   printf("x = %f fun(x) = %f \n", xMin, fun(xMin));
}
