#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stringmodul.h"

static length(char *name)
{
    int i = 0;

    if(name == NULL)
    {
        i = 0;
    }
    while (name[i] != '\0')
    {
        i++;
    }
    
    return i;

}

int compare(char *name1, char *name2)
{
    int i = 0;
    int korrekt = 1;

    while (name1[i] != '\0' || name2[i] != '\0')
    {
        i++;
        if (name1[i] != name2[i])
        {
           korrekt = 0; 
        }
    }

    return korrekt;
    
}

