#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int arr[10];
int temp[0];
int average = 0;
int spec = 25;
int ind;
int size;

int largest();
int averagenr();
int specifik();

int main()
{

    srand(time(NULL));

    for (int i = 0; i < 10; i++){

    arr[i] = rand()% 100;
    }

    temp[0] = arr[0];

  int largest();
  int averagenr();
  int ind = specifik(ind);

    printf("Largest number: %d\n", temp[0]);

    for (int i = 0; i < 10; i++){

    printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Average: %d\n", average/10);

    printf("%d\n", ind);


    return 0;
}

   int largest(){
    for (int j = 1; j < 10; j++){


    if (temp[0] < arr[j]){

      temp[0] = arr[j];

      
    }
    
    }
    }
   int averagenr(){
    for (int i = 0; i < 10; i++){

     average += arr[i];

    }
    }

   int specifik(int ind){


    for (int size = 0; size < 10; size++){


     if(arr[size] == spec)
     {
        ind = size +1;
        break;
     }
     else {

     ind = -1;

     }

    }
    return(ind);
    }
