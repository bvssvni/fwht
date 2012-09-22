
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fwht.h"
#include "fwht.c"

#define Err() do {printf("%i Error\n", __LINE__); exit(1);} while (0)

void test(void)
{
    {
        int a[] = {1,0,1,0,0,1,1,0};
        int n = 8;
        int b[n];
        fwht_transform(n, a, b);
        if (b[0] != 4) Err();
        if (b[1] != 2) Err();
        if (b[2] != 0) Err();
        if (b[3] != -2) Err();
        if (b[4] != 0) Err();
        if (b[5] != 2) Err();
        if (b[6] != 0) Err();
        if (b[7] != 2) Err();
        fwht_transform(n, b, a);
        fwht_normalize(n, a);
        if (a[0] != 1) Err();
        if (a[1] != 0) Err();
        if (a[2] != 1) Err();
        if (a[3] != 0) Err();
        if (a[4] != 0) Err();
        if (a[5] != 1) Err();
        if (a[6] != 1) Err();
        if (a[7] != 0) Err();
    }
    
    {
        int a[] = {1,0,1,0,0,1,1,0,1,1,1,0,1,0,0,0};
        int n = sizeof(a)/sizeof(*a);
        int b[n];
        fwht_transform(n, a, b);
        fwht_transform(n, b, a);
        fwht_normalize(n, a);
        int ans[] = {1,0,1,0,0,1,1,0,1,1,1,0,1,0,0,0};
        int i;
        for (i = 0; i < n; i++) {
            if (a[i] != ans[i]) Err();
        }
    }
    {
        int a[] = {1,0,1,0,0,1,1,0};
        int b[] = {1,0,0,0,0,1,1,0};
        int n = 8;
        double diff_a = fwht_sum_absolute_difference(n, a, b);
        double diff_b = fwht_sum_absolute_difference(n, b, a);
        if (diff_a != diff_b) Err();
        
        int a2[n];
        int b2[n];
        fwht_transform(n, a, a2);
        fwht_transform(n, b, b2);
        double diff_a2 = fwht_sum_absolute_difference(n, a2, b2);
        double diff_b2 = fwht_sum_absolute_difference(n, b2, a2);
        if (diff_a2 != diff_b2) Err();
        
        fwht_transform(n, a2, a);
        fwht_transform(n, b2, b);
        fwht_normalize(n, a);
        fwht_normalize(n, b);
        
        double diff_a3 = fwht_sum_absolute_difference(n, a, b);
        double diff_b3 = fwht_sum_absolute_difference(n, b, a);
        
        if (diff_a != diff_a3) Err();
        if (diff_b != diff_b3) Err();
    }
}

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < (1<<20); i++) {
        test();
    }
    printf("fwht unit tests completed!\n");
    return 0;
}
