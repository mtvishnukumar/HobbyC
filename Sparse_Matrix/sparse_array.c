#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INPUT_LENGTH 20
#define TOTAL_STRING 1000
#define TOAL_QUERY 1000

void ReleaseMemory (char **buffer, int total_blocks)
{
    int index = 0;

    if (buffer == NULL)
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
    int N = 0,Q = 0, *count = NULL, ite = 0,length, search_idx = 0;
    char **input = NULL,**query = NULL,temp[INPUT_LENGTH+1],ch;

    scanf("%d",&N);
    if ((N <= 0) || (N > TOTAL_STRING))
    {
        return 0;
    }

    /* To clear input buffer */
    while((ch = getchar())!=EOF && (ch != '\n'));

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
            while((ch = getchar())!=EOF && (ch != '\n'));
        }
        input[ite] = (char*)calloc(1, (sizeof(char) *(length + 1)));

        if (input[ite] == NULL)
        {
            ReleaseMemory(input,ite);
            return 0;
        }

        strcpy(input[ite],temp);
    }

    scanf("%d",&Q);

    if ((Q <= 0) || (Q > TOAL_QUERY))
    {
        ReleaseMemory (input,N);
        return 0;
    }

    /* To clear input buffer */
    while((ch = getchar())!=EOF && (ch != '\n'));

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
            while((ch = getchar())!=EOF && (ch != '\n'));
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

    count = (int*)calloc(Q,sizeof(int));

    if (count == NULL)
    {
        ReleaseMemory(query,ite);
        ReleaseMemory(input,N);
        return 0;
    }

    for (ite = 0; ite < Q; ite++)
    {
        count[ite] = 0;
    }

    for (ite = 0; ite < Q; ite++)
    {
        for (search_idx = 0; search_idx < N; search_idx++)
        {
            if (strcmp(input[search_idx],query[ite]) == 0)
            {
                count[ite]++;
            }
        }
    }
    for(ite = 0; ite < Q; ite++)
    {
        printf("%d\n",count[ite]);
    }
    free(count);

    ReleaseMemory(input,N);
    input = NULL;
    ReleaseMemory(query,Q);
    query = NULL;
    return 0;
}
