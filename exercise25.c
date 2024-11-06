#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arr[10];

int randomize()
{

    srand(time(NULL));

    for (int i = 0; i < 10; i++){

    arr[i] = rand()% 100;
    }

    for (int r = 0; r < 10; r++){


    for (int j = 1; j < 9; j++){

    if (arr[r] == arr[j])
    {
      printf("reroll %d %d\n", arr[r], arr[j]);
      arr[r] = rand()% 100;  
      
    }

    }
    

    }
}

int print()
{
    for (int i = 0; i < 10; i++){

    printf("%d ", arr[i]);

    }

}



int main(){

randomize();    
print();
printf("\n");


return 0;
}