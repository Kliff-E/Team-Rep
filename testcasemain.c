#include "testcase.h"
#include <stdio.h>
#include <assert.h>

int main()
{

    int arr[5];
    int x = 1;
    int y = 0;
    int temp;

    

    fill_arr(arr);
    print_arr(arr);
    printf("\n");
    sort_arr(arr,ascending);
    assert(1 == confirm(arr));
    confirm(arr);
    print_arr(arr);
    printf("\n");

    return 0;
}