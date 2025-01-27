/**
 * @file exercise19.h
 * @author Kliff Elvin (elvinkliff@gmail.com)
 * @brief Develop and test a multiple-instance linked list module to strore and restore data of type int according the following requirements.

        The data stored in a linked list shall be unique and sorted.
        The module shall provide the following functions:
        A create function to create an instance of the list.
        An insert function to insert an integer in a list.
        An available function to return the number of data elements stored in a list.
        A search function to check if an integer exists in a list or not
        A remove function to delete an integer from a list
        An edit function to change the data stored in a node of a list.
        Note that the data stored in a list shall always be unique and sorted.
        A destroy function to release memory allocated for a list.
        Test the module using assertions.




 * @version 0.1
 * @date 2025-01-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef EXERCISE19_H
#define EXERCISE19_H

struct list_t;

namespace list

{
    list_t *create(void);
    bool insert(list_t *lst, int value);
    bool search(list_t *lst, int data);
    bool remove(list_t *lst, int elem);
    int available(list_t *lst);
    bool edit(list_t *lst, int odata, int ndata);
    void destroy(list_t *&lst);
}

#endif