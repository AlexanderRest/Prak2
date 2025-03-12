#include<stdio.h>
#include<stdlib.h>
int main()
{
  float* ptr1;
  float* ptr2;
  float* ptr3;
  ptr1=(float*)malloc(sizeof(float));
  ptr2=(float*)malloc(sizeof(float));
  ptr3=(float*)malloc(sizeof(float));
  printf("%d \n",ptr1);
  printf("%d \n",ptr2);
  printf("%d \n",ptr3);
  *ptr1=256.66;
  *ptr2=0.78;
  *ptr3=45.55;
  printf("%f \n",*ptr1);
  printf("%f \n",*ptr2);
  printf("%f \n",*ptr3);
  float buffer=*ptr1;
  *ptr1=*ptr2;
  *ptr2=buffer;
  printf("%f \n",*ptr1);
  printf("%f \n",*ptr2);
  printf("%f \n",*ptr3);
  free(ptr1);
  free(ptr2);
  free(ptr3);
}

