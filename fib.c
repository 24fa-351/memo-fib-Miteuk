#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

unsigned long long memo[MAX];

//memo func

void memoization()
{
   for (int i = 0; i< MAX; i++)
      memo[i] = -1;
}

// Fibonacci Functions
unsigned long long recursive_memo(unsigned long long n)
{
   if (n == 1)
      return 0;
   if (n == 2)
      return 1;
   memo[n] = recursive_memo(n-1) + recursive_memo(n-2);
   return memo[n];

}

unsigned long long iterative_memo(unsigned long long n)
{
   if (n == 1)
      return 0;
   if (n == 2)
      return 1;
   
   unsigned long long a = 0;
   unsigned long long b = 1;
   unsigned long long next;

   //Fibonacci number #1 is 0 so start at 3 instead of 2. F(1)= 0, F(2) = 1
   for(int i = 3; i <= n; ++i)
   {
      next = a + b;
      a = b;
      b = next;
   }
   return b;
}

int main(int argc, char *argv[]) 
{

   unsigned long long number = atoi(argv[1]);


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
