#include <stdio.h>
#include <stdlib.h>

void mergeFiles(const char *file1, const char *file2, const char *resultFile);

int main()
{
    char file1[100], file2[100], resultFile[100];

    // Prompt user for input filenames
    printf("Enter the first filename: ");
    scanf("%s", file1);

    printf("Enter the second filename: ");
    scanf("%s", file2);

    // Prompt user for output filename
    printf("Enter the resultant filename: ");
    scanf("%s", resultFile);

    // Merge the files
    mergeFiles(file1, file2, resultFile);

    printf("Lines have been merged alternately into %s\n", resultFile);

    return 0;
}

void mergeFiles(const char *file1, const char *file2, const char *resultFile)
{
    FILE *fptr1, *fptr2, *fptrResult;
    char line[256];

    // Open the first file for reading
    fptr1 = fopen(file1, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s\n", file1);
        exit(0);
    }

    // Open the second file for reading
    fptr2 = fopen(file2, "r");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s\n", file2);
        fclose(fptr1);
        exit(0);
    }

    // Open the resultant file for writing
    fptrResult = fopen(resultFile, "w");
    if (fptrResult == NULL)
    {
        printf("Cannot open file %s\n", resultFile);
        fclose(fptr1);
        fclose(fptr2);
        exit(0);
    }

    // Merge lines alternately
    while (!feof(fptr1) || !feof(fptr2))
    {
        // Read and write a line from the first file
        if (fgets(line, sizeof(line), fptr1) != NULL)
        {
            fputs(line, fptrResult);
        }

        // Read and write a line from the second file
        if (fgets(line, sizeof(line), fptr2) != NULL)
        {
            fputs(line, fptrResult);
        }
    }

    // Close all files
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptrResult);
}
