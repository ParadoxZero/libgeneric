/*
 *   MIT License
 *
 *   Copyright (c) 2017-2018 Sidhin S Thomas
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

 /*
  * @file   list.h
  *
  * @brief Resizable generic container. Linked List, data stored in non continuous locations.
  *
  * List will change it's itemSize dynamically as data is added and removed from it.
  * Random access is not possible, hence @ref stGetListItem will take linear time to access it
  */

#ifndef DATA_STRUCTURE_LIST_H
#define DATA_STRUCTURE_LIST_H

#include <data_structure/data_structure.h>
#include <stddef.h>
#include <stdlib.h>

#include <string.h>


/*
 * This is the structure that stores the data being given to list.
 * It is best to not touching it in application program.
 */
typedef struct node {
    void *data;
    struct node* next;
} node;

/*
 * The structure representing the List.
 * When a new list is created, a new object of this
 * structure is created
 */
typedef struct List{
    node *head;
    size_t itemSize;
    int listLength;
} stList;

typedef node** stListIterator;

/*
 * Used to signal the functions that the operation should be done
 * to last item of the list
 */
#define stLIST_END (-1)

/*
 * Function: stCreateList
 * ----------------------
 * Creates and initializes a List
 *
 *  @param itemSize:    The itemSize of data members that are to be stored.
 *
 *  @return:            A pointer to the List that was created.
 *
 *  Example
 *  To create a list to store integers.
 *      stList *list = stCreateList(sizeof(int));
 */
stList* stCreateList(size_t itemSize);

/*
 * Function: stDeleteList
 * ----------------------
 * Deletes a previously created list and free associated memories
 *
 *  @param stack:       The list to be deleted.
 *
 *  @return:            A pointer to the stack that was created.
 *                      May return 'NULL' in case of failure to allocate necessary memory.
 */
int stDeleteList(stList *list);

/*
 * Function: stAddItemList
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
int stAddListItem(stList *list, void *value);

/*
 * Function: stAddItemListAt
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
int stAddListItemAt(stList *list, void *value, unsigned int index);

/*
 * Function: stRemoveItemList
 * ----------------------
 * Removes a previously inserted node
 *
 *  @param list:    The list from which the node is to be removed.
 *  @param index:   The index of the item to be removed.
 *                  use MACRO -> stLIST_END, to remove last item of the list.
 *
 *  @return:        An integer signally success or failure of operation.
 *                   (0) -> Successful
 *                  (-1) -> Failed
 */
int stRemoveItemList(stList *list, unsigned int index);

/*
 * Function: stGetListItem
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
void* stGetListItem(stList *list, unsigned int index);

/*
 * Function: stListIterator
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
stListIterator stGetListIterator(stList *list);

/*
 * Function: stListIteratorNext
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
int stListIteratorNext(stListIterator iter);

/*
 * Function: stGetListIteratorData
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
void* stGetListIteratorData(stListIterator iterator);

#endif //DATA_STRUCTURE_LIST_H
