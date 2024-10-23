#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int name;
int counter = 1;
int onespace = 1;
int first = 1;
int sec = 1;

int main(){

printf("Write your full name\n");



while ((name = getchar())!= '\n' ){
if (!isspace(name) && !isdigit(name) && isalpha(name))
{
  if (first == 1){
    first = 0;
    name = toupper(name);
    putchar(name);
    
  }
  else if (counter == 0 && sec == 1){
  sec = 0;
  name = toupper(name);
  putchar(name);
  }
  else{
  name = tolower(name);
  putchar(name);
  }
   
}
 else if (isspace(name)) {

       if(counter == 1){ 
        name == ' ';
        putchar(name);
        counter = 0;
        onespace = 0;
       }
       
    }
}
 
printf("\n");
return 0;
}