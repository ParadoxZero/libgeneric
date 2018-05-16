/*
 *   MIT License
 *
 *   Copyright (c) 2017-2018 Sidhin S Thomas <sidhin.thomas@gmail.com>
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

 /**
  * @file   list.h
  *
  * @brief Resizable generic container. Linked List, data stored in non continuous locations.
  *
  * List will change it's itemSize dynamically as data is added and removed from it.
  * Random access is not possible, hence @ref stGetListItem will take linear time to access it
  */

#ifndef DATA_STRUCTURE_LIST_H
#define DATA_STRUCTURE_LIST_H

#include <generic.h>
#include <stddef.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>


/**
 * This is the structure that stores the data being given to list.
 * It is best to not touching it in application program.
 */
typedef struct node {
    void *data;
    struct node* next;
} node;

/**
 * The structure representing the List.
 * When a new list is created, a new object of this
 * structure is created
 */
typedef struct gList{
    node *head;
    size_t itemSize;
    int listLength;
} gList;

typedef node** gListIterator;

/**
 * Used to signal the functions that the operation should be done
 * to last item of the list
 */
#define gLIST_END (-1)

/**
 * Function: gListCreate
 * ----------------------
 * Creates and initializes a List
 *
 *  @param itemSize:    The itemSize of data members that are to be stored.
 *
 *  @return:            A pointer to the List that was created.
 *
 *  Example
 *  To create a list to store integers.
 *      gList *list = gCreateList(sizeof(int));
 */
gList* gListCreate(size_t itemSize);

/**
 * Function: gListDelete
 * ----------------------
 * Deletes a previously created list and free associated memories
 *
 *  @param stack:       The list to be deleted.
 *
 *  @return:            Nothing.
 */
void gListDelete(gList *list);

/**
 * Function: gListAddItem
 * ----------------------
 * Removes a previously inserted node
 *
 *  @param list:    The list from which the node is to be removed.
 *  @param value:   The address of the data you want to store. The data from the address will be copied
 *                  instead of storing the pointer. That is, the data pointed by the pointer will be
 *                  duplicated and stored. Any changes to original after storing will not affect the
 *                  stored value.
 *                  The values will be appended to end of the list.
 *
 *
 *  @return:        An integer signally success or failure of operation.
 *                   (0) -> Successful
 *                  (-1) -> Failed
 */
int gListAddItem(gList *list, void *value);

/**
 * Function: gListAddItemAt
 * ----------------------
 * Removes a previously inserted node
 *
 *  @param list:    The list from which the node is to be removed.
 *  @param value:   The address of the data you want to store. The data from the address will be copied
 *                  instead of storing the pointer. That is, the data pointed by the pointer will be
 *                  duplicated and stored. Any changes to original after storing will not affect the
 *                  stored value.
 *                  The values will be appended to end of the list.
 *  @param index    The location value is to be stored at. The values coming after it will be pushed one
 *                  index forward.
 *
 *
 *  @return:        An integer signally success or failure of operation.
 *                   (0) -> Successful
 *                  (-1) -> Failed
 */
int gListAddItemAt(gList *list, void *value, unsigned int index);

/**
 * Function: gListRemoveItem
 * ----------------------
 * Removes a previously inserted node
 *
 *  @param list:    The list from which the node is to be removed.
 *  @param index:   The index of the item to be removed.
 *                  use MACRO -> gLIST_END, to remove last item of the list.
 *
 *  @return:        An integer signally success or failure of operation.
 *                   (0) -> Successful
 *                  (-1) -> Failed
 */
int gListRemoveItem(gList *list, unsigned int index);

/**
 * Function: gListGetItem
 * ----------------------
 * Retrieves the item stored in the given list from given index.
 *
 *  @param list:    The list from which node is to be retrieved.
 *  @param index:   The index of the required node
 *
 *  @return:        A pointer to the Location containing the data.
 *                  The pointer should be casted to the type of the
 *                  data before being used.
 *                  May return 'NULL' in that case of invalid index.
 */
void* gListGetItem(gList *list, unsigned int index);

/**
 * Function: gListGetIterator
 * ----------------------
 * Iterator is an object ( a pointer ) which can be used to loop through the list.
 * It is important to interact with iterator using only the library
 * functions.
 *
 *  @param list:    The list from which node is to be retrieved.
 *
 *  @return:        An iterator.
 *                  May return 'NULL' in that case of empty list.
 */
gListIterator gListGetIterator(gList *list);

/**
 * Function: gListIterate
 * ----------------------
 * This function moves the iterator to the next node.
 *
 *  @param iter:    The iterator to be moved.
 *
 *  @return:        Status code of the operation.
 *                  ( 0) -> Success
 *                  (-1) -> Failed
 *                  Check value of st_errno for details.
 */
int gListIterate(gListIterator iter);

/**
 * Function: gListGetIteratorData
 * ----------------------
 * Returns the value stored in the node the iterator is currently visiting.
 *
 *  @param iterator:    The list from which node is to be retrieved.
 *
 *  @return:            Returns pointer to the location constainig the data.
 *                      It must be casted to the data type which was stored to
 *                      correctly access it.
 *                      May return 'NULL' in that case of invalid iterator, or empty list.
 */
void* gListGetIteratorData(gListIterator iterator);

#endif //DATA_STRUCTURE_LIST_H
