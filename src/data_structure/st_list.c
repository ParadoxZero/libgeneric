/*
 *   MIT License
 *
 *   Copyright (c) 2017 Sidhin S Thomas
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

static node * create_node(){
    node * new_node = malloc(sizeof(node));
    if(new_node == NULL){
        st_errno = 11;
        return NULL;
    }
    new_node->next = NULL;
    new_node->data = NULL;
    return new_node;
}

List * st_list_create(size_t size){
    List* new_list = (List*) malloc(sizeof(List));
    if (new_list == NULL){
        st_errno = ST_ENOMEN;
        return NULL;
    }
    new_list->head = NULL;
    new_list->size = size;
    new_list->list_size = 0;
    return new_list;
}

int st_list_add(List* list, void *value){
    if(list->head == NULL){
        node *head = create_node();
        if(head == NULL){
            return -1;
        }
        head->data = malloc(list->size);
        if(head->data == NULL){
            st_errno = ST_ENOMEN;
            return -1;
        }
        memcpy(head->data,value,list->size);
        list->head = head;
        list->list_size++;
        return 0;
    }
    node *tmp = list->head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = create_node();
    if (tmp->next == NULL){
        st_errno = 11;
        return -1;
    }
    tmp = tmp->next;
    tmp->data = malloc(list->size);
    if(tmp->data == NULL){
        st_errno = ST_ENOMEN;
        return -1;
    }
    memcpy(tmp->data, value, list->size);
    list->list_size++;
    return 0;
}

int st_list_remove(List* list, unsigned int index){
    if(list->list_size < index+1){
        st_errno = ST_EBUFUNDR;
        return -1;
    }
    int i = 1;
    node* tmp = list->head;
    if(index == 0){
        node *nxt = tmp->next;
        free(tmp);
        list->head = nxt;
        list->size--;
        return 0;
    }
    while(tmp->next != NULL){
        if(i == index){ //found location
            node* next = (tmp->next)->next;
            free(tmp->next);
            tmp->next = next;
            list->size--;
            return 0;
        }
    }
    st_errno = ST_EINVAL;
    return -1;
}

void* st_list_get(List* list, unsigned int index){
    if(list->list_size-1 < index){
        st_errno = ST_EIDXBND;
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

st_list_iter st_list_get_iter(List* list){
    if(list == NULL){
        st_errno = ST_ENOCTNR;
        return NULL;
    }
    return &list->head;
}

int st_list_next(st_list_iter iter){
    if(iter == NULL){
        st_errno = ST_ECTNREND;
        return 1;
    }
    *iter = (*iter)->next;
    return 0;
}

void* st_list_iter_get(st_list_iter iter){
    if(iter == NULL){
        st_errno = ST_ECTNREND;
        return NULL;
    }
    return (*iter)->data;
}