#include <stdio.h>
#include <string.h>
#define INT_SIZE sizeof(int) * 8
int myStrStr(char *haystack, char *needle, char *buffer){
    int i = 0, j = 0;
    int substring = 0;

    memset(&buffer[0], 0, 255);
    while (haystack[i] != '\0' && needle[j] != NULL)
    //while ( '\0' != haystack[i] && '\0' != needle[j])
    {
        if (haystack[i] != needle[j])
        {
            ++i;
            j=0;
        }
        else
        {
            buffer[j] = needle[j];
            ++i;
            ++j;
        }
    }
    printf("Substring is : %s", buffer);
    //if (  '\0' == needle[j])
    if (needle[j]==NULL)
    {
        substring = 1;
    }
    return substring;
    //printf("Substring is : %s", &buffer);
}

void binaryArray(int n, int array[], int size){
    int i,j;
    for (i=0; i<size; ++i){
        array[size-i-1] = (n >> i) & 1;
    }
}

void binaryPrinter(int array[], int size)
{
    printf("Converted value :");
    for (int i=0;i<size; ++i)
    {
        printf("%d", array[i]);
    }
}

unsigned int countOnes(int num){
    int ones = 0;
    for(int i=0; i<INT_SIZE; i++)
    {
        if (num & 1)
            ones++;
        num >>= 1;
    }
    return ones;
}
