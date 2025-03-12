#include<stdio.h>
int main()
{
  float a;
  float b;
  scanf("%f",&a);
  scanf("%f",&b);
  float* ptra=&a;
  float* ptrb=&b;
  *ptra=*ptra*2;
  *ptrb/=2;
  printf("%f \n",*ptra);
  printf("%f \n",*ptrb);
}

