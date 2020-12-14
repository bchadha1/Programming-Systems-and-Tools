#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int Array1[4];
    int *ptr, i;

    ptr = (int*) malloc(4 * sizeof(int));

    printf("Enter the elements:\t");
    for(i=0; i<4; i++)
    {
        scanf("%d",(ptr+i));
    }

    memset(ptr,1,4*sizeof(Array1[4]));

    printf("Elements of array are\n");
    for(i=0; i<4; i++)
    {
        printf("Address of the element: %d\n",(ptr+i));
        printf("Values of the element: %d\n", *(ptr+i));
    }

    int *p2, num2=5;
    int Array2[5];
    p2 = (int*) malloc(5 * sizeof(int));

    printf("Enter the 5 elements of new array:\n");
    for (i=0; i<5; ++i)
    {
        scanf("%d\n", &Array2[i]);
    }
    free(Array2);

    printf("Array after freeing memory: ");
    for (i=0; i<num2; i++)
    {
        printf("%d\n",Array2[i]);
    }

    return 0;
}
