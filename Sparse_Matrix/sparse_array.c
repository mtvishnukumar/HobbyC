/*******************************************************************
 * There are N strings. Each string's length is no more than 20 characters.
 * There are also Q queries.
 * For each query, you are given a string, and you need to find out how many
 * times this string occurred previously.
 *
 * Input Format
 * ============
 * The first line contains N, the number of strings.
 * The next N lines each contain a string.
 * The N+2nd line contains Q, the number of queries.
 * The following Q lines each contain a query string.
 *
 * Constraints
 * ===========
 * 1<=N<=1000
 * 1<=Q<=1000
 * 1<= length of any string <=20
 *
 * SAMPLE INPUT:
 * ------------
 *  4
 *  aba
 *  baba
 *  aba
 *  xzxb
 *  3
 *  aba
 *  xzxb
 *  ab
 *
 * SAMPLE OUTPUT:
 * -------------
 *  2
 *  1
 *  0
 * **************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPUT_LENGTH 20
#define TOTAL_STRING 1000
#define TOAL_QUERY 1000

void ReleaseMemory (char **buffer, int total_blocks)
{
    int index = 0;

    if ((buffer == NULL) || (total_blocks <= 0))
    {
        return;
    }
    for (index = 0; index < total_blocks; index++)
    {
        free(buffer[index]);
        buffer[index] = NULL;
    }
    free (buffer);
}


int main()
{
    int N = 0,Q = 0, *count = NULL, ite = 0,length;
    char **input = NULL,**query = NULL,temp[INPUT_LENGTH+1];

    printf("Enter N:");
    scanf("%d",&N);
    if ((N <= 0) || (N > TOTAL_STRING))
    {
        return 0;
    }

    /* To clear input buffer */
    for(;getchar()!='\n';);

    input = (char**)calloc(1, (N * (sizeof(char*))));
    if (input == NULL)
    {
        return 0;
    }

    for (ite = 0; ite < N; ite++)
    {
        memset(temp,0,INPUT_LENGTH+1);
        fgets(temp,INPUT_LENGTH+1,stdin);
        length = strlen(temp);
        if (temp[length-1] == '\n')
        {
            temp[length - 1] = '\0';
            length--;
        }
        else
        {
            /* Need to clear the input buffer if the user has entered
             * input string whose lenght is greate than 20 */
            for (;getchar()!='\n';);
        }

        input[ite] = (char*)calloc(1, (sizeof(char) *(length + 1)));

        if (input[ite] == NULL)
        {
            ReleaseMemory(input,ite);
            return 0;
        }

        strcpy(input[ite],temp);
    }
    printf("Enter Q:");

    scanf("%d",&Q);

    if ((Q < 0) || (Q > TOAL_QUERY))
    {
        ReleaseMemory (input,N);
        return 0;
    }

    /* To clear input buffer */
    for (;getchar()!='\n';);

    query = (char**)calloc(1, (Q *sizeof(char*)));
    if (query == NULL)
    {
        ReleaseMemory(input,N);
        return 0;
    }

    for (ite = 0; ite < Q; ite++)
    {
        memset(temp,0,INPUT_LENGTH+1);/* +1 reason; one byte for \0*/
        fgets(temp,INPUT_LENGTH+1,stdin);
        length = strlen(temp);
        if (temp[length-1] == '\n')
        {
            temp[length - 1] = '\0';
            length--;
        }
        else
        {
            /* Need to clear the input buffer if the user has entered
             * input string whose lenght is greate than 20 */
            for (;getchar()!='\n';);
        }

        query[ite] = (char*)calloc(1, (sizeof(char) *(length + 1)));

        if (query[ite] == NULL)
        {
            ReleaseMemory(query,ite);
            ReleaseMemory(input,N);
            return 0;
        }

        strcpy(query[ite],temp);

    }
    ReleaseMemory(input,N);
    input = NULL;
    ReleaseMemory(query,Q);
    query = NULL;
    return 0;
}
