#include <stdio.h>
#include <time.h>

long long c[100];

int main()
{
    clock_t begin = clock();
    unsigned int n;
    printf("Enter an odd number : ");
    scanf("%d",&n);

    c[0] = 1;
    for (int i = 0; i < n; c[0] = -c[0], i++)
    {
        c[1 + i] = 1;
        for (int j = i; j > 0; j--)
        {
            c[j] = c[j - 1] - c[j];
        }
    }
    c[0]++;
    c[n]--;

    int tmp = n;
    while (tmp-- && c[tmp] % n == 0)
    {
        continue;
    }

    if (tmp<0){
        printf("According to the AKS algorithm %d is prime\n", n);    
    }
    else
    {
        printf("According to the AKS algorithm %d is not prime\n", n);
    }
    
    clock_t end = clock();
    double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
    printf("Time elapsed:%f \n", time_spent);

}
