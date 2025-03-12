#include<stdio.h>
#include<stdlib.h>
void *otrizandnum(int *h, int n)
{
    int k=0;
    int j1=0;
    int j2=0;
    for(int i=0; i<n; i++)
    {
        if(h[i]<0)
            k++;
    }
    int *b=malloc(k*sizeof(int));
    for (int i=0; i<k; ++i)
        printf("%d\n", b[i]);

    int *c=malloc(k*sizeof(int));
    for(int i=0; i<n; i++)
    {
        if(h[i]<0)
        {
            b[j1]=h[i];
            c[j2]=i;
            j1++;
            j2++;
            //printf("%d\n",b[j1]);
        }
    }
    for(int i=0; i<k; i++)
        printf("%d\n", b[i]);
    //return b;
    free(b);
    free(c);
}

float srarifm(int *b, int n)
{
    float summa=0;
    int k=0;
    for(int i=0; i<n; i++)
    {
        if(b[i]<0)
        {
            summa=summa+b[i];
            k++;
        }
    }
    return (summa/k);
}
int main()
{
    int n;
    scanf("%d",&n);
    int *a=malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        int g;
        scanf("%d",&g);
        a[i]=g;
    }
    /*a[0]=0;
    a[1]=10;
    a[2]=-15;
    a[3]=30;
    a[4]=-120;*/
    float s=srarifm(a,n);
    printf("%f\n", s);
    int *b=otrizandnum(a,n);
    //printf("%d\n", b);
    free(a);
   /* float h=srarifm(b);
    printf("%f\n", h);*/
}

