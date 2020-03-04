#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *raw_file = argv[1];
    FILE *file_ptr = fopen(raw_file, "r");
    if (file_ptr == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", raw_file);
        return 2;
    }

    unsigned char *buffer = malloc(512);
    int jpg_number = 0;
    FILE *img;

    while (fread(buffer, 512, 1, file_ptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg_number > 0)
            {
                fclose(img);
            }
            
            char filename[10];
            sprintf(filename, "%03i.jpg", jpg_number);

            img = fopen(filename, "w");

            if (img == NULL)
            {
                fclose(file_ptr);
                free(buffer);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 3;
            }

            jpg_number++;
        }

        fwrite(buffer, 512, 1, img);
    }

    fclose(file_ptr);
    fclose(img);
    free(buffer);
    return 0;
}