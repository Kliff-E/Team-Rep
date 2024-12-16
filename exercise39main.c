#include "exercise39.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>


void test_gcd() {
    assert(gcd(8, 12) == 4);  // Test case 1
    assert(gcd(7, 13) == 1);  // Test case 2
    assert(gcd(20, 30) == 10); // Test case 3
    assert(gcd(101, 10) == 1); // Test case 4
    printf("All GCD tests passed!\n");
}

void test_lcm() {
    assert(lcm(4, 6) == 12);  // Test case 1
    assert(lcm(7, 5) == 35);  // Test case 2
    assert(lcm(15, 20) == 60); // Test case 3
    assert(lcm(101, 10) == 1010); // Test case 4
    printf("All LCM tests passed!\n");
}

void test_sort_string() {
    char str1[] = "jsaNSHosAlPWnSJq";
    sort(str1);
    assert(strcmp(str1, "AaHJjlNnoPqSSssW") == 0); // Test case 1
    
    char str2[] = "hello";
    sort(str2);
    assert(strcmp(str2, "ehllo") == 0); // Test case 2
    
    char str3[] = "apple";
    sort(str3);
    assert(strcmp(str3, "aelpp") == 0); // Test case 3
    
    char str4[] = "Zebra";
    sort(str4);
    assert(strcmp(str4, "aberZ") == 0); // Test case 4
    
    printf("All string sort tests passed!\n");
}

int main()
{
    char arr[17] ={'j','s','a','N','S','H','o','s','A','l','P','W','n','S','J','q'};

    test_gcd();
    test_lcm();
    test_sort_string();

    int divisior = gcd(8,12);
    printf("Greatest common divisor is %d\n", divisior);
    int multiple = lcm(4,6);
    printf("Least common multiple is %d\n", multiple);

    sort(arr);


    return 0;

}