/***********************************************************************************
Leonardo loves puzzles involving strings, but he's just found a problem that has him
stumped! Help him solve the following challenge:

Given a binary string, SS, composed of only 00's and 11's, find and print the total
number of substrings of SS which do not contain a 0000 or 1111.

Input Format:
------------
The first line contains an integer, T (the number of test cases).
The T subsequent lines of test cases each contain a string, S, composed
only of 0's and 1's.

Constraints:
-----------

1<=T<=100
1<=|S|<=(10^5)
Output Format

For each test case, print the total number of substrings of S having no consecutive
zeroes or ones (i.e.: not containing 00 or 11).

Sample Input:
-------------
7
1010
100
0000
11111
10101
10100
10010
Sample Output:
-------------
10
4
4
5
15
11
9
Explanation:
------------
Test Case 0: S0=1010
Our set of substrings ={{1},{0},{1},{0},{10},{01},{10},{101},{010},{1010}}
There are 10 possible substrings, none of which have consecutive 0's or 1's. Thus,
we print 10 on a new line.

Test Case 1: S1=100
Our set of substrings ={{1},{0},{0},{10},{00},{100}}
There are 6 possible substrings, but 2 of them ({00} and {100}) have consecutive zeroes.
Thus, we print the result of 6-2, which is 4, on a new line.
***************************************************************************************/
/**************************************************************************************
SAMPLE INPUT:
------------
Value   0   0   1   0   1   1   0   0
Index   0   1   2   3   4   5   6   7


ALGORITHM:
---------
1)  Start from the left end.
2)  Take 2, 3, 4, .. Till total number of elements at a time.
    a.  Search for substring 00 or 11.
    b.  If the substring found in a set of taking x elements at a time, then for all the
        sets which takes x+1 elements at a time will not satisfy the given conditions.
        i.  In our example first start with index 0(step number = 0). Take 2 elements at
            a time. It has the substring matching 00. So all other sets (i.e sets with
            taking x elements at a time where 2 < x <= (total elements . step number)),
            the substring will present and hence the count should not be incremented.
            Now, in step number 1, we will start from the index 1 and can form sets with
            taking 2, 3, 4 . (totalelements - 1) elements at a time. Start with 2 elements
            at a time; the set is {0,1}. No substring match found.
            Now, take 3 elements starting from index number 1; set is{0,1,0}. No substring
            match found.
            Now, take 4 elements at a time starting from index 1; the set is {0,1,0,1}. No
            substring match is found. Now, take 5 elements at a time, starting from the
            index 1; set is {0,1,0,1,1}. Here we are having a substring {1,1}. So, all the
            other sets taking 5 & more than that much elements from the index 1 will not
            satisfy the condition. So, we can break the loop and go to the next iteration
            (step number = 2) starting from the index 3 and taking 2, 3, ...(total element -2)

**************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define T 100
#define BINARY_STR_LENGTH 100000
#define FILENAMELEN 8
#define SUCCESS 0
#define FAILURE 1
void Close_File_Descriptor (FILE **input_fd,int count);
int find_leonardo_substr (FILE *fd);

int main()
{
    FILE *input_file[T] = {NULL};
    int testcases = 0, index = 0, output = 0;
    char ch, filename[FILENAMELEN];
    unsigned int length;

    scanf("%d",&testcases);
    if ((testcases<1) || (testcases > T))
    {
        return FAILURE;
    }
    /* To clear input buffer */
    while((ch = getchar())!=EOF && (ch != '\n'));

    for (index = 0; index < testcases; index++)
    {
        memset(filename,0,FILENAMELEN);
        sprintf(filename,"temp%d",index);
        if ((input_file[index] = fopen(filename,"w+")) == NULL)
        {
            perror(filename);
            Close_File_Descriptor (input_file,index);
            return FAILURE;
        }
        length = 0;
        while((ch= getchar()) != '\n')
        {
            if(length <= BINARY_STR_LENGTH)
            {
                fputc(ch,input_file[index]);
                length++;
            }
        }
    }

    /* Core Logic Computation */
    for (index = 0; index < testcases; index++)
    {
        output = find_leonardo_substr (input_file[index]);
        printf("%d\n",output);
    }
    Close_File_Descriptor (input_file,testcases);
    return SUCCESS;
}
int find_leonardo_substr (FILE *fd)
{
    int count = 0, stepnumber = 0, totalelements = 0,
        index = 0, ite = 0, substring_match = 0, origination;
    char ch, ch_temp;

    if (fd == NULL)
    {
        return count;
    }

    if (fseek (fd,0,SEEK_END) == 0)
    {
        totalelements = ftell (fd);
        fseek (fd,0,SEEK_SET);
    }
    count += totalelements;

    for (stepnumber = 0; stepnumber < totalelements; stepnumber++)
    {
        /* This loop is to implement the substring matching from left
         * end to right end step by step */
        fseek(fd,stepnumber,SEEK_SET);
        origination = ftell (fd);
        for (index = 2; index <= (totalelements-stepnumber);index++)
        {
            /* This loop is to implement the functionality of taking 2, 3,
             * ..., (totalelements-stepnumber) elements at a time */
            substring_match = 0;
            fseek (fd,origination,SEEK_SET);
            ch = fgetc (fd);
            ch_temp = ch;
            for (ite = 1; ite < index; ite++)
            {
                /* This loop is to detect substring matches */
                ch = fgetc (fd);
                if (ch_temp != ch)
                {
                    ch_temp = ch;
                }
                else
                {
                    substring_match = 1;
                    break;
                }
            }
            if (substring_match == 1)
            {
                break;
            }
            else
            {
                count++;
            }
        }
    }
    return count;
}

void Close_File_Descriptor (FILE **input_fd,int count)
{
    int index;

    for (index = 0; index < count; index++)
    {
        if (input_fd[index] != NULL)
        {
            fclose(input_fd[index]);
        }
    }
}
