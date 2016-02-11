#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) 
{
    int outer_ite = 0, inner_ite = 0, max = 0, value = 0;
    if ((l < 1) || (r>1000))
    {
        return 0;
    }

    for (outer_ite = l; outer_ite <=r; outer_ite++)
    {
        for (inner_ite = outer_ite; inner_ite <=r; inner_ite++)
        {
            value = outer_ite ^ inner_ite;
            if (value > max)
            {
                max = value;
            }
        }
    }    
    return max;
}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
