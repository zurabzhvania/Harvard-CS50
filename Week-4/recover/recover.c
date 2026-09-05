#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    unsigned char buffer[512];
    int jpegCount = 0;
    FILE *output = NULL;
    while (fread(buffer, 512, 1, input) == 1)
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL)
            {
                fclose(output);
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", jpegCount);
            output = fopen(filename, "w");
            if (output == NULL)
            {
                printf("Could not create file.\n");
                fclose(input);
                return 1;
            }
            jpegCount++;
        }
        if (output != NULL)
        {
            fwrite(buffer, 512, 1, output);
        }
    }
    if (output != NULL)
    {
        fclose(output);
    }
    fclose(input);
    return 0;
}
