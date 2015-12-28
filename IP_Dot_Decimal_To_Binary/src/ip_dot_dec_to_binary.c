#include "ip_addr_to_bin.h"
#define IP_STR_LENGTH 15

int main()

{
    char dot_decimal_ip[IP_STR_LENGTH+1] = {0}, success = 1;
    int compo_array[3]={0};
    unsigned int binary_out[4] = {0};
    int length = 0, iteration, compo_len = 0, compo_sum = 0, compo_index = 0,
        compo_ite = 0, finaloutput = 0;
    int element = 0;

    printf("Enter the IP Address in dotted decimal notation:\r\n");
    fgets(dot_decimal_ip,IP_STR_LENGTH+1,stdin); /* Read the input string from standard input */

    length = strlen (dot_decimal_ip);
    if (length == 0)
    {
        printf("Please enter the valid IP address\r\n");
    }

    if (length < IP_STR_LENGTH)
    {
        dot_decimal_ip[length - 1] = '\0';
        length--;
    }

    for (iteration = 0; iteration <= length; iteration++)
    {
        if ((dot_decimal_ip[iteration] == '.') || (dot_decimal_ip [iteration] == '\0'))
        {
            /* Parsing of a single component is done */
            if (compo_len > 3)
            {
                printf("Invalid IP\n");
                success = 0;
                break;
            }
            compo_len -= 1;
            compo_sum = 0;
            for(compo_ite = compo_len;compo_ite >=0; compo_ite--)
            {
                compo_sum += (compo_array[compo_ite] *(power(10,(compo_len-compo_ite))));
            }

            if (compo_sum > 255)
            {
                printf("Invalid IP\n");
                success = 0;
                break;
            }

            binary_out [compo_index++] = compo_sum;
            memset(compo_array,0,sizeof(compo_array));
            compo_len = 0;
        }
        else
        {
            if ((dot_decimal_ip[iteration] < '0') || (dot_decimal_ip[iteration] > '9'))
            {
                printf("Invalid IP\n");
                success = 0;
                break;
            }
            element = (int)(dot_decimal_ip[iteration] - '0');
            compo_len++;
            if (compo_len > 3)
            {
                printf("Invalid IP\n");
                success = 0;
                break;
            }
            compo_array[compo_len-1] = element;
        }
    }

    if (success == 1)
    {
        finaloutput = (binary_out[0] << 24)+ (binary_out[1] << 16)+ (binary_out[2] << 8) + binary_out[3];
        printf("The binary output for the given IP is:");
        print_binary((unsigned int)finaloutput);
        printf("\n");
    }
    return 0;
}



void print_binary(unsigned int input)
{
    int index;
    for (index = 31; index >= 0; index--)
    {
        if ((input>>31))
        {
            printf("%c",'1');
        }
        else
        {
            printf("%c",'0');
        }
        input = input<<1;
    }
}

int power(int base, int multiplier)
{
    int mul = 1;
    while (multiplier)
    {
        mul *= base;
        multiplier--;
    }
    return mul;
}
