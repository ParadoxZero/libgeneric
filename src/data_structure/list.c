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

#include <data_structure/list.h>


static node * create_node(node* next, void* data, size_t itemSize){
    node * new_node = malloc(sizeof(node));
    if(new_node == NULL){
        st_errno = ST_ENOMEN;
        return NULL;
    }
    new_node->next = next;
    new_node->data = malloc(itemSize);
    if(new_node->data==NULL){
        free(new_node);
        st_errno = ST_ENOMEN;
        return NULL;
    }
    memcpy(new_node->data,data,itemSize);
    return new_node;
}

stList * stCreateList(size_t size){
    stList* new_list = (stList*) malloc(sizeof(stList));
    if (new_list == NULL){
        st_errno = ST_ENOMEN;
        return NULL;
    }
    new_list->head = NULL;
    new_list->itemSize = size;
    new_list->listLength = 0;
    return new_list;
}

//TODO: Implement DeleteList
int stAddListItem(stList *list, void *value){
    if(list->head == NULL){
        node *head = create_node(NULL,value,list->itemSize);
        if(head==NULL){
            return -1;
        }
        list->head = head;
        list->listLength++;
        return 0;
    }
    node *tmp = list->head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = create_node(NULL,value,list->itemSize);
    if(tmp->next == NULL){
        st_errno = ST_ENOMEN;
        return -1;
    }
    list->listLength++;
    return 0;
}

int stAddListItemAt(stList *list, void *value, unsigned int index){
    if(list->listLength < index){
        return -1;
    }
    if(index==0){
        if(list->head == NULL ){ // For Empty list
            list->head = create_node(NULL,value,list->itemSize);
            if(list->head==NULL){
                return -1;
            }
            list->listLength++;
            return 0;
        }
        else{
            node* tmp = list->head;
            list->head = create_node(tmp,value,list->itemSize);
            if(list->head == NULL){
                list->head = tmp;
                return -1;
            }
            list->listLength++;
            return 0;
        }
    }
    if(list->head==NULL){ // List empty and Index not 0. Then Error
        return -1;
    }
    else {
        int i = 0;
        node *ptr = list->head;
        node *old_ptr = ptr;
         do{
            if (i == index) {
                node* new_node = create_node(ptr,value,list->itemSize);
                if (new_node == NULL) {
                    st_errno = ST_ENOMEN;
                    return -1;
                }
                old_ptr->next = new_node;
                list->listLength++;
                break;
            }
            i++;
            old_ptr = ptr;
            ptr = ptr->next;
        }while (ptr!=NULL);
    }
}

int stRemoveItemList(stList *list, unsigned int index){
    if(list->listLength < index+1 && index!=stLIST_END){
        st_errno = ST_EBUFUNDR;
        return -1;
    }
    int i = 1;
    node* tmp = list->head;
    if(index == stLIST_END){    // Asked to remove last item
        if (tmp == NULL)
            return  -1;
        if (tmp->next == NULL){ // only 1 item in list
            free(tmp);
            list->head = NULL;
            list->listLength = 0;
            return 0;
        }
        node* old_ptr = tmp;
        while (tmp->next != NULL) { // Loop to last node.
            old_ptr = tmp;
            i++;
            tmp = tmp->next;
        }
        old_ptr->next = NULL;
        free(tmp);
        list->listLength--;
        return 0;
    }else {                     // Removing Item at index
        if(index == 0){
            node *nxt = tmp->next;
            free(tmp);
            list->head = nxt;
            list->listLength--;
            return 0;
        }
        while (tmp->next != NULL) {
            if (i == index) {
                node *next = (tmp->next)->next;
                free(tmp->next);
                tmp->next = next;
                list->listLength--;
                return 0;
            }
            i++;
            tmp = tmp->next;
        }
    }
    st_errno = ST_EINVAL;
    return -1;
}

void* stGetListItem(stList *list, unsigned int index){
    if(list->listLength-1 < index){
        st_errno = ST_EBUFUNDR;
        return NULL;
    }
    node* tmp = list->head;
    int i = 0;
    while(tmp!=NULL){
        if(i==index){
            return tmp->data;
        }
        i++;
        tmp = tmp->next;
    }

    st_errno=ST_EINVAL;
    return NULL;
}

stListIterator stGetListIterator(stList *list){
    if(list == NULL){
        st_errno = ST_ENOITM;
        return NULL;
    }
    node **iter = malloc(sizeof(node *));
    *iter = list->head;
    return iter;
}

int stListIteratorNext(stListIterator iter){
    if((*iter) == NULL){
        st_errno = ST_EITMEND;
        return 1;
    }
    *iter = (*iter)->next;
    return 0;
}

void* stGetListIteratorData(stListIterator iter){
    if(*iter == NULL){
        st_errno = ST_EITMEND;
        return NULL;
    }
    return (*iter)->data;
}