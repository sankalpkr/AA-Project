#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, r, i, condition, j;
    unsigned int n, d, k;
    unsigned long long x,p;

    clock_t begin = clock();

    printf("Enter an odd number : ");
    scanf("%d",&n);
    
    d=n-1;
    r=0;    
    while (d%2==0)
    {
        d=d/2;
        r++;
    }

    condition=1;
    i=0;
    while (i<=2 && condition)
    {
        condition=0;
    
        a=rand()%(n-4)+2;
        p=a%n;
        k=d;
        x=1;
    
        while (k>0)
        {
            if (k%2==1)
                x=(x*p)%n;
            p=(p*p)%n;
    
            k=k/2;
        }
    
        if(x==1 || x==n-1)
            condition=1;
        j=1;
    
    
        while (!condition && j<=r-1)
        {
            x=(x*x)%n;
            if (x==n-1)
                condition=1;
                j++;
        }

    
        if (condition) i++;
    }
    if (i==3){
        printf("According to the Miller-Rabin algorithm %d is prime\n", n);    
    }
    else
    {
        printf("According to the Miller-Rabin algorithm %d is not prime\n", n);
    }
    
    clock_t end = clock();
    double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
    printf("Time elapsed:%f \n", time_spent);

}
