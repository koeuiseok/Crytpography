#include <stdio.h>
#include <stdlib.h>

struct BIG_DECIMAL { 
 unsigned char *digit; 
 int size;
 bool sign; 
};

BIG_DECIMAL CreateDecimal(unsigned char *str, int size)
{
 BIG_DECIMAL decimal;
 decimal.digit = (unsigned char *)malloc(size); 
  
 for(int i = 0; i < size; i++)
 decimal.digit[i] = str[size-i-1] - 48;

 decimal.size = size;
 decimal.sign = false;
  
 return decimal; 
}

int main()
{
  BIG_DECIMAL decimal;
  
  decimal = CreateDecimal((unsigned char*)"34234233243",11);
  
  return 0;
  
}
