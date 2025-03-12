#include<stdio.h>
#include<stdlib.h>
#include <math.h>
void massive(float *h, int n)
{
    int count=0;
    for (int j=0; j<n; j++)
    {
        if(h[j]>=0)
            count++;
    }
    float *c=malloc(count*sizeof(float));
    int count_c=0;
    for (int i=0; i<n; i++)
    {
        if(h[i]>=0)
        {
            c[count_c]=(pow(h[i], 0.5)/5);
            count_c++;
        }
    }
    for(int i=0; i<count_c; i++)
        printf("%f\n", c[i]);

}
int main()
{
    int n=5;
    int count=0;
    float *b=malloc(n*sizeof(float));
    b[0]=-23;
    b[1]=12;
    b[2]=34;
    b[3]=98.78;
    b[4]=-123.456;
    massive(b, n);
    //printf("%f\n", c);
    /*for (int i=0; i<n; i++)
        printf("%f\n", b[i]);
    for (int j=0; j<n; j++)
    {
        if(b[j]>=0)
            count++;
    }
    float *c=malloc(count*sizeof(float));
    int count_c=0;
    for (int i=0; i<n; i++)
    {
        if(b[i]>=0)
        {
            c[count_c]=(pow(b[i], 0.5)/5);
            count_c++;
        }
    }
    for(int i=0; i<count_c; i++)
        printf("%f\n", c[i]);*/
}

