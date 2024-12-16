#include <stdio.h>
#include <string.h>

static char *split_string(const char *str, const char *delim);

int main ()
{
  const char str[] ="- This, a sample string.";
  const char *delim = (" ,.-");
  printf ("Splitting string \"%s\" into tokens:\n",str);
  char *token = split_string(str, delim);


  while (token != NULL)
  {
    printf ("%s\n",token);
    token = split_string (NULL, delim);
  }

  return 0;
}

static char *split_string(const char *str, const char *delim)
{
    static char *last;
    char *start;

    if (str != NULL) {
        last = strdup(str);
    }

    if (last == NULL)
    {
      start = NULL;
    }

    else{ last += strspn(last, delim);
    
    if (*last == '\0') {
        start = NULL; // No more tokens
    }

    else{

    start = last;

    last = strpbrk(start, delim);
    if (last == NULL) {
        last = NULL; // No more tokens, end of string
    } else {
        *last = '\0'; // Null-terminate the token
        last++; // Move past the delimiter for the next call
    }
    }
    }
    return start;
}



