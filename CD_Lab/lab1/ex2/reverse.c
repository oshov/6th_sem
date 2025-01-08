#include <stdio.h>
#include <stdlib.h>

void reverseFileContents(const char *inputFile, const char *outputFile);

int main()
{
    char inputFile[100], outputFile[100];
    FILE *fptr;
    long fileSize;

    // Prompt user for input file name
    printf("Enter the filename to open for reading: ");
    scanf("%s", inputFile);

    // Open the input file in read mode
    fptr = fopen(inputFile, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file %s\n", inputFile);
        exit(0);
    }

    // Determine the file size
    fseek(fptr, 0, SEEK_END); // Move the file pointer to the end
    fileSize = ftell(fptr);   // Get the current position (file size)
    fclose(fptr);

    printf("The size of the file '%s' is: %ld bytes\n", inputFile, fileSize);

    // Prompt user for output file name
    printf("Enter the filename to save reversed contents: ");
    scanf("%s", outputFile);

    // Reverse the contents of the file
    reverseFileContents(inputFile, outputFile);

    printf("Reversed contents have been written to %s\n", outputFile);

    return 0;
}

void reverseFileContents(const char *inputFile, const char *outputFile)
{
    FILE *fptr1, *fptr2;
    long fileSize, i;
    char c;

    // Open the input file in read mode
    fptr1 = fopen(inputFile, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s\n", inputFile);
        exit(0);
    }

    // Open the output file in write mode
    fptr2 = fopen(outputFile, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s\n", outputFile);
        fclose(fptr1);
        exit(0);
    }

    // Determine the file size
    fseek(fptr1, 0, SEEK_END);
    fileSize = ftell(fptr1);

    // Read and write the file contents in reverse order
    for (i = fileSize - 1; i >= 0; i--)
    {
        fseek(fptr1, i, SEEK_SET); // Move the file pointer to the position
        c = fgetc(fptr1);          // Read the character
        fputc(c, fptr2);           // Write the character to the output file
    }

    // Close the files
    fclose(fptr1);
    fclose(fptr2);
}
