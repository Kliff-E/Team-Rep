#include <stdio.h>
#include <stdlib.h>

char ch;
int line = 0;
int i;

int main()
{

    FILE *file = fopen("story.txt", "r");

    if (file == NULL)
    {
        printf("Failed to open story.txt\n");
        exit(1);
    }


    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
        if (ch == '.')
        {
            line++;
            i++;
        }
        i++;
        
    }
    
    printf("\n");
    printf("%d\n", line);
    printf("%d\n", i);

    fclose(file);


    return 0;
}