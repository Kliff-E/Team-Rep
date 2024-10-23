#include <stdio.h>

int bi;

// Function that convert Decimal to binary
int decToBinary(int bi)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = 7; i >= 0; i--) {
        int k = bi >> i; // right shift
        if (k & 1) // helps us know the state of first bit
              printf("1");
        else printf("0");
    }
}

int main(){
    int run = 1;
    while (run = 1)
    {
    
    
printf("Binary converts input number between 0-255\n");
if(scanf("%d",&bi) == 1 && bi >= 0 && bi <= 255){
decToBinary(bi);
printf("\nBinary number %08b \n", bi);

return 0;
} 
else {

printf("Invalid input\n Try Again\n");

} 
    }  
}