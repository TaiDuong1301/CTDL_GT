/**
 * @file File.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * When working with files, you need to declare a pointer of type file. 
 * This declaration is needed for communication between the file and the program.
 */

void inputFile(const char *filename, int num);
void outputFile(const char *filename, int *num);

int main()
{
    int numIN, numOUT;
    char *filename = "program.txt";

    printf("Enter num: ");
    scanf("%d", &numIN);

    inputFile(filename, numIN);

    outputFile(filename, &numOUT);

    printf("Value of n = %d", numOUT);
    return 0;
}
/**
 * @brief Write to a text file
 * 
 * @param filename 
 */
void inputFile(const char *filename, int num) {
    // For reading and writing to a text file, we use the functions fprintf() and fscanf().
    FILE *fptr;

    fptr = fopen(filename,"w");

    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }

    fprintf(fptr,"%d",num);
    fclose(fptr);
}
/**
 * @brief Read from a text file
 * 
 * @param filename 
 */
void outputFile(const char *filename, int *num) {
    int temp;
    FILE *fptr = fopen(filename,"r");

    if (fptr == NULL){
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    fscanf(fptr,"%d", &temp);

    *num = temp;
    fclose(fptr); 
}