#include <stdio.h>
#include <stdlib.h>
#include<cs50.h>

#define BUFFER_SIZE 512
int main(int argc, char *argv[])
{
  FILE* input = fopen("card.raw","r");

  if(argc!=2 )
  {
    return 1;
  }
  if (input == NULL)
  {
    printf("can't open this file");
    return 1 ;
  }

  unsigned char buffer[BUFFER_SIZE];

  int jpg_found = 0 ; //false
  int file_counter = 0 ;

  FILE *picture = NULL;
  while (fread(buffer,BUFFER_SIZE,1,input) == 1)
  {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jpg_found == 1)
            {
                fclose(picture);
            }
            else
            {
                jpg_found = 1;
            }
            char files[8];
            sprintf(files, "%03d.jpg", file_counter);
            picture = fopen(files,"a");
            file_counter ++ ;
        }
        if (jpg_found == 1)
        {
            fwrite(&buffer,BUFFER_SIZE,1,picture);
        }

}
fclose(input);
fclose(picture);
return 0 ;
}