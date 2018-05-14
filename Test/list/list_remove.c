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

#include <stdio.h>
#include <data_structure/list.h>

int main()
{
    stList* list = stCreateList(sizeof(int));
    for (int i = 0; i <10 ; ++i) {
        if(stAddListItem(list, &i)==-1){
            return st_errno;
        }
        for (int j = 0; j <= i ; ++j) {
            printf("%d ", *(int*) stGetListItem(list, j));
        }
        printf("\n");
    }
    for (int i = 9; i >=0 ; --i) {

        if(stRemoveItemList(list, i)==-1){
            return st_errno;
        }
        stListIterator iter = stGetListIterator(list);
        while(stGetListIteratorData(iter)!=NULL){
            printf("%d ", *(int*) stGetListIteratorData(iter));
            fflush(stdout);
            stListIteratorNext(iter);
        }
        printf("\n");
    }
    stListIterator iter = stGetListIterator(list);
    while(*iter!=NULL){
        printf("%d ", *(int*) stGetListIteratorData(iter));
    }
    return 0;
}