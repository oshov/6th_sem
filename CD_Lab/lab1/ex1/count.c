#include <stdio.h>
#include <stdlib.h> // For exit()

int main()
{
    FILE *fptr;
    char filename[100], c;
    int lineCount = 0, charCount = 0;

    // Prompt user for the filename
    printf("Enter the filename to open: ");
    scanf("%s", filename);

    // Open the file for reading
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    // Read file character by character
    while ((c = fgetc(fptr)) != EOF)
    {
        charCount++; // Increment character count
        if (c == '\n')
        {
            lineCount++; // Increment line count on newline
        }
    }

    // Close the file
    fclose(fptr);

    // Display the results
    printf("The file %s contains:\n", filename);
    printf("%d lines\n", lineCount);
    printf("%d characters\n", charCount);

    return 0;
}
