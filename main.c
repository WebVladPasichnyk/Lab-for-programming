#include "stdio.h"
#include "math.h"

int main() {
   float sum, average;
   sum = 0;
   int A[] = {5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 5, 7, 8, 9, 10, 10, 9, 8, 7, 7, 6, 5, 5, 5, 5};
   for (int i = 0; i < 24; i++)
   {
      sum = sum + A[i];
   }
   average = sum / 24;
   printf("%f\n", average);
}