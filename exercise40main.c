#include <stdio.h>
#include "exercise40.h"



int main()
{

    
    list_t list;
    init_list(&list);

    for(int i = 5; i >= 1; i--)
    {
    add_sorted(&list, i);
    }
    change_data(&list,3,6);

    remove_node(&list, 1);

    search_data(&list, 6);

    int elements = number_of_elements(&list);

    print_list(&list, elements);

    delete_list(&list);

    //print_list(&list, elements);



    return 0;
}