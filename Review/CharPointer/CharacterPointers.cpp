#include <stdio.h>
#include <stdlib.h>

void Test1();
void Input();

int main()
{
    // Test1();
    Input();
}

void Test1() 
{
    char str[11] = "HelloWorld";
    char *ptr = str;

    while (*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }
    
}

void Input()
{
    int n, i;
    char *ptr;

    printf("Enter number of characters to store: ");
    scanf("%d", &n);

    ptr = (char*)malloc(n*sizeof(char));

    for(i=0; i < n; i++)
    {
        printf("Enter ptr[%d]: ", i);
        /* notice the space preceding %c is
          necessary to read all whitespace in the input buffer
        */
        scanf(" %c", ptr+i); 
    }

    printf("\nPrinting elements of 1-D array: \n\n");

    for(i = 0; i < n; i++)
    {
        printf("%c ", ptr[i]);
    }

}

/*
    Invalid:
    char *ptr = "Hello"
    ptr[0] = 'Y' or *ptr = 'Y'
    gets(ptr)
    scanf("%s", ptr)
    strcpy(ptr, "source")
    strcat(ptr, "Sencond string")
*/