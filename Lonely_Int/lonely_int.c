#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
int lonelyinteger(int a_size, int* a) 
{
    int outer_iter = 0,inner_iter = 0, outer_val = 0, temp_val = 0;
    char Match_Found = 0;
    
    if (a == NULL)
    {
        return 0;
    }

    if (a_size % 2 == 0)
    {
        return 0;
    }

    if ((a_size < 1) || (a_size > 99))
    {
        return 0;
    }

    for (outer_iter = 0; outer_iter < a_size; outer_iter += 2)
    {
        outer_val = a[outer_iter];
        Match_Found = 0;
        for (inner_iter = outer_iter + 1; inner_iter < a_size; inner_iter++)
        {
            if ( outer_val == a[inner_iter])
            {
                /* Pair Found; Group Pairs */
                if (inner_iter != outer_iter+1)
                {
                    /* Swapping is required only when the pairs are not colocated */
                    temp_val = a[outer_iter+1];
                    a [outer_iter+1] = a [inner_iter];
                    a[inner_iter] = temp_val;
                }
                Match_Found = 1;
                break;
            }
        }
        if (Match_Found == 0)
        {
            /* No Pair Found */
            return a[outer_iter];
        }
    }
    return 0;
}

int main() {
    int res;
    
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d", res);
    
    return 0;
}
