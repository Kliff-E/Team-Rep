#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ch[1024];
int line = 0;
char word[3];
int j = 1;
int c = 0;

int main()
{

    fgets(word, sizeof(word),stdin);
    word[strcspn(word, "\n")] = 0;

    FILE *file = fopen("story.txt", "r");

    if (file == NULL)
    {
        printf("Failed to open story.txt\n");
        exit(1);
    }


    while ((ch[c] = fgetc(file)) != EOF) {

        if (ch[c] == '.')
        {
            line++;
            c++;
        }
        c++;
        
        if (ch[c] == word[3])
        {



            for (int i = strlen(word); i == strlen(word); i--)
            {
               if (ch[c] == word[i])
               {
                j++;

                if (j == strlen(word))
                {
                    printf("%d\n", line);
                }

               }
               
            }
            
        }      
        
    }
    
    printf("\n");
    printf("%d\n", line);

    fclose(file);


    return 0;
}