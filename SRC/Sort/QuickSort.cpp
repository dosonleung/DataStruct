//
//  QuickSort.cpp
//  DataStruct
//
//  Created by DosonLeung on 2/25/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//

#include "QuickSort.hpp"

static int qslength = 0;

void qsort(ElemType E[], int left, int right, bool isAscending){
    if (left >= right) {
        return;
    }
    int start = left;
    int end = right;
    while(left < right){
        //std::cout << "left:" << left << " " << "right:" << right << std::endl;
        while(left < right){//find the element large/less than the one on the left
            if (isAscending) {
                if (E[right].key < E[left].key) {
                    swap(E, left, right);
                    break;
                }
            }else{
                if (E[right].key > E[left].key) {
                    swap(E, left, right);
                    break;
                }
            }
            right--;
        }
        while (left < right) {
            if (isAscending) {
                if (E[left].key > E[right].key) {
                    swap(E, left, right);
                    break;
                }
            }else{
                if (E[left].key < E[right].key) {
                    swap(E, left, right);
                    break;
                }
            }
            left ++;
        }
    }
    //printElements(E, qslength);
    qsort(E, start, left-1, isAscending);
    qsort(E, right+1, end, isAscending);
}

void QuickSort(ElemType E[], int len, bool isAscending){
    qslength = len;
    qsort(E, 0, len-1, isAscending);
}
