
#include "fwht.h"

void fwht_transform(int n, const int *src, int *dst)
{
    int adata[n];
    int bdata[n];
    int *a = adata;
    int *b = bdata;
    void *tmp;
    memcpy(a, src, sizeof(int)*n);
    
    // Fast Walsh Hadamard Transform.
    int i, j, s;
    for (i = n>>1; i > 0; i>>=1) {
        for (j = 0; j < n; j++) {
            s = j/i%2;
            b[j]=a[(s?-i:0)+j]+(s?-1:1)*a[(s?0:i)+j];
        }
        tmp = a; a = b; b = tmp;
    }
    
    memcpy(dst, a, sizeof(int)*n);
}

void fwht_normalize(int n, int *src)
{
    int i;
    for (i = 0; i < n; i++) src[i] /= n;
}

double fwht_sum_absolute_difference(int n, int *a, int *b)
{
    long sum = 0;
    int diff;
    int i;
    for (i = 0; i < n; i++) {
        diff = b[i]-a[i];
        sum += diff > 0 ? diff : -diff;
    }
    return sum/(double)n;
}
