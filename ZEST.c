#include <stdio.h>         
     
unsigned int countBits(unsigned int n)
{
   unsigned int count = 0;
   while (n)
   {
        count++;
        n >>= 1;
    }
    return count;
}
   
int main()
{
    int i = 65;
    printf("%d\n", countBits(12222));
    return 0;
}