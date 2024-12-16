#ifndef TESTCASE_H
#define TESTCASE_H

void fill_arr(int arr[5]);
void print_arr(int arr[5]);
void swap(int *x, int *y);
int ascending(int x, int y);
typedef int compare_t (int, int);
int sort_arr(int *arr, compare_t compare);
int confirm(int *arr);

#endif