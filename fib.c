#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

unsigned long long memo[MAX];

//memo func

void memoization()
{
   for (int ix = 0; ix< MAX; ix++)
      memo[ix] = -1;

      memo[1] = 0; // Base case F(1) = 0
      memo[2] = 1; // Base case F(2) = 1
}

// Fibonacci Functions
unsigned long long recursive(int n)
{
   if (n == 1)
      return 0;
   if (n == 2)
      return 1;
      
   return recursive(n-1) + recursive(n-2);
}

unsigned long long recursive_memo(int n)
{
   if (memo[n] != -1)
      return memo[n];
   
   memo[n] = recursive(n-1) + recursive(n-2);
   return memo[n];
   
}
unsigned long long iterative(int n)
{
   if (n == 1)
      return 0;
   if (n == 2)
      return 1;
   
   unsigned long long a = 0;
   unsigned long long b = 1;

   //Fibonacci number #1 is 0 so start at 3 instead of 2. F(1)= 0, F(2) = 1
   for (int iy = 3; iy <= n; iy++)
   {
      unsigned long long next = a + b;
      a = b;
      b = next;
   }
   return b;
}

unsigned long long iterative_memo(int n)
{
   if (memo[n] != -1)
      return memo[n];
   
   memo[n] = iterative(n);
   return memo[n];
}

int main(int argc, char *argv[]) 
{

   int number = atoi(argv[1]);

   memoization();

   unsigned long long fibNumber;

   if(strcmp(argv[2],"r") == 0) //recursive 
   {
      fibNumber = recursive_memo(number);
   }
   else if(strcmp(argv[2], "i") == 0 ) //iterative
   {
      fibNumber = iterative_memo(number);
   }

   printf("%llu\n", fibNumber);
   

return 0;
}
